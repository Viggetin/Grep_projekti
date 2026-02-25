//
// Created by victo on 20.2.2026.
//

#include "main.h"
using namespace std;

/*  Ohjelman logo & tekijatiedot
 *  ---------------------------------------------------
*   Funktio yksinkertaisesti kutsuttaessa tekee Cout:in avulla ASCII logon
*   Myös lisaa tekijan nimen
*
*   Tama on palautuksessa kommentoitu
*/

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

/* Ensimmäinnen Inkrementin- Toiminnallisuus
 *---------------------------------------------------
 * Funktio suorittaa vaaditut ensimmainsen inkrementint toiminnot
 *
 * Funktio siis toimii, kun ohjelmaa ajetaan suoraan joko .exe tiedostosta tai komentorivilta ./Grep
 * Ohjelma kysyy kayttajalta tekstin, josta kayttaja voi etsia tietyn merkkijonon.
 */

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

/* Toisen Inkrementin- Toiminnallisuus
 *---------------------------------------------------
 * Funktio suorittaa toisen inkrementin vaaditut toiminnot.
 *
 * Funktio aloitetaan tiedoston avaamisella, josta tarkistetaan heti avautuuko tiedosto oikein.
 * Tassa tapauksessa poikkeuskasittely toimii, jos mainittua tiedostoa ei ole olemassa.
 * Jos tiedosto avataan onnistuneesti sen koko mitataan ja tallennetaan size muuttujaan.
 *
 * Ohjelma jatkaa tasta tallentamalla hakusanan komentorivin argumentista ja tarkistaa koko tekstin rivi rivilta
 * , kun vastaava hakusana tulee niin se tulostaa koko merkkijonon rivivaihtoon saakka. Lopuksi tiedosto suljetaan
 */

void InkrementtiKaks(char *argv[])
{
    ifstream fileText(argv[2], ios::binary);
    if (!fileText.is_open())
    {
        cout << "An exception occurred. Exception Nr. -1" << "\n";
        cout << "Could not find out the size of file \"" << argv[2] << "\"" << "\n";
        return;
    }
    else
    {
        fileText.seekg(0, ios::end);        // siirry tiedoston loppuun
        streampos size = fileText.tellg();  // tiedoston koko tavuina
        fileText.seekg(0, ios::beg);        // takaisin alkuun
    }


    string searchWord;
    string line;



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
            cout << line << "\n";
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


/* Kolmannen ja neljannen Inkrementin- Toiminnallisuus
 * ---------------------------------------------------
 * Funktio suorittaa kolmannen ja neljannen inkrementin toiminnallisuudet.
 *
 * Funktio aloittaa samanlaisella tiedoston tarkistuksella mita toisessa inkrementissa.
 * Toiminnallisuus tuli molempiin neljannen inkrementin aikana.
 *
 * Funktio siis perustuu samaan logiikkaan mita toinen inkrementti mutta tassa kayttajalla on
 * ominaisuutena hakea tiedostosta enemman informaatiota. Vaihtoehdot tulevat lisatyista argumenteista
 * , jotka alkavat "-o" komennon jalkeen vaihtoehtoina on siis
 *
 * -l naytetaan tiedoston rivinumerot 1:sta eteenpain tiedoston loppuun saakka
 * -o annetaan ilmenneiden hakusanojen lukumaara lopussa
 * -r haetaan tiedostosta merkkijonot, joissa ei ilmene hakusanaa
 * -i Ei huomioida isoja kirjaimia
 */

void inkrementtiKolme(char *argv[])
{
    // Tiedoston tarkistus -> inkrementti 4
    //Avataan tekstitiedosto ja tarkistetaan onko se auki -> Jos ei niin virheilmoitus ja return
    ifstream fileText(argv[3], ios::binary);
    if (!fileText.is_open())
    {
        cout << "An exception occurred. Exception Nr. -1" << "\n";
        cout << "Could not find out the size of file \"" << argv[3] << "\"" << "\n";
        return;
    }
    fileText.seekg(0, ios::end);
    streampos size = fileText.tellg();
    fileText.seekg(0, ios::beg);


    string searchWord;      // Kayttajan hakusana
    string inputSearchWord; // Kayttajan alkup. hakusana, jos ei huomioida isoja kirjaimia
    string line;            // Rivimuuttuja
    string options;         // Argumentti optioiden tallennus

    // Argumenttien boolean muuttujat --> tarkistetaan onko kaytossa
    bool showLineNumbers = false;
    bool showOccurrences = false;
    bool reverseSearch = false;



    // Argumenttien ja hakusanan hakeminen komennosta
    options = argv[1];
    searchWord = argv[2];


    // Rivinumerointi
    if (options.find('l') != string::npos)
    {
        showLineNumbers = true;
    }
    // Hakusana laskuri + tarkistaa o kirjaimen "-o" jalkeen
    if (options.find('o', 2) != string::npos)
    {
        showOccurrences = true;
    }
    // Kaanteinen haku -> haetaan rivit, jossa ei esiinny hakusana
    if (options.find('r') != string::npos)
    {
        reverseSearch = true;
    }
    // Ei huomioida isoja kirjaimia
    if (options.find('i') != string::npos)
    {
        inputSearchWord = searchWord;
        string nonCaseSearchWord = searchWord; // tätä käytetään haussa

        // Kaydaan koko hakusana lapi ja muutetaan kirjaimet pieneksi
        for (int i = 0; i < nonCaseSearchWord.length(); i++)
        {
            nonCaseSearchWord[i] = tolower(nonCaseSearchWord[i]);
        }

        searchWord = nonCaseSearchWord;
    }

    // Rivi- ja sanalaskurien alustus
    int lineCounter = 1;
    int wordCount = 0;

    // Tiedoston sisallon lapikaynti
    while (getline(fileText, line))
    {
        // Hakusanan etsiminen, jos ei tehda kaanteista hakua
        if ((line.find(searchWord) != string::npos) && reverseSearch == false)
        {
            if (showLineNumbers)
            {
                cout<< lineCounter << ": " <<  line << "\n";
            }
            else
            {
                cout << line << "\n";
            }
            wordCount++;
        }
        // tulostetaan vain rivit joissa hakusanaa EI esiinny jos kaanteinen haku on asetettu paalle
        else if ((line.find(searchWord) == string::npos) && reverseSearch == true)
        {
            cout<< lineCounter << ": " <<  line << "\n";
            wordCount++;
        }
        lineCounter++;
    }
    // Esitetaan lopulliset tulokset joko normihausta tai kaanteisesta hausta
    if (showOccurrences && reverseSearch == false)
    {
        cout <<"\n" <<"Occurrences of lines containing " << "\"" << searchWord << "\": " << wordCount << "\n";
    }
    else if (showOccurrences && reverseSearch == true)
    {

        cout <<"\n" <<"Occurrences of lines NOT containing " << "\"" << inputSearchWord << "\": " << wordCount << "\n";
    }

    fileText.close();
}

