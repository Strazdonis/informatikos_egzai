#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct duomenys {
    string vardas;
    int taskai[10];
    int lyginiu = 0;
    int rezultatas = 0;
};
int n, k;
duomenys duom[51];
void nuskaitymas() {
    ifstream fin;
    fin.open("U2.txt");
    fin >> n >> k;

    char raides[10];
    fin.get();
    for(int i=0; i<n; i++) {
        fin.get(raides, 10);
        fin.get();
        duom[i].vardas = raides;
        for(int j=0; j<k; j++) {
            fin >> duom[i].taskai[j];
            if(duom[i].taskai[j] % 2 == 0) {
                duom[i].lyginiu++;
                duom[i].rezultatas+=duom[i].taskai[j];
            } else {
                duom[i].rezultatas-=duom[i].taskai[j];
            }
        }
        fin.get();
    }
    fin.close();
}

int valdovas() {
    int didz=duom[0].rezultatas;
    int lyg=duom[0].lyginiu;
    int index=0;
    for(int i=0; i<n; i++) {
        if(duom[i].rezultatas > didz) {
            didz = duom[i].rezultatas;
            lyg = duom[i].lyginiu;
            index = i;
        } else if(duom[i].rezultatas == didz && duom[i].lyginiu > lyg) { // jei tasku tiek pat laimi su daugiau lyginiu
            didz = duom[i].rezultatas;
            index = i;
        }
    }
    return index; // grazina valdovo numeri strukturoje
}



int main() {


    nuskaitymas();
    int index = valdovas();
    cout << duom[index].vardas << " " << duom[index].rezultatas;
    return 0;
}
