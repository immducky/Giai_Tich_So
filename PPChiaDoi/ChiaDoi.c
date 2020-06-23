#include <stdlib.h>
#include<stdio.h>
#include<math.h>

// Khai báo hàm:
double ham1(double x);
double ham2(double x);
double ham3(double x);
double ham4(double x);
double nghiem(double (*f)(double x), double a, double b, double eps);


int main(void) {
    double epsilon, a, b;

    printf("Nhap sai so muc tieu: ");
    scanf("%lf", &epsilon);

    printf("Nhap khoang phan ly (a,b): \n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);

    //printf("%lf\n\n", nghiem(ham1, a, b,epsilon));   //a=0,b=10
    //printf("%lf\n\n", nghiem(ham2, a, b, epsilon));  //a=1,b=2
    //printf("%lf\n\n", nghiem(ham3, a, b, epsilon));  //a=1.2,b=2
    printf("%lf\n\n", nghiem(ham4, a, b, epsilon));  //a=0,b=1,defaul a=2,b=3

    return 0;
}


// Định nghĩa hàm:
double ham1(double x)
{
    return ((x * x) - 2);
}

double ham2(double x)
{
    return (pow(2, x) + x - 4);
}

double ham3(double x)
{
    return(log(x * x * x + 3 * x - 5) + 1);
}

double ham4(double x)
{
    return(sin(x) * sin(x) - cos(x) * cos(x) * cos(x));
}

// Hàm tìm nghiệm của phương trình
// INPUT: hàm số f(x), (a, b) và sai số ε mục tiêu.
// OUTPUT: nghiệm x của phương trình f(x) = 0 với sai số < ε.
double nghiem(double (*f)(double x), double a, double b, double eps)
{
    if (f(a) * f(b) > 0)    // kiểm tra điều kiện thực hiện
    {                       // phương pháp chia đôi.
        printf("Ham khong doi dau tren (a,b)\n");
        return -1;
    }
    else
    {
        printf("\n");
        printf("    a             b             x         denta(x)       f(x)\n");
        // Sử dụng phương pháp đánh giá sai số hậu nghiệm
        while (b - a > eps)
        {
            if (f((a + b) / 2.0) * f(a) < 0)
            {
                b = (a + b) / 2.0;
                printf("%-14lf", a);
                printf("%-14lf", b);
                printf("%-14lf", b);
                printf("%-14lf", b - a);
                printf("%-14lf\n", f(b));
            }
            else
            {
                a = (a + b) / 2.0;
                printf("%-14lf", a);
                printf("%-14lf", b);
                printf("%-14lf", a);
                printf("%-14lf", b - a);
                printf("%-14lf\n", f(a));
            }
        }
        /*// Sử dụng phương pháp đánh giá sai số tiên nghiệm
        int n = log2((b - a)/eps);
        for(int indexOfMyForLoop=0;indexOfMyForLoop<n+1;indexOfMyForLoop++)
        {
            if (f((a + b) / 2.0) * f(a) < 0)
            {
                b = (a + b) / 2.0;
                printf("%-14lf", a);
                printf("%-14lf", b);
                printf("%-14lf", b);
                printf("%-14lf", b - a);
                printf("%-14lf\n", f(b));
            }
            else
            {
                a = (a + b) / 2.0;
                printf("%-14lf", a);
                printf("%-14lf", b);
                printf("%-14lf", a);
                printf("%-14lf", b - a);
                printf("%-14lf\n", f(a));
            }
        }*/


        if (fabs(f(b)) <= eps)
            return b;
        else
            return a;
    }
}
