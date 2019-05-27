#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    struct duomenys {
        int x;
        int y;
        int plotis;
        int ilgis;
        int r;
        int g;
        int b;
    };
    struct koordinates {
        int r = 255;
        int g = 255;
        int b = 255;
    };
    koordinates koord[100][100]; // atitinka koord[x][y]
    ifstream fin;
    fin.open("U2.txt");
    int sk;
    fin >> sk;
    duomenys duom[100];
    int max_a = 0, max_b = 0;
    for(int i=0; i<sk; i++) {
        fin >> duom[i].x >> duom[i].y >> duom[i].plotis >> duom[i].ilgis >> duom[i].r >> duom[i].g >> duom[i].b;
        if(duom[i].x + duom[i].plotis > max_b) {
            max_b = duom[i].x + duom[i].plotis;
        }
        if(duom[i].y + duom[i].ilgis > max_a) {
            max_a = duom[i].y = duom[i].ilgis;
        }
    }
    cout << max_a << " " << max_b << endl;
    /*
        -- FORMATAS --
    koord[0][0].r = duom[0].r;
    koord[0][0].g = duom[0].g;
    koord[0][0].b = duom[0].b;  
    
    */
    for(int j = 0; j<sk; j++) {
        for(int k = duom[j].x; k<=duom[j].plotis; k++) {
            for(int l=duom[j].y; l<=duom[j].ilgis; l++) {
                koord[k][l].r = duom[j].r;
                koord[k][l].g = duom[j].g;
                koord[k][l].b = duom[j].b;
                cout << "koord["<<k<<"]["<<l<<"].rgb = " << duom[j].r <<" "<< duom[j].g<<" " << duom[j].b<<endl;
            }
            
        }
    }

    for(int f=0; f<2; f++) {
        for(int g=0; g<2; g++) {
            cout << "koord: " << f<< " " << g << " -- " << koord[f][g].r << " " << koord[f][g].g << " " << koord[f][g].b << endl;
        }
        
    }

    
    
    return 0;
}
