#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int n; // jei duomenys skaitomi funkcijoje nera kaip prieiti, laikant strukturoje ir rusiuojant susinaikina nebent priskirti kiekvienam indexui (waste of resources)
int k; // jei duomenys skaitomi funkcijoje nera kaip prieiti, laikant strukturoje ir rusiuojant susinaikina nebent priskirti kiekvienam indexui (waste of resources)
struct duomenys {
    string vardai;
    int technika[10]; //nes max 10 teiseju
    int artist[10]; //nes max 10 teiseju
    int balu_suma = 0;
};
duomenys duom[300]; // max 100 sokeju, vienam 3 eilutes

void nuskaitymas() {
    ifstream fin;
    fin.open("U2.txt");
    fin>>n>>k;
    fin.get();
    char raides[20];
    for(int i=0;i<n; i++) {
        fin.get(raides, 20);
        duom[i].vardai = raides;
        fin.get();
        for(int j=0; j<k; j++) {
            fin >> duom[i].technika[j];
        }
        fin.get();
        for(int e=0; e<k; e++) {
            fin >> duom[i].artist[e];
        }
        fin.get();
    }

    fin.close();
}

int balai(int balai[10]) {
    int didz=balai[0]; 
    int maz=balai[0]; 
    int suma=0;
    for(int i=0; i<k; i++) {
        if(balai[i] > didz) {
            didz = balai[i];
        } else if(balai[i] < maz) {
            maz = balai[i];
        }
        suma+= balai[i];
    }
    return suma - (didz + maz); // atimant maziausia ir didziausia balus
}

void rikiavimas() {
    duomenys temp;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(duom[i].balu_suma > duom[j].balu_suma && duom[j].balu_suma != 0) { // kazkoks genijus nusprende kad jei toks pats vardas tai ta pati sokeja tai pilna 0 xd
                temp = duom[i];
                duom[i] = duom[j];
                duom[j] = temp;
            }
        }
    }
}


int main() {
    nuskaitymas();
    for(int i=0; i<n; i++) { //skaiciuojami balai
        duom[i].balu_suma += balai(duom[i].technika);
        duom[i].balu_suma += balai(duom[i].artist);
    }
    rikiavimas();
    for(int j=0; j<n; j++) {
        if(duom[j].balu_suma != 0) {  // kazkoks genijus nusprende kad jei toks pats vardas tai ta pati sokeja tai pilna 0 xd
            cout << duom[j].vardai << " " << duom[j].balu_suma << endl;
        }
    }
    return 0;
}
