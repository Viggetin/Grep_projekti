//
// Created by victo on 20.2.2026.
//

#ifndef GREP_FUNCTIONS_H
#define GREP_FUNCTIONS_H
using namespace std;

void printLogo()
{
    cout << "   _____                  _____           _      _    _   _ \n";
    cout << "  / ____|                |  __ \\         (_)    | |  | | (_)\n";
    cout << " | |  __ _ __ ___ _ __   | |__) | __ ___  _  ___| | _| |_ _ \n";
    cout << " | | |_ | '__/ _ \\ '_ \\  |  ___/ '__/ _ \\| |/ _ \\ |/ / __| |\n";
    cout << " | |__| | | |  __/ |_) | | |   | | | (_) | |  __/   <| |_| |\n";
    cout << "  \\_____|_|  \\___| .__/  |_|   |_|  \\___/| |\\___|_|\\_\\__|_|\n";
    cout << "                 | |                    _/ |                \n";
    cout << "                 |_|                   |__/                 \n";
    cout << "\n" << " Grep-projekti 2026 kevat"<< " \n";
    cout << " (C) Victor Sten "<< " \n\n";
}

/* Ensimmäinnen Inkrementtin- Toiminnallisuus */

void InkrementtiYks()
{
    // Alustetaan merkkijono haku, jossa haetaan isommasta teksti kasasta tiettya merkkirivia
    string text, searchWord;

    // Kysytaan lause/teksti
    cout << "\n" << "Give a string from which to search for: ";
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

/* Toisen Inkrementtin- Toiminnallisuus */

void InkrementtiKaks(char *argv[])
{
    // Tiedoston avaus ja tarkistus onnistuiko se
    ifstream fileText(argv[2]);

    string searchWord;
    string line;

    if (!fileText.is_open())
    {
        cout << "Can't open the file" << "\n";

    }
    // Debuggausta varten
    //cout << "Tiedosto: " << argv[2] << "\n";
    //cout << "Hakusana: " << argv[1] << "\n";
    //cout << "Tiedosto auki: " << fileText.is_open() << "\n";

    searchWord = argv[1];
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


#endif //GREP_FUNCTIONS_H