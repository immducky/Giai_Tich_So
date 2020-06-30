/// CREATE ON CODEBLOCKS 5/5/2020

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <dos.h>
#include <stdbool.h>
#include <string.h>

#define M 10000
//int n,m;

//int used[M][M];

/// Lưu lại giá trị các hàng và cột đã khử.
int Mark(int used[M][M],int m, int n, int x,int y);

/// Nhập Ma trận.
double EnterMatrix( double A[M][M], int m, int n );

/// Hiển thị ma trận.
void PrintMatrix( double A[M][M], int m, int n );

/// Hiển thị Phương trình
void PrintEquations( double A[M][M], int m, int n );

/// Quá trình đọc nghiệm.
double PrintResult( double A[M][M],double B[M][M], int index[M], int m, int n );

/// tìm vị trí phần tử khử.
int Finex_element( double A[M][M],int used[M][M], double Maxx, int m, int n, int x );

/// tìm vị trí phần tử  khử.
int Finey_element( double A[M][M],int used[M][M], double Maxx, int m, int n, int x );

/// Khử
double Handle_element(double A[M][M], int m, int n,int x,int y);

/// Tìm giá trị tuyệt đối lớn nhất .
double Maxabs( double A[M][M],int used[M][M], int m, int n );

/// Sắp xếp lại Ma trận .
int OrderMatrix( double A[M][M], int m, int n, int x, int y );

///
int Isnotsolution( double A[M][M], int m, int n, int Is);

/// Tìm hạng của ma trận .
int Rank( double A[M][M], int m, int n);
/// Kiểm tra tính đúng
double Check( double A[M][M],double Solutions[M], int m, int n);


main()
{

    FILE *fp;
    char FName[M];
    int m, n, x, y, i;
    int s = 0;
    int choice;
    int key;
    int Is = 0;
    int Count = 0;
    int index[M];
    double A[M][M],B[M][M];
    double Maxx = 0;
    double Solutions[M];
    int used[M][M];
    for( int i = 1; i <= m; ++i)
        for ( int j = 1; j <= n; j++)
            used[i][j] = 0;
    for( int i = 1; i <= n; ++i)
        index[i] = 0;

   do
   {
       printf( "\n\tGAUSS-JORDAN METHOD\n" );
       printf( "\t      (Ax=b)        \n" );
       printf( "1.Read Matrix from file.\n");
       printf( "2.Enter Matrix from keyboard.\n");
       printf( "0.Exit.\n");
       scanf( "%d", &key );
       switch(key)
       {
       case 1:
           printf("\nEnter the file name: ");
           scanf("%s", &FName );
           //gets(FName);
           fp = fopen( FName, "r" );
           if(!fp)
           {
               printf("\nFile ko ton tai.");
               break;
           }
           fscanf( fp, "%d\n", &m );
           fscanf( fp, "%d\n", &n );

           for( int i = 1; i <= m; ++i )
            for( int j = 1; j <= n+1; ++j )
            {
               fscanf( fp, "%lf\t", &A[i][j]);
            }
           fclose( fp );
           PrintEquations( A, m, n);
           Is = Isnotsolution( A, m,n,Is );
           for( int i = 1; i <= m; ++i )
            for( int j = 1; j <= n+1; ++j )
            {
               B[i][j] = A[i][j];
            }
           for( int i = 1; i <= n; ++i)
                Solutions[i] = 0;
           tt:
            {
                while( Count < m-1 || Maxx != 0 )
                {
                    Is = Isnotsolution( A, m,n,Is );
                    if( Is == 1 )
                    {
                        printf( "\nThe system of equations has no solution! ");
                        printf( "\nReason : Appearance as 0X1 + 0X2 +...+ Xn = b. ");
                        break;
                    }
                    x = 0; y =0;
                    Maxx = Maxabs( A, used, m, n);
                    x = Finex_element( A,used,Maxx, m, n, x);
                    y = Finey_element( A,used,Maxx, m, n, y);
                    //OrderMatrix(A,m,n,x,y);
                    //y = x;
                    i = y;
                    index[i] = x;
                    Mark(used, m, n, x, y);
                    Handle_element( A, m, n, x, y);
                    //printf("Reduction %d:",Count+1);
                    //PrintMatrix(A,m,n);
                    Maxx = Maxabs( A, used, m, n);
                    //printf("\n");
                    Count++;
                }
                if( Is == 0 )
                {
                    printf("\nIndex of reducing element is:");
                    for( int i = 1; i <= n; ++i)
                        printf("\t%d",index[i]);
                    printf("\nThe Matrix after Gauss-Jordan method.");
                    PrintMatrix(A,m,n);
                    PrintResult(A,B,index,m,n);
                    fflush(stdin);
                }
            }
            break;
       case 2:
            printf( " Enter the number of variables:\n" );
            scanf( "%d", &n );
            printf( " Enter the number of  the equations:\n" );
            scanf( "%d", &m );
            EnterMatrix( A, m, n );
            PrintEquations( A, m, n );
            Is = Isnotsolution( A, m,n, Is );
            for( int i = 1; i <= m; ++i )
                for( int j = 1; j <= n+1; ++j )
                {
                    B[i][j] = A[i][j];
                }
            for( int i = 1; i <= n; ++i)
                Solutions[i] = 0;
            goto tt;
            break;
       case 0:
           exit(0);
       default:
           printf("Try again.");
           break;
       }

   }while( key != 1 || key != 2 || key != 0);
}

