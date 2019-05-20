/*

IŠ ORO 0 ATSIRANDA PO PATIEKALAIS 

*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct duomenys {
    string patiekalas;
    int produktai[10];
    int kaina;
};
duomenys duom[12];

int prod_kaina(int kainos[], int produktai[], int kelintas, int sk) {
    /*
        Apskaičiuoja vieno produkto kaina
    */
    int kaina = 0;
    for(int i=0; i<sk; i++) {
        kaina += kainos[i] * produktai[i];
    }
    duom[kelintas].kaina = kaina;
    return kaina;
}

int svec_kaina(duomenys data[], int sk) {
    /*
        Apskaičiuoja vieno svečio pietų kainą
    */
    int kaina=0;
    for(int i=0;i<sk; i++) {
        kaina += data[i].kaina;
    }

    return kaina;
}

int main() {
    ifstream fin;
    fin.open("U2.txt");
    ofstream fout;
    fout.open("U2Rez.txt");
    int n,p;
    fin >> n >> p;


    int kainos[n];

    for(int i=0; i<n; i++) {
        fin >> kainos[i];
    }

    fin.get();
    char raides[15];

    for(int j=0; j<p; j++) {
        fin.get(raides, 15);
        duom[j].patiekalas = raides;
        for(int e=0; e<n; e++) {
            fin >> duom[j].produktai[e];
        }

        fin.get();
        fin.get(); //wtf kodel 2 reikia
    }
    fin.close();
    for(int f=0; f<n; f++) {
        cout << duom[f].patiekalas << prod_kaina(kainos, duom[f].produktai, f, n) << endl;
    }

    int centai = svec_kaina(duom, n);
    int litai = centai/100;
    cout << litai << " " << centai - litai*100;

    fout.close();
    return 0;
}
