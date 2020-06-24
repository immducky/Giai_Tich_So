#include <conio.h>
#include <stdio.h>
#include <math.h>

double f(double x)
{
    return  log(x) -1;
}
double  df(double x)
{
    double h = 1e-7;
    return ((f(x + h) - f(x - h))/(2 * h));
}
double  ddf(double x)
{
    float h = 1e-3;
    return ((df(x + h) - df(x - h))/(2 * h));
}

//Gia tri nho  nhat  cua mot ham
double  min(double f(double x), double a, double b)
{
    double  alpha , x0 = a, e = 1e-7;
    double  mini = a;

    alpha = (b - a)/10000;

    do
    {
        int  loop = 10000;
        x0 = x0 + e;
        if(df(x0) > 0)
            do {
                x0 = x0 + alpha * df(x0);
                loop--;
                if (loop < 0)
                    break;
            }
            while(fabs(df(x0)) > e);
            else{
                do{
                    x0 = x0 - alpha*df(x0);
                    loop --;
                    if(loop < 0)
                        break;
                }
                while(fabs(df(x0)) > e);
            }
            if (x0 > b) break;
            else{
                if (f(x0) < f(mini))
                    mini = x0;
            }
    }
    while (1);

    if (f(mini) < f(b))
        return f(mini);
    else  return f(b);
}

//Gia tri lon  nhat  cua mot ham
double  max(double f(double x), double a, double b){
    double  nef(double x){
        return  -1 * f(x);
    }
    return  -1 * min(nef,a,b);
}

//Dau cua mot so
int  sign(double x){
    if (x >= 0)  return  1;
    else  return  -1;
}

//Kiem  tra ham  khong  doi dau  tren[a,b]
int  checkf(double f(double x), double a, double b){
    double m1, m2;
    m1 = max(f,a,b);
    m2 = min(f,a,b);
    if (sign(m1) == sign(m2))
        return  1;
    else
        return  -1;
}

// Phuong  phap  Newton
double  sol(double a, double b, double e){
    double s, x0 , m1, m2, c;
    int i = 1;
    if (sign(f(a)) == sign(ddf(a)))
        x0 = a;
    else x0 = b;
    double  f1(double x){
        return  fabs(df(x));
    }
    double  f2(double x){
        return  fabs(ddf(x));
    }

    m1 = min(f1,a,b);
    m2 = max(f2,a,b);
    c = sqrt (2.0 * m1 * e/m2);

    //m1= min(f1,a,b);          Su dung  cong  thuc  sai so muc  tieu
    // c=m1e;
    do{
        s = x0;
        x0 = x0 - f(x0)/df(x0);
        printf("\nLan  thu %d:\n", i);
        printf("x = %8.15lf \n", x0);
        printf("e = %8.15lf \n", fabs(x0 -s));
        printf("fx = %8.15lf \n", f(x0));
        i++;
    }
    while(fabs(x0-s)  >= c); //|f(x0)|≥c    Su dung  cong  thuc  sai so muc  tieu

    if(fabs(x0-s) < c){   //|f(x0)|< c   Su dung  cong  thuc  sai so muc  tieu
        printf("\nVay so lan lap: %d \n", i-1);
        printf("x = %8.15lf", x0);
    }
    return(x0);
}

int  main(){
    printf("\n Tim  nghiem  ham so bang  phuong  phap  Newton  Raphson");
    double a, b, e;

    //Kiem  tra  khoang  co hai dau  mut  trai  dau
    do{
        printf("\n Nhap a: ");
        scanf("%lf", &a);
        printf("\n Nhap b: ");
        scanf("%lf", &b);

        if (sign(f(a)) == sign(f(b))) {
            printf("Day  khong  phai  khoang  cach ly  nghiem! Hay  nhap  lai!");
        }
        if (a == b) {
            printf("a phai  khac b! Hay  nhap  lai!");
        }
    }
    while ((sign(f(a)) == sign(f(b))) || (a == b));

    if (a > b){
        a=a+b;
        b=a-b;
        a=a-b;
    }

    printf("\n Nhap  gia  tri sai so: ");
    scanf("%lf", &e);
    //Kiem  traf′,f′′khong  doi  dau
    int c1, c2;
    c1 = checkf(df ,a,b);
    c2 = checkf(ddf ,a,b);

    if ((c1 == 1) && (c2 == 1)){
        sol(a,b,e);
    }
    else{
        if (c1 != 1){
            printf("Dao ham cap  mot doi dau  tren  doan  nay. Thuat  toan  khong  thuc  hienduoc");
        }
        if (c2 != 1){
            printf("Dao ham cap  hai doi dau  tren  doan  nay. Thuat  toan  khong  thuc  hienduoc");
        }
    }
}