double EnterMatrix( double A[M][M], int m, int n )
{
    printf( "\tAX = b\n" );
    for( int i = 1 ; i <= m; ++i )
    {
        printf( "\n" );
        for( int j = 1; j <= n + 1; ++j )
        {
         scanf( "%lf", &A[i][j] );
        }
    }

}

void PrintEquations( double A[M][M], int m, int n )
{
    printf( "\nThe system equations just enterred is: ");
    for( int i = 1; i <= m; ++i )
    {
        printf( "\n" );
        printf( "%0.2lfX1", A[i][1] );
        for( int j = 2; j <= n; ++j )
        {
            if( A[i][j] == 0 )
                continue;
            if( A[i][j] < 0 )
            {
                double b = A[i][j];
                printf( " - %0.2lfX%d", fabs(b), j );
            }
            else
                printf( " + %0.2lfX%d", A[i][j], j );
        }
        printf( " = %0.2lf.\n ", A[i][n + 1] );
    }
}

void PrintMatrix( double A[M][M], int m, int n )
{
    for( int i = 1; i <= m; ++i )
    {
        printf("\n");
        for( int j = 1; j <= n + 1; ++j )
        {
            printf( "%.2lf\t", A[i][j] );
        }
    }
    printf("\n");
}

double Maxabs( double A[M][M],int used[M][M], int m, int n )
{
    double Maxx=0;
    double tmp,t;
    for( int i = 1; i <= m; i++ )
        for( int j = 1; j <= n; j++)
        {
            if( used[i][j] == 1)
                continue;
            tmp = A[i][j];
            t = fabs(tmp);
            if( Maxx < t )
                Maxx = t;
        }
    return Maxx;
}

/// Các giá trị tại used[i][j] bằng 1 nếu cùng hàng hoặc cột với phân tử khử.
int Mark( int used[M][M], int m, int n,int x, int y )
{
    for( int i = 1; i <= m; ++i )
        for( int j = 1; j <= n; ++j )
            if( i == x || j == y )
                    used[i][j] = 1;
}

int Finex_element( double A[M][M],int used[M][M], double Maxx, int m, int n, int x)
{
    double tmp;
    for( int i = 1; i <= m; ++i )
    {
        for( int j = 1; j <= n; ++j )
        {
            tmp = A[i][j];
            /// Bỏ qua vị trí  hàng và cột đã khử.
            if(used[i][j] == 1)
                continue;
            if( fabs( tmp ) == 1 )
            {
                x = i;
                return x;
                break;

            }
        }
        if( x == 0 )
        {
            for( int j = 1; j <= n; ++j )
            {
                tmp = A[i][j];
                if(used[i][j] == 1)
                continue;
                else if( fabs(tmp) == Maxx )
                {
                    x = i;
                    return x;
                    break;

                }
            }
        }
    }

}

