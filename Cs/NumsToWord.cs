/*
 * W skrócie:
 * - Program ma zabezpieczenie przed źle wprowadzonymi danymi
 * - Program zamienia kropkę na przecinek
 * - Program rozróżnia pozycję przecinka (np. jeśli pierwszy)
 * - ToDo ify dla prawidłowych nazw liczb po przeinku (np. 0,2 powinno podać dwie dziesiąte a nie dwa dziesiąte)
 * */

using System;
using System.Text; // dla StringBuilder

namespace ZapisSlowny
{
    class Program
    {
        static void Main(string[] args)
        {
            string podanaLiczbaStr, 
                liczbaSlownieStr, 
                liczbaSlowniePrzecinekStr, 
                sufix = "";
            bool wynikSprawdzenia;
            int gdziePrzecinek;
            float podanaLiczbaFloat;

            Console.WriteLine("Podaj liczbę, a napiszę ją słownie!" +
                              "\nPotrafię to zrobić tylko w zakresie od 0 do 999." +
                              "\nCzekam: ");

            // sprawdzenie poprawności danych
            do
            {
                podanaLiczbaStr = Console.ReadLine();

                // gdyby ktoś podał kropkę zamiast przecinka
                StringBuilder kropka = new StringBuilder(podanaLiczbaStr);
                kropka.Replace(".", ",");
                podanaLiczbaStr = kropka.ToString();
                gdziePrzecinek = podanaLiczbaStr.IndexOf(","); // szukanie przecinka w stringu

                // sprawdzenie czy jest liczbą i czy dobry zakres podanej liczby
                wynikSprawdzenia = float.TryParse(podanaLiczbaStr, out podanaLiczbaFloat);
                if (!wynikSprawdzenia || (podanaLiczbaFloat < 0) || (podanaLiczbaFloat > 999))
                {
                    Console.Write("Coś nie tak. Jeszcze raz: ");
                }
            } while (!wynikSprawdzenia || (podanaLiczbaFloat < 0) || (podanaLiczbaFloat > 999));

            int sklejonePrzedInt = 0,
                sklejonePoInt = 0;
            string sklejonePrzed = "",
                   sklejonePo = "";

            // jesli brak przecinka
            if (gdziePrzecinek == -1) 
            {
                for (int i = 0; i < podanaLiczbaStr.Length; i++)
                    sklejonePrzed += podanaLiczbaStr[i];

                sklejonePrzedInt = int.Parse(sklejonePrzed);
                Console.WriteLine("Sklejone przed = {0}", sklejonePrzedInt);

                liczbaSlownieStr = LiczbaNaSlowa(sklejonePrzedInt);
                Console.WriteLine("Wynik = {0}", liczbaSlownieStr);
            }


            else if (gdziePrzecinek > 0)
            {
                //dla całkowitych
                for (int i = 0; i < gdziePrzecinek; i++)
                    sklejonePrzed += podanaLiczbaStr[i];

                sklejonePrzedInt = int.Parse(sklejonePrzed); // parsowanie string na int

                //dla rzeczywistych po przecinku
                for (int i = ++gdziePrzecinek; i < podanaLiczbaStr.Length; i++)
                    sklejonePo += podanaLiczbaStr[i];

                sklejonePoInt = int.Parse(sklejonePo); // parsowanie string na int

                // dla przyrostka
                if (sklejonePoInt > 0 && sklejonePoInt < 9)
                    sufix = "dziesiętnych";

                else if(sklejonePoInt > 10 && sklejonePoInt < 99)
                    sufix = "setnych";

                else
                    sufix = "tysięcznych";

                // Tu się dzieje magia
                liczbaSlownieStr = LiczbaNaSlowa(sklejonePrzedInt);
                liczbaSlowniePrzecinekStr = LiczbaNaSlowa(sklejonePoInt);
                Console.WriteLine("Wynik = {0} i {1} {2}", liczbaSlownieStr, liczbaSlowniePrzecinekStr, sufix);
            }

            else // jesli przecinek na pierwszym miejscu tablicy string ( == 0)
            {
                for (int i = 1; i < podanaLiczbaStr.Length; i++)
                    sklejonePo += podanaLiczbaStr[i];
                    sklejonePoInt = int.Parse(sklejonePo);

                if (sklejonePoInt > 0 && sklejonePoInt < 9)
                    sufix = "dziesiętnych";

                else if (sklejonePoInt > 10 && sklejonePoInt < 99)
                    sufix = "setnych";

                else
                    sufix = "tysięcznych";

                liczbaSlowniePrzecinekStr = LiczbaNaSlowa(sklejonePoInt);
                Console.WriteLine("Wynik = {0} {1} ", liczbaSlowniePrzecinekStr, sufix);
            }
        }//main

        /// <summary>
        /// meotda zamieniająca liczbę na zapis słowny
        /// </summary>
        /// <param name="liczbaDoZmiany"></param>
        /// <returns>liczba podana przez użytkownika</returns>
        static string LiczbaNaSlowa(int liczbaDoZmiany)
        {
            if (liczbaDoZmiany == 0)
                return "zero";

            string slownie = "";
            string[] setki = new[] 
            {
                "zero",
                "sto ",
                "dwieście ",
                "trzysta ",
                "czterysta "
            };

            string[] jednosci = new[] 
            {
                "zero",
                "jeden",
                "dwa",
                "trzy",
                "cztery",
                "pięć",
                "sześć",
                "siedem",
                "osiem",
                "dziewięć",
                "dziesięć",
                "jedenaście",
                "dwanaście",
                "trzynaście",
                "czternaście",
                "piętnaście",
                "szesnaście",
                "siedemnaście",
                "osiemnaście",
                "dziewiętnaście"
            };

            // setki

            if (((liczbaDoZmiany / 100) > 0) && ((liczbaDoZmiany / 100) < 5))
            {
                slownie += setki[liczbaDoZmiany / 100];
                liczbaDoZmiany %= 100; // ucina setki z liczby i leci dalej
            }

            else if (((liczbaDoZmiany / 100) > 0) && ((liczbaDoZmiany / 100) >= 5))
            {
                slownie += jednosci[liczbaDoZmiany / 100] + "set ";
                liczbaDoZmiany %= 100;
            }

            // dziesiątki i jedności

            if (liczbaDoZmiany > 0)
            {
                string[] dziesiatki = new[] 
                {
                    "zero",
                    "dziesięć",
                    "dwadzieścia ",
                    "trzydzieści ",
                    "czterdzieści "
                };
                
                if (liczbaDoZmiany < 20)
                    slownie += jednosci[liczbaDoZmiany];
                else
                {
                    if (liczbaDoZmiany <= 49)
                        slownie += dziesiatki[liczbaDoZmiany / 10];

                    else if (liczbaDoZmiany <= 99)
                        slownie += jednosci[liczbaDoZmiany / 10] + "dziesiąt ";

                    if ((liczbaDoZmiany % 10) > 0)
                        slownie += jednosci[liczbaDoZmiany % 10];
                }
            }// if liczbaDoZmiany > 0

            return slownie;
        } // LiczbaNaSlowa
    } // Program
}