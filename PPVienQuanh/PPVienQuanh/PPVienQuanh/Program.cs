using System;

namespace Phuong_phap_vien_quanh
{
    class Program
    {
        static void Print1(int n, double[] A)
        {
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine("{0} ", Math.Round(A[i], 4));
            }
        }
        static void Print(int n, double[,] A)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write("{0}  ", Math.Round(A[i, j], 4));
                }
                Console.Write("\n");
            }
        }
        static void Nhap1(int n, double[,] A, double[,] B)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    A[i, j] = B[i, j];
                }
            }
        }
        static void Nhap2(int n, double[] A, double[,] B)
        {
            for (int i = 0; i < n; i++)
            {
                A[i] = B[i, n];
            }
        }
        static void Nhap3(int n, double[] A, double[,] B)
        {
            for (int i = 0; i < n; i++)
            {
                A[i] = B[n, i];
            }
        }
        static double[] TichMatrix1(int n, double[,] A, double[] B)
        {
            double[] X = new double[n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    X[i] += A[i, j] * B[j];
                }
            }
            return X;
        }
        static double[] TichMatrix2(int n, double[] B, double[,] A)
        {
            double[] X = new double[n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    X[i] += B[j] * A[j, i];
                }
            }
            return X;
        }
        static double TichMatrix3(int n, double[] A, double[] B)
        {
            double X = 0;
            for (int i = 0; i < n; i++)
            {
                X = X + A[i] * B[i];
            }
            return X;
        }
        static double[,] TichMatrix4(int n, double[] A, double[] B)
        {
            double[,] X = new double[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    X[i, j] = A[i] * B[j];
                }
            }
            return X;
        }
        static double[,] CongMatrix1(int n, double[,] A, double[,] B)
        {
            double[,] X = new double[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    X[i, j] = A[i, j] + B[i, j];
                }
            }
            return X;
        }
        static double[,] NhanSoVsMatrix(int n, double m, double[,] A)
        {
            double[,] KQ = new double[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    KQ[i, j] = m * A[i, j];
                }
            }
            return KQ;
        }
        static double[] NhansovsMatrix2(int n, double m, double[] A)
        {
            double[] X = new double[n];
            for (int i = 0; i < n; i++)
            {
                X[i] = m * A[i];
            }
            return X;
        }
        static double[,] NghichDaoCap2(double[,] A)
        {
            double m = 1 / (A[0, 0] * A[1, 1] - A[1, 0] * A[0, 1]);
            double[,] X = new double[2, 2];
            X[0, 0] = m * A[1, 1];
            X[0, 1] = (-m) * A[0, 1];
            X[1, 0] = (-m) * A[1, 0];
            X[1, 1] = m * A[0, 0];
            return X;
        }
        static double det(int n, double[,] A)
        {
            double s, sum = 0;
            if (n == 1) return A[0, 0];
            if (n == 2) return (A[0, 0] * A[1, 1] - A[0, 1] * A[1, 0]);
            for (int k = 0; k < n; k++)
            {
                double[,] S = new double[n, n];
                for (int i = 0; i < n; i++)
                {
                    for (int j = 1; j < n; j++)
                    {
                        if (i < k) S[i, j - 1] = A[i, j];
                        else { if (i > k) S[i - 1, j - 1] = A[i, j]; }
                    }
                }
                if (k % 2 == 0) s = 1;
                else s = -1;
                sum = sum + A[k, 0] * s * det(n - 1, S);
            }
            return sum;
        }
        static void Main(string[] args)
        {
            #region Du lieu dau vao
            int n = 4;
            /*double[,] a =
            {
                { 1,2,3,3,7,5},
                {4,5,6,-1,-2,1},
                {7,8,-2,2,3,2 },
                {1,-2,5,1,0,1 },
                {0,2,1,-2,3,4 },
                {1,2,3,-5,1,-2 }
            };*/
            double[,] a =
            {
                {1,4,1,3},
                {0,-1,3,-1 },
                {3,1,0,2 },
                {1,-2,5,1 }
            };
            double[,] a1 =
           {
                {1,4,1,3},
                {0,-1,3,-1 },
                {3,1,0,2 },
                {1,-2,5,1 }
            };
            if (a.GetLength(0) != a.GetLength(1))//Kiem tra ma tran vuong
            {
                Console.WriteLine("A khong phai ma ma tran vuong => STOP");
                Console.ReadKey();
                Environment.Exit(0);
            }
            if (det(n, a) == 0)
            {
                Console.WriteLine("A la ma tran suy bien => STOP");
                Console.ReadKey();
                Environment.Exit(0);
            }
            #endregion
            double[,] H = new double[n, n];

            for (int i = 2; i < n; i++)
            {
                double[,] a11 = new double[i, i];
                double[,] NghichDao = new double[i, i];
                double[] a21 = new double[i];
                double[] a12 = new double[i];
                double a22 = a[i, i];
                double[,] b11 = new double[i, i];
                double[] b21 = new double[i];
                double[] b12 = new double[i];
                double b22 = 0;
                double[] X = new double[i];
                double[] Y = new double[i];
                double Teta = 0;
                Nhap1(i, a11, a);
                Console.WriteLine("\nIn ma tran a11");
                Print(i, a11);
                Nhap2(i, a12, a);
                Console.WriteLine("\nIn ma tran a12");
                Print1(i, a12);
                Nhap3(i, a21, a);
                Console.WriteLine("\nIn ma tran a21");
                Print1(i, a21);
                if (det(i, a11) == 0)
                {
                    Console.WriteLine("Ma tran con cap {0} suy bien => Khong ap dung duoc phuong phap vien quanh", i + 1);
                    Console.ReadKey();
                    Environment.Exit(0);
                }
                else
                {
                    Console.WriteLine("\nDo det(a11) = {0} (khac 0) => ton tai ma tran nghich dao a11 =>Tinh tiep", det(i, a11));
                }
                if (i == 2)
                {
                    NghichDao = NghichDaoCap2(a11);
                }
                if (i > 2)
                {
                    for (int k = 0; k < i; k++)
                    {
                        for (int t = 0; t < i; t++)
                        {
                            NghichDao[k, t] = H[k, t];
                        }
                    }
                }
                Console.WriteLine("\nMa tran nghich dao cua a11 la:");
                Print(i, NghichDao);
                X = TichMatrix1(i, NghichDao, a12);
                Console.WriteLine("\nTinh duoc ma tran X la:");
                Print1(i, X);
                Y = TichMatrix2(i, a21, NghichDao);
                Console.WriteLine("\nTinh duoc ma tran Y la: ");
                Print1(i, Y);
                Teta = 1 / (a22 - TichMatrix3(i, Y, a12));
                b11 = CongMatrix1(i, NghichDao, NhanSoVsMatrix(i, Teta, TichMatrix4(i, X, Y)));
                b12 = NhansovsMatrix2(i, -Teta, X);
                b21 = NhansovsMatrix2(i, -Teta, Y);
                b22 = Teta;
                for (int k = 0; k < i; k++)
                {
                    for (int t = 0; t < i; t++)
                    {
                        H[k, t] = b11[k, t];
                    }
                }
                for (int k = 0; k < i; k++)
                {
                    H[k, i] = b12[k];
                }
                for (int k = 0; k < i; k++)
                {
                    H[i, k] = b21[k];
                }
                H[i, i] = Teta;
                Console.WriteLine("(Teta)^-1 = {0}", Teta);
                Console.WriteLine("\nMa tran B11 cap {0}", i);
                Print(i, b11);
                Console.WriteLine("\nMa tran nghich dao A{0} la:", i + 1);
                Print(i + 1, H);
                Console.WriteLine("\n******************************************************************");
            }
            Console.WriteLine("Ma tran nghich dao can tim bang phuong phap vien quanh la:");
            for (int k = 0; k < n; k++)
            {
                for (int t = 0; t < n; t++)
                {
                    Console.Write("{0}   ", Math.Round(H[k, t], 4));
                }
                Console.Write("\n");
            }
            double[,] X1 = new double[n, n];
            for (int k = 0; k < n; k++)
            {
                for (int t = 0; t < n; t++)
                {
                    for (int m = 0; m < n; m++)
                    {
                        X1[k, t] += a1[k, m] * H[m, t];
                    }
                }
            }
            Console.WriteLine("Tich 2 ma tran la: ");
            for (int k = 0; k < n; k++)
            {
                for (int t = 0; t < n; t++)
                {
                    Console.Write("{0}\t", Math.Round(X1[k, t], 4));
                }
                Console.Write("\n");
            }


            Console.ReadKey();
        }
    }
}