int Finey_element( double A[M][M],int used[M][M], double Maxx, int m, int n, int y)
{
    double tmp;
    for( int i = 1; i <= m; ++i )
    {
        for( int j = 1; j <= n; ++j )
        {
            tmp = A[i][j];
            /// Bỏ qua vị trí  hàng và cột đã khử.
            if(used[i][j] == 1)
                continue;
            if( fabs( tmp ) == 1 )
            {
                y = j;
                return y;
                break;

            }
        }
        if( y == 0 )
        {
            for( int j = 1; j <= n; ++j )
            {
                tmp = A[i][j];
                if(used[i][j] == 1)
                continue;
                else if( fabs(tmp) == Maxx )
                {
                    y = i;
                    return y;
                    break;

                }
            }
        }
    }
}

double Handle_element( double A[M][M], int m, int n,int x,int y )
{
    double mid;
    for( int i = 1; i <= m; ++i)
    {
        /// Giữ nguyên giá trị hàng thứ i.
        if( i == x )
            continue;
        mid = A[i][y]/A[x][y];
        for( int j = 1; j <= n + 1; ++j )
        {
            A[i][j] = A[i][j] - A[x][j] * mid;

        }
    }

}

/// Kiểm tra phương trình vô nghiệm (lỗi trả về ...)
int  Isnotsolution( double A[M][M], int m, int n, int Is)
{
    int dem = 0;
    for( int i = 1; i <= m; ++i )
    {
        for( int j = 1; j <= n; ++j )
        {
            if( A[i][j] == 0 )
            {
                dem++;
                //return dem;
            }
            else
                continue;
        }
        if( dem == n )
        {
            if( A[i][n+1] != 0 )
                Is = 1;
                return Is;
                break;
        }
        else
        {
            dem = 0;
            continue;
        }
    }
    return Is;
}


/// Đổi vị trí cột x với cột y.
int OrderMatrix( double A[M][M], int m, int n, int x, int y )
{
    double tmp;
    if( x != y )
    {
        for( int i = 1; i <= m; ++i )
        {
            tmp = A[i][x];
            A[i][x] = A[i][y];
            A[i][y] = tmp;
        }
    }
}

/// xác định Rank của ma trận A|b.
int Rank(double A[M][M], int m, int n)
{
	int i ,j , rank = 0, flag = 0;
	for(i = 1; i <= m; ++i)
	{
		for(j = 1; j <= n+1; ++j)
		{
			if(A[i][j] != 0)
                flag = 1;
		}
		if(flag == 1)
		{
			rank++;
			flag = 0;
		}
	}
	return rank;
}

