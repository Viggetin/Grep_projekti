//
// Created by victo on 20.2.2026.
//
#include "main.h"
#include "functions.h"

using namespace std;

int main(int argc, char *argv[])
{

    printLogo();

    // Alustetaan if lauseella eri argc arvot
    // Argc = 1 -> Merkkijonon etsiminen tekstista
    // Argc = 3 --> Merkkijonon etsiminen tiedostosta?

    if (argc == 1)
    {
        InkrementtiYks();
    }
    else if (argc == 3)
    {
        InkrementtiKaks(argv);
    }
    else if (argc == 4)
    {
        inkrementtiKolme(argv);
    }

    return 0;
}