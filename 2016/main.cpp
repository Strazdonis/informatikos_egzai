#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct duomenys {
    string pratimas;
    int kartai;
};
duomenys duom[100];

void rikiavimas(int sk) {
    duomenys temp;
    for(int i=0; i<sk; i++) {
        for(int j=0; j<sk; j++) {
            if(duom[i].kartai > duom[j].kartai) {
                temp = duom[j];
                duom[j] = duom[i];
                duom[i] = temp;
            }
        }
    }
}



int main() {
    ifstream fin;
    fin.open("U2.txt");
    int sk,kartai, skirtingu=0;
    fin >> sk;
    fin.get();
    char pr[20];
    
    bool buvo = false;
    for(int i=0; i<sk; i++) {
        fin.get(pr, 20);
        fin.get();
        fin >> kartai;
        for(int j=0; j<i; j++) {
            if(duom[j].pratimas == pr) {
                buvo = true;
                duom[j].kartai += kartai;
            }
        }
        if(!buvo) {
            skirtingu++; // skaiciuoja kiek is viso skirtingu pratimu
            duom[i].pratimas = pr;
            duom[i].kartai = kartai;
        }
        fin.get();
    }


    rikiavimas(skirtingu);


    for(int e=0; e<skirtingu; e++) {
        cout << duom[e].pratimas << " " << duom[e].kartai << endl;
    }


    return 0;
}
