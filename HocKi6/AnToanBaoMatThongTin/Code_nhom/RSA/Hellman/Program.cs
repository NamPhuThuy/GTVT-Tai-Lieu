using System;
using System.IO;

class Program
{
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
        string[] lines = File.ReadAllLines(@"C:\Users\dth63\Documents\Zalo Received Files\congkhai\Hellmaninput.txt");
        int q = int.Parse(lines[0]);
        int a = int.Parse(lines[1]);
        int xa = int.Parse(lines[2]);
        int xb = int.Parse(lines[3]);

        int ya = BinhPhuong(a, xa, q);
        int yb = BinhPhuong(a, xb, q);

        int ka = BinhPhuong(yb, xa, q);
        int kb = BinhPhuong(ya, xb, q);

        // Ghi kết quả vào tệp văn bản
        using (StreamWriter writer = new StreamWriter(@"C:\Users\dth63\Documents\Zalo Received Files\congkhai\Hellmanoutput.txt"))
        {
            writer.WriteLine("Gia tri YA: " + ya);
            writer.WriteLine("Gia tri YB: " + yb);
            writer.WriteLine("Gia tri KA: " + ka);
            writer.WriteLine("Gia tri KB: " + kb);
        }
    }
}
