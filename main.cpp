//
// Created by victo on 20.2.2026.
//
#include "main.h"
#include "functions.h"

using namespace std;

int main()
{
    printLogo();

    // Alustetaan merkkijono haku, jossa haetaan isommasta teksti kasasta tiettya merkkirivia

    string text, searchWord;

    // Kysytaan lause/teksti
    cout << "Give a string from which to search for:  ";
    getline(cin,text);

    // Kysytaan tarkentava haku mita tekstista halutaan etsia
    cout << "Give search string:  ";
    getline(cin, searchWord);

    // Haetaan merkkijonon sijainti tekstista
    size_t pos = text.find(searchWord);

    // tarkistetaan onko merkkijono tekstissä. Jos text.find ei loyda merkkijonoa
    // se ei palauta normaalia 1 2 3 4 sijaintia vaan Npos, joka on todella iso luku -> -1
    if (pos != string::npos)
    {
        cout << "\"" << searchWord << "\" found in \"" << text << "\" in position " << pos << "\n";
    }
    else
    {
        cout << "\"" << searchWord << "\" NOT found in \"" << text << "\" \n\n";
    }


    return 0;
}