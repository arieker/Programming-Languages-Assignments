using System;
using System.Threading;

class Program
{
    static void Main(string[] args)
    {
        Thread thread1 = new Thread(CountByOnes);
        Thread thread2 = new Thread(CountByTwos);
        Thread thread3 = new Thread(CountBySevens);

        thread1.Start();
        thread2.Start();
        thread3.Start();
    }

    static void CountByOnes()
    {
        for (int i = 1; i <= 10000; i++)
        {
            Console.WriteLine($"1:{i}:");
        }
    }

    static void CountByTwos()
    {
        for (int i = 2; i <= 20000; i += 2)
        {
            Console.WriteLine($"2:{i}:");
        }
    }

    static void CountBySevens()
    {
        for (int i = 7; i <= 70000; i += 7)
        {
            Console.WriteLine($"3:{i}:");
        }
    }
}