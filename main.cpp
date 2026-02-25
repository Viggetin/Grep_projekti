//
// Created by victo on 20.2.2026.
//

// Sisallytetaan muut headeri tiedostot
#include "main.h"
#include "functions.cpp"

using namespace std;

int main(int argc, char *argv[])
{

    //printLogo();

    // Alustetaan if lauseella eri argc arvot
    // Argc = 1 -> Merkkijonon etsiminen kayttajan tekstista
    // Argc = 3 --> Merkkijonon etsiminen tiedostosta
    // Argc = 4 --> Merkkijonon etsiminen tiedostosta + Optiot (-o)

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
    else
    {
       cout << "Invalid number of arguments" << "\n";
    }

    return 0;
}