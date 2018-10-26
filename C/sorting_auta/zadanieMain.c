#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "zadanie.h"

int main()
{

    srand(time(NULL));
    Samochod *tab = malloc(10*sizeof(Samochod));
    int i = 0, wybor = 0;

    printf("\nLosuj liczbe: %d\n\n0", losuj_liczbe(9,10));

    for (i = 0; i < 10; i++) //
    {
        tab[i].waga = losuj_liczbe(500, 1500);
        tab[i].cena = losuj_liczbe(20000, 30000);
        tab[i].jakiKolor = (kolor)losuj_liczbe(0, 4);
        tab[i].jakieWyposazenie = (wyposazenie)losuj_liczbe(0, 3);

        printf("Waga: %d, ", tab[i].waga);
        printf("cena: %d, ", tab[i].cena);
        printf("kolor: %d, ", tab[i].jakiKolor);
        printf("wyposazenie: %d\n", tab[i].jakieWyposazenie);
    }

    do
    {
        printf("\n\nWyposazenie: 0 = Podstawowe, 1 = Standard, 2 = Premium\n");
        printf("Kolor: 0 = Bialy, 1 = Czarny, 2 = Czerwony, 3 = Niebieski\n");
        printf("\n1: Najnizsza cena\n");
        printf("2: Najwyzsza cena\n");
        printf("3: Najlzejszy\n");
        printf("4: Najciezszy\n");
        printf("5: Wg koloru\n");
        printf("6: Wg wyposazenia\n");
        printf("0: KONIEC\n");
        printf("Wybierz: ");
        scanf("%d", &wybor);

        sortuj_samochody(wybor, tab);

    }
    while (1);

    free(tab);
    return 0;
}
