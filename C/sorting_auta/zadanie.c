#include "zadanie.h"
#include <stdio.h>

int i = 0, j = 0;

///////// LOSOWANIE ///////////
int losuj_liczbe(int minim, int maxim)
{
    return rand() % maxim + minim;
}

//////// SWAP ////////////////
void swap(Samochod *tab, int poz)
{
    int temp = tab[poz].cena;
    tab[poz].cena = tab[poz + 1].cena;
    tab[poz + 1].cena = temp;

    temp = tab[poz].waga;
    tab[poz].waga = tab[poz + 1].waga;
    tab[poz + 1].waga = temp;

    temp = tab[poz].jakiKolor;
    tab[poz].jakiKolor = tab[poz + 1].jakiKolor;
    tab[poz + 1].jakiKolor = (kolor)temp;

    temp = tab[poz].jakieWyposazenie;
    tab[poz].jakieWyposazenie = tab[poz + 1].jakieWyposazenie;
    tab[poz + 1].jakieWyposazenie = (wyposazenie)temp;

}

/////// SORT ////////////////
void sortuj_samochody(int wybor, Samochod *tablica)
{
    switch (wybor)
    {
    case 0:
        exit(0);
        break;

    case 1: // najnizsza cena
        system("cls");

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (tablica[j].cena > tablica[j + 1].cena)
                    swap(tablica, j);
            }
        }

        for (i = 0; i < 10; i++)
        {
            printf("cena: %d, ", tablica[i].cena);
            printf("Waga: %d, ", tablica[i].waga);
            printf("kolor: %d, ", tablica[i].jakiKolor);
            printf("wyposazenie: %d\n", tablica[i].jakieWyposazenie);
        }
        break;



    case 2: // najwyzsza cena
        system("cls");

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (tablica[j].cena < tablica[j + 1].cena)
                    swap(tablica, j);
            }
        }

        for (i = 0; i < 10; i++)
        {
            printf("cena: %d, ", tablica[i].cena);
            printf("Waga: %d, ", tablica[i].waga);
            printf("kolor: %d, ", tablica[i].jakiKolor);
            printf("wyposazenie: %d\n", tablica[i].jakieWyposazenie);
        }
        break;



    case 3: //najlzejszy
        system("cls");
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (tablica[j].waga > tablica[j + 1].waga)
                    swap(tablica, j);
            }
        }

        for (i = 0; i < 10; i++)
        {
            printf("Waga: %d, ", tablica[i].waga);
            printf("cena: %d, ", tablica[i].cena);
            printf("kolor: %d, ", tablica[i].jakiKolor);
            printf("wyposazenie: %d\n", tablica[i].jakieWyposazenie);
        }
        break;



    case 4: // najciezszysrand(time(NULL));
        system("cls");
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (tablica[j].waga < tablica[j + 1].waga)
                    swap(tablica, j);
            }
        }

        for (i = 0; i < 10; i++)
        {
            printf("Waga: %d, ", tablica[i].waga);
            printf("cena: %d, ", tablica[i].cena);
            printf("kolor: %d, ", tablica[i].jakiKolor);
            printf("wyposazenie: %d\n", tablica[i].jakieWyposazenie);
        }
        break;



    case 5: //wg koloru
        system("cls");
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (tablica[j].jakiKolor < tablica[j + 1].jakiKolor)
                    swap(tablica, j);
            }
        }

        for (i = 0; i < 10; i++)
        {
            printf("kolor: %d, ", tablica[i].jakiKolor);
            printf("Waga: %d, ", tablica[i].waga);
            printf("cena: %d, ", tablica[i].cena);
            printf("wyposazenie: %d\n", tablica[i].jakieWyposazenie);
        }
        break;



    case 6://wg wyposazenia
        system("cls");
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (tablica[j].jakieWyposazenie < tablica[j + 1].jakieWyposazenie)
                    swap(tablica, j);
            }
        }

        for (i = 0; i < 10; i++)
        {
            printf("wyposazenie: %d, ", tablica[i].jakieWyposazenie);
            printf("Waga: %d, ", tablica[i].waga);
            printf("cena: %d, ", tablica[i].cena);
            printf("kolor: %d\n", tablica[i].jakiKolor);
        }
        break;



    default:
        system("cls");
        printf("\n\n!!!! Cos nie tak, jeszcze raz: !!!!");
        break;
    }
}
