using System;
using System.IO;

class Program
{
    static int NghichDao(int a, int n)
    {
        int Q, A1 = 1, A2 = 0, A3 = n, B1 = 0, B2 = 1, B3 = a;
        while (B3 != 0 && B3 != 1)
        {
            Q = A3 / B3;
            int B1_cp = B1, B2_cp = B2, B3_cp = B3;
            B1 = A1 - B1 * Q;
            B2 = A2 - B2 * Q;
            B3 = A3 - B3 * Q;

            A1 = B1_cp;
            A2 = B2_cp;
            A3 = B3_cp;
        }
        return (B2 + n) % n;
    }

    static int HaBac(int a, int m, int n)
    {
        if (m == 1) return a % n;
        int c = m / 2;
        int d = m % 2;
        int v = (int)(Math.Pow(HaBac(a, c, n), 2) * Math.Pow(a, d)) % n;
        return v;
    }

    static void Main(string[] args)
    {
        // Đọc giá trị từ tệp văn bản
        string[] lines = File.ReadAllLines(@"D:\DaiHocNhanLam\HocKi6\AnToanBaoMatThongTin\Code_nhom\RSA\inrsa.txt");
        int p = int.Parse(lines[0]);
        int q = int.Parse(lines[1]);
        int e = int.Parse(lines[2]);
        int M = int.Parse(lines[3]);

        int n = p * q;
        int euler_n = (p - 1) * (q - 1);
        int d = NghichDao(e, euler_n); // d = e^-1 mod phi-n
        int C = HaBac(M, e, n); // M^e mod n
        int g = HaBac(C, d, n);

        // Ghi kết quả vào tệp văn bản
        using (StreamWriter writer = new StreamWriter(@"D:\DaiHocNhanLam\HocKi6\AnToanBaoMatThongTin\Code_nhom\RSA\outrsa.txt"))
        {
            writer.WriteLine("PU = {" + e + "," + n + "}");
            writer.WriteLine("PR = {" + d + "," + n + "}");
            writer.WriteLine("C = " + C);
            writer.WriteLine("M = " + g);
        }
    }
}
