using System;

namespace Giai_phuong_trinh_bac_n
{
    class Program
    {
        static double[] a = new double[1000];
        static double[] b = new double[1000];
        static double[] c = new double[1000];
        static double[] d = new double[1000];
        static int n, k, KL, dem = 0;
        static double mx, mn, a1;

        static double f(double x)
        {
            double p = 0;
            for (int i = 0; i <= n; i++)
            {
                p = p * x + a[i];
            }
            return p;
        }

        static double fdh(double x)
        {
            double p = 0;
            int m;
            m = n;
            for (int i = 0; i <= n - 1; i++)
            {
                p = p * x + m * a[i];
                m = m - 1;
            }
            return p;
        }

        static double GiaiNghiem(double x)
        {
            int start, finish;
            //int dem=0;
            start = 0;
            finish = 10000;
            if (n == 1)
            {
                if (a[0] != 0) return -a[1] / a[0];
                else return KL = 1;
            }
            while (fdh(x) == 0)
            {
                x = x + 0.00003;
            }
            while (start < finish)
            {
                if (start == (finish - 1))
                {
                    if (Math.Abs(f(x)) > 0.1) KL = 1;
                }
                x = x - (f(x) / fdh(x));
                if (Math.Abs(f(x)) < 0.000000001) return x;
                start++;
                //dem++;
            }
            return x;
        }

        static void chiadathuc(double x)
        {
            for (int i = 1; i < n; i++)
            {
                a[i] = a[i] + a[i - 1] * x;
            }
            n = n - 1;
        }

        static void Main(string[] args)
        {
            double x;
            int T = 0;
            do  // Lấy bậc của đa thức
            {
                Console.Write("Giai da thuc bac n voi (n>0), nhap n= ");
                n = Int32.Parse(Console.ReadLine());
            }
            while (n <= 0);

            Console.WriteLine("\nNhap cac he so:");
            do  // Lấy hệ số đầu tiên (khác 0)
            {
                Console.Write("x^{0} (Khac 0) = ", n);
                a[0] = Double.Parse(Console.ReadLine());
            } while (a[0] == 0);

            //  Lấy hệ số còn lại
            for (int i = 1; i <= n; i++)
            {
                Console.Write("x^{0} = ", n - i);
                a[i] = Double.Parse(Console.ReadLine());
                // f(x) = a1*x^n + a2x*n-1 + ... + an-1*x + an
            }

            // Đổi dấu phương trình sao cho hệ số đầu tiên luôn dương
            if (a[0] < 0)
            {
                for (int i = 0; i <= n; i++)
                {
                    a[i] = -a[i];
                }
            }

            // k là vị trí có hệ số âm đầu tiên của đa thức (Lấy bậc từ to nhất đến nhỏ nhất)
            for (int i = 1; i <= n; i++)
            {
                if (a[i] < 0)
                {
                    k = i;
                    break;
                }
            }

            // b là mảng lưu giá trị các hệ số âm của a ở vị trí tương ứng. Những cái nào đéo âm cho bằng 0 hết
            for (int i = 0; i <= n; i++)
            {
                if (a[i] < 0)
                {
                    b[i] = -a[i];
                }
                else b[i] = 0;
            }

            // mx là số nhỏ nhất trong b
            mx = b[0];
            for (int i = 1; i <= n; i++)
            {
                if (b[i] > mx)
                {
                    mx = b[i];
                }
            }

            double m = 1 + Math.Pow(mx / a[0], 1.0 / k);
            Console.WriteLine("m là {0}", m);

            for (int i = 0; i <= n; i++)
            {
                c[i] = Math.Pow(-1, i) * a[i];
            }

            if (c[0] < 0)
            {
                for (int i = 0; i <= n; i++)
                {
                    c[i] = -Math.Pow(-1, i) * a[i];
                }
            }

            for (int i = 1; i <= n; i++)
            {
                if (c[i] < 0)
                {
                    k = i;
                    break;
                }
            }

            for (int i = 0; i <= n; i++)
            {
                if (c[i] < 0)
                {
                    d[i] = -c[i];
                }
            }

            mn = d[0];
            for (int i = 1; i <= n; i++)
            {
                if (d[i] > mn)
                {
                    mn = d[i];
                }
            }
            double nn = -1 - Math.Pow(mn / a[0], 1.0 / k);
            Console.WriteLine("nn là {0}", nn);
            a1 = (m - nn) / n;
            do
            {
                if (f(nn) * f(nn + a1) < 0)
                {
                    Console.WriteLine("Khoang phan li nghiem la: {0},{1}", nn, nn + a1);
                }
                nn = nn + a1;
            }
            while (nn <= m);

            while (n > 0)
            {
                x = GiaiNghiem(0);
                if (KL == 1)
                {
                    if (T == 0) Console.WriteLine("PT vo nghiem");
                    break;
                }
                if (T == 0) Console.WriteLine("\nPhuong trinh co nghiem la:");
                Console.WriteLine("X= {0}", x);
                chiadathuc(x);
                T = 1;
                Console.WriteLine("{0}", dem);
            }
            Console.ReadKey();
        }
    }
}

