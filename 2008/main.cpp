#include <iostream>
#include <fstream>
using namespace std;
struct duomenys {
    string pavadinimas;
    int msk;
    int mnr[100];
};
duomenys duom[100];
int marsrutai[100] = {0};
int stoteles[100] = {0};
void nuskaitymas() {
    ifstream fin;
    fin.open("U2.txt");
    int sk;
    fin >> sk;
    fin.get();
    char raide[100];
    for(int i = 0; i<sk; i++) {
        fin.get(raide, 20);
        duom[i].pavadinimas = raide;
        fin >> duom[i].msk;
        for(int j = 0; j < duom[i].msk; j++) {
            fin >> duom[i].mnr[j];
            marsrutai[duom[i].mnr[j]] += duom[i].msk;
            stoteles[duom[i].mnr[j]]++;
        }
        fin.get();
    }
    fin.close();
}

int didziausias(int mars[100], int stot[100]) {
    int didz_mars = mars[0];
    int didz_stot = stot[0];
    int didzi;
    for(int i = 0; i<100; i++) {
        if(mars[i] >= didz_mars && stot[i] > didz_stot) {
            didz_mars = mars[i];
            didz_stot = stot[i];
            didzi = i;
        }
    }
    return didzi;
}

void stoteliuPav(int sk) {
    ofstream fout;
    fout.open("U2rez.txt");
    fout << sk << endl; // sita reiktu spausdint main() turbut
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < duom[i].msk; j++) {
            if(sk == duom[i].mnr[j]) {
                fout << duom[i].pavadinimas << endl;
            }
        }
    }
    fout.close();
}

int main() {
    nuskaitymas();
    stoteliuPav(didziausias(marsrutai, stoteles)); //nezinau ar gerai taip turbut ne bet nesvarbu
    return 0;
}
