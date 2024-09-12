using System;
using System.IO;

class Program
{
    static int NghichDao(int a, int n)
    {
        for (int i = 2; i <= a + n; i++)
        {
            if ((a * i) % n == 1) return i;
        }
        return 0; // Trường hợp không tìm thấy
    }

    static int BinhPhuong(int a, int m, int n)
    {
        int res = 1, nho = a;
        long kq;
        while (true)
        {
            int mu = m / 2;
            if (mu == 0) break;

            if (m % 2 != 0)
            {
                res = (res * a) % n;
            }
            kq = (long)a * a % n;
            m /= 2;

            a = (int)kq;
        }
        return (int)((a * res) % n);
    }

    static void Main(string[] args)
    {
        // Đọc giá trị từ tệp văn bản
        string[] lines = File.ReadAllLines(@"C:\Users\dth63\Documents\Zalo Received Files\congkhai\RSAinput.txt");
        int p = int.Parse(lines[0]);
        int q = int.Parse(lines[1]);
        int e = int.Parse(lines[2]);
        int M = int.Parse(lines[3]);

        int n = p * q;
        int euler_n = (p - 1) * (q - 1);

        int d = NghichDao(e, euler_n);

        int C = BinhPhuong(M, d, n);
        int g = BinhPhuong(C, e, n);

        // Ghi kết quả vào tệp văn bản
        using (StreamWriter writer = new StreamWriter(@"C:\Users\dth63\Documents\Zalo Received Files\congkhai\RSAoutput.txt"))
        {
            writer.WriteLine("PU = {" + e + "," + n + "}");
            writer.WriteLine("PR = {" + d + "," + n + "}");
            writer.WriteLine("C = " + C);
            writer.WriteLine("M = " + M);
        }
    }
}