///Quá trình đọc nghiệm.
double PrintResult( double A[M][M],double B[M][M] , int index[M], int m, int n )
{
    int Rind = 0;
    int rankM = Rank(A,m,n);
    printf("\nRankM = %d\n",rankM);
    double Solutions[n];
    /// xác định rank của A thông qua index[].
    /// nếu khác 0 thì rank +1.
    for( int i = 1; i <= n; ++i )
    {
        if( index[i] != 0)
            Rind++;
    }
    printf("\nRind = %d",Rind);
    /// Hạng của A nhỏ hơn hạng A|b => vô nghiệm
    if( Rind != rankM )
    {
        printf("\nThe system of equations has no solution!");
    }
    /// r(A) số ẩn -> Nghiệm duy nhất.
    if( Rind == rankM && Rind == n )
    {
        printf("\nThe system of equations has unique solution!");
        for( int i = 1; i <= n; ++i )
        {
            int l = index[i];
            Solutions[i] = A[l][n+1]/A[l][i];
            printf("\nX%d = %lf", i, Solutions[i]);
        }
    }
    /// r(A) = r(A|b) -> vô số nghiệm.
    if( Rind == rankM && Rind < n )
    {
        /// Số ẩn tham số bằng n trừ đi số phần tử khử.
        int k = n - Rind;
        int c[k];
        int v[Rind];
        int v1[Rind];
        double ValP[k];
        double Val[Rind];
        int US[n];
        int U[n];
        for( int i = 1; i <= n; ++i)
        {
            US[i] = 0;
            U[i] = 0;
        }
        printf("\nThe system of equations has countless solutions!\n");

        /// xác định các ẩn tham số bằng cách xét mảng index.
        /// index[j] = 0 -> ẩn j là ẩn tham số .
        for( int i = 1 ; i <= k; ++i )
            for( int j = 1; j <= n; ++j)
            {
                if( index[j] == 0 && U[j] != 1)
                    {
                        c[i] = j;
                        U[j] = 1;
                        break;
                    }
            }
        /// xác định các ẩn phụ thuộc bằng cách xét mảng index.
        /// index[j] != 0 -> ẩn j là ẩn tham số.
        for( int i = 1 ; i <= Rind; ++i )
            for( int j = 1; j <= n; ++j)
            {
                if( index[j] != 0 && US[j] != 1)
                {
                        v[i] = j;
                        v1[i] = index [j];
                        US[j] = 1;
                        break;
                }
            }
        for( int i = 1 ; i <= Rind; ++i )
            printf("%d\t",v[i]);
        printf("\n");
        for( int i = 1; i <= Rind; ++i)
            printf("%d\t",v1[i]);

        /// Đọc nghiệm
        for( int j = 1; j <= k; ++j )
        {
            /// Ẩn tham số
            for( int i = 1; i <= n; ++i )
            {
                int p,q,e;
                p = c[j];
                if( i == p )
                {
                    printf("\nX%d any value of R.",i);
                }
            }
        }
        /// Ẩn phụ thuộc
        for( int i = 1; i <= Rind; ++i )
        {
            int l = v[i];
            int l1 = v1[i];
            for( int j = 1; j <= n; ++j )
            {
                if( j == l)
                {
                    double b;
                    b = A[l1][n+1]/A[l1][l];
                    printf("\nX%d = %lf",j,b);
                    for( int t = 1; t <= k; ++t )
                    {
                        double b1;
                        int p = c[t];
                        b1 = A[l1][p]/A[l1][l];
                        if( fabs(b1) != 0.00)
                        {
                            if( b1 < 0 )
                            {
                                printf( " + %lfX%d", fabs(b1), p );
                            }
                            else
                                printf(" - %lfX%d", b1, p);
                        }
                    }
                }
            }

        }
        /// Nếu có ẩn tham số thì thực hiện
        printf("\n");
        if( k > 0)
        {
            /// Nhận giá trị cho các ẩn thâm số
            for( int i = 1; i <= k; ++i )
            {
                int p = c[i];
                if ( p != 0 )
                {
                    printf("\nX%d = ",p);
                    scanf("%lf",&Solutions[p]);
                }
            }
            for( int i = 1; i <= Rind; ++i )
            {
                int l = v[i];
                int l1 = v1[i];
                for( int j = 1; j <= n; ++j )
                {
                    if( j == l)
                    {
                        Solutions[l] = A[l1][n+1]/A[l1][l];
                        for( int t = 1; t <= k; ++t )
                        {
                            double b1,b2;
                            int p = c[t];
                            b1 = A[l1][p]/A[l1][l];
                            b2 = Solutions[p];
                            Solutions[l] = Solutions[l] - (b1*b2);
                        }
                    }
                }
            }
            for( int i = 1; i <= n; ++i )
                printf( "\nX%d = %lf ", i, Solutions[i] );
        }
    }
    printf("\n");
    if( ( Rind == rankM && rankM == n ) || (Rind == rankM && rankM < n ) )
        Check( B, Solutions, m, n);
}

double Check( double B[M][M],double Solutions[M], int m, int n)
{
    double b[m];
    for( int i = 1; i <= m; ++i )
        b[i] = 0;
    for( int i = 1; i <= m; ++i )
        for( int j = 1; j <= n; ++j )
        {
            b[i] = b[i] +( B[i][j]*Solutions[j] );
        }
    printf( "\nA*Solutions: ");
    for( int i = 1; i <= m; ++i )
        printf( "\n%lf ", b[i] );
}

