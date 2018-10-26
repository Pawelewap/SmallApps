using System;

namespace Ackermann
{
    class Program
    {
        static void Main(string[] args)
        {
            int result;

            for (int m = 0; m < 4; m++)
            {
		        for (int n = 0; n < 12; n++) // Większa wartość n daje stack overflow przy m => 3
                {
                    result = ackermann(m, n);
                    Console.WriteLine("Dla ({0}, {1}) : {2}", m, n, result);
		        } // petla dla n
	        } // petla dla m
        } // main

        static int ackermann(int m, int n)
        {
            if (m == 0)
                return n + 1;
            else if ((m > 0) && (n == 0))
                return ackermann(m - 1, 1);
            else
                return ackermann(m - 1, ackermann(m, n - 1));
        }// ackermann
    }
}
