#ifndef ZADANIE_H_
#define ZADANIE_H_

typedef enum kolor kolor;
typedef enum wyposazenie wyposazenie;
typedef struct Samochod Samochod;

int losuj_liczbe(int minim, int maxim);
void swap(Samochod *tab, int poz);
void sortuj_samochody(int wybor, Samochod *tablica);

enum kolor
{
    KO_BIALY = 0,
    KO_CZARNY,
    KO_CZERWONY,
    KO_NIEBIESKI
};

enum wyposazenie
{
    WY_PODSTAWOWE = 0,
    WY_STANDARD,
    WY_PREMIUM
};

struct Samochod
{
    int waga, cena;
    kolor jakiKolor;
    wyposazenie jakieWyposazenie;
};


#endif // ZADANIE_H_
