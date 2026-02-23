//
// Created by victo on 20.2.2026.
//
#include "main.h"
#include "functions.h"

using namespace std;

int main(int argc, char *argv[])
{

    //printLogo();

    // Alustetaan merkkijono haku, jossa haetaan isommasta teksti kasasta tiettya merkkirivia
    string text, searchWord;

    // Alustetaan if lauseella eri argc arvot
    // Argc = 1 -> Merkkijonon etsiminen tekstista
    // Argc = 3 --> Merkkijonon etsiminen tiedostosta?

    if (argc == 1)
    {
        // Kysytaan lause/teksti
        cout << "Give a string from which to search for: ";
        getline(cin,text);

        // Kysytaan tarkentava haku mita tekstista halutaan etsia
        cout << "Give search string: ";
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
    }
    else if (argc == 3)
    {
        // Tiedoston avaus ja tarkistus onnistuiko se
        ifstream fileText(argv[2]);
        if (!fileText.is_open())
        {
            cout << "Can't open the file" << "\n";
            return 0;
        }
        // Debuggausta varten
        //cout << "Tiedosto: " << argv[2] << "\n";
        //cout << "Hakusana: " << argv[1] << "\n";
        //cout << "Tiedosto auki: " << fileText.is_open() << "\n";

        searchWord = argv[1];
        string line;
        int count = 0;

        // Tarkistetaan koko teksti rivi rivilta ja jos hakusana tulee vastaan
        // niin sen koko rivi tulostetaan tekstina
        while (getline(fileText, line) )
        {
            // Ehto toteutuu jos haetulla sanalla on sijainti teksissa
            if (line.find(searchWord) != string::npos)
            {
                cout << line << endl;
                count++;
            }
        }
        // Annetaan ilmoitus jos osumia ei tullut
        if (count == 0)
        {
            cout << "\n" << "No sentences found with your searchword" << "\n";
        }

        // suljetaan tiedosto
        fileText.close();

    }

    return 0;
}