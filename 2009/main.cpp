#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct duomenys {
    string vardas;
    int minutes;
    int sekundes;
    int laikas; //is viso laiko sekundemis
};

duomenys duom[100][50]; //ideal butu viska su vienamaciu masyvu bet jau tyngiu
duomenys like[50];

void did_rusiavimas(duomenys data[100][50], int sk, int sport[]) {
duomenys temp;
    for(int i=0; i<sk; i++) {
        for(int j=0;j<sport[i];j++) {
            for(int e=0; e<sport[i]; e++) {
                if(data[i][j].laikas<data[i][e].laikas) {
                    temp=data[i][j];
                    data[i][j]=data[i][e];
                    data[i][e]=temp;
                }
            }
        }
    }
}

void maz_rusiavimas(duomenys data[50], int sk) {
duomenys temp;
    for(int i=0; i<sk; i++) {
        for(int j=0; j<i+1; j++) {
            if(like[i].laikas<like[j].laikas) {
                temp=data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }
    }

}


void spausdinimas(duomenys data[100], int sk) {
    for(int i=0; i<sk; i++) {
       cout << data[i].vardas << " " << data[i].minutes << " " << data[i].sekundes << endl;
    }
}

int main() {
    ifstream fin;
    fin.open("U2.txt");
    int k;
    fin>>k;
    int sport[k];
    int nsport[k];
    char a[20];
    fin.get();
    for(int i=0;i<k; i++) {
        fin>>sport[i];
        fin.get();
        for(int j=0; j<sport[i]; j++) {
            fin.get(a, 20);
            duom[i][j].vardas=a;
            fin>>duom[i][j].minutes >> duom[i][j].sekundes;
            duom[i][j].laikas = duom[i][j].minutes*60 + duom[i][j].sekundes;
            fin.get();
        }
    }
    fin.close();
    did_rusiavimas(duom, k, sport);
    int skaiciuotuvas=0;
    for(int f=0; f<k; f++) {
        for(int b=0; b<sport[f]/2; b++) {
            like[skaiciuotuvas++] = duom[f][b];
        }
    }
    maz_rusiavimas(like, skaiciuotuvas);
    spausdinimas(like, skaiciuotuvas);
    return 0;
}
