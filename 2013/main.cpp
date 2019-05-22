#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main() {

    struct miestas {
        string pavadinimas;
        string apskritis;
        int gyventojai = 0;
    };
    struct apskritis {
        string pavadinimas;
        int gyventojai = 0;
        int maz_gyventoju = 600001; // daugiau nei nurodytas didziausias gyventoju sk (n (100 <= n <= 600000))
        int kiekis = 0;

    };
    miestas miestai[103];
    apskritis apskritys[103];
    int sk, gyv;
    ifstream fin;
    fin.open("U2.txt");
    fin >> sk;
    fin.get();
    char mst[20];
    char aps[13];
    for(int i=0; i<sk; i++) {
        fin.get(mst, 20);
        miestai[i].pavadinimas = mst;
        fin.get(aps, 13);
        miestai[i].apskritis = aps;
        fin>>gyv;
        miestai[i].gyventojai += gyv;
        fin.get();
    }
    fin.close(); // informacijos nebereiks skaityti

    for(int j=0; j<sk; j++) {
        bool buvo = false;
        for(int e=0; e<apskritys[0].kiekis; e++) {
            if(apskritys[e].pavadinimas == miestai[j].apskritis) { // jei tokia apskritis jau zinoma tik prideti gyventoju
                buvo = true;
                apskritys[e].gyventojai += miestai[j].gyventojai;
                if(apskritys[e].maz_gyventoju > miestai[j].gyventojai) { // atrenkamas maziausias miestas is apskirties
                    apskritys[e].maz_gyventoju = miestai[j].gyventojai;
                }
            }
        }
        if(buvo == false) { // jei tokios apskrities dar nebuvo - prideti gyventoju ir isiminti apskriti
            apskritys[apskritys[0].kiekis].pavadinimas = miestai[j].apskritis;
            apskritys[apskritys[0].kiekis++].gyventojai += miestai[j].gyventojai;
        }
    }

    int kiekis = apskritys[0].kiekis; // perrusiojant apskritys[0].kiekis persikels, tad reikia isiminti
    apskritis temp; // laikina struktura rusiavimui

    for(int g=0; g<kiekis; g++) {
        for(int n=0; n<kiekis; n++) {
            if(apskritys[g].maz_gyventoju < apskritys[n].maz_gyventoju || (apskritys[g].maz_gyventoju == apskritys[n].maz_gyventoju && apskritys[g].pavadinimas < apskritys[n].pavadinimas)) { // pirma dalis - rusiavimas pagal maziausia gyv. skaiciu, antra dalis (skliaustose) - jei maz. gyv. tiek pat, rusiavimas pagal abecele
                temp = apskritys[g];
                apskritys[g] = apskritys[n];
                apskritys[n] = temp;
            }
        }
    }

    for(int f=0; f<kiekis; f++) {
        cout << "--" << apskritys[f].pavadinimas << " " << apskritys[f].maz_gyventoju << " " << apskritys[f].gyventojai << endl; // informacijos spausdinimas
    }

    return 0;
}
