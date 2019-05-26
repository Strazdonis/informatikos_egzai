#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct duomenys {
    string vardas;
    char dnr[21];
    int koeficientas;
};

duomenys duom[21];
int n, m, nr;
string vardas;

void nuskaitymas() {
    ifstream fin;
    fin.open("U2.txt");
    fin >> n >> m >> nr;
    fin.get();
    char vard[12];
    char dnr[21];
    for(int i=0; i<n; i++) {
        fin.get(vard, 12);
        duom[i].vardas = vard; 
        fin.get(dnr, m+1);
        for(int j=0; j<m; j++) {
            duom[i].dnr[j] = dnr[j];
        }
        duom[i].koeficientas = 0;
        fin.get();
    }
    vardas = duom[nr].vardas;
}

int koef_skaic(int avis, int sk) {
    for(int i=0; i<m; i++) {
        if(duom[sk].dnr[i] == duom[avis].dnr[i]) {
            duom[sk].koeficientas++;
        }
    }
    return duom[sk].koeficientas;
}

void rikiavimas() {
    duomenys temp;
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            if(duom[i].koeficientas > duom[j].koeficientas || (duom[i].koeficientas == duom[j].koeficientas && duom[i].vardas < duom[j].vardas)) {
                temp = duom[i];
                duom[i] = duom[j];
                duom[j] = temp;
            }
            
        }
    }
}


void spausdinimas() {
    cout << vardas << endl;
    for(int i=0; i<m; i++) {
        if(duom[i].koeficientas > 0) {
            cout << duom[i].vardas << " " << duom[i].koeficientas << endl;
        }
    }
}



int main() {
    nuskaitymas();
    nr-=1; // kad butu patogiau naudoti masyve
    for(int i=0; i<m; i++) {
        if(i != nr) {
            koef_skaic(nr, i);
        }
    }
    rikiavimas();
    spausdinimas();
    return 0;
}
