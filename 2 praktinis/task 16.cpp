/*Užduotis „Mokinių pažymių sistema“

Tikslas:

Sukurti C++ programą, kuri leidžia vartotojui:

    Įvesti mokinių vardus ir jų pažymius.
    Peržiūrėti visų mokinių arba konkretaus mokinio pažymius.
    Atnaujinti konkretų pažymį konkrečiam mokiniui.
    Pašalinti mokinį iš sąrašo.

Reikalavimai:

    Naudoti du masyvus: vienmatis masyvas skirtas mokinių vardams saugoti,
    dvimatis masyvas skirtas pažymiams: eilutės – mokiniai, stulpeliai – pažymiai.
    Leisti į masyvą įvesti iki 100 mokinių, kiekvienas iš jų gali turėti iki 10 pažymių.
    Naudoti ciklus ir sąlyginius sakinius duomenų valdymui.
    Sukurti paprastą meniu, leidžiantį vartotojui pasirinkti veiksmą.
*/

#include <iostream>
#include <string>
#include <format>
#include <iomanip>
using namespace std;

void tbl(int _tekstoIlgis, string _text, int _ilgisLenget, int _eilutesNum, int _kitaEilute) {
    int i,l;

    if (_kitaEilute == -1) {
        for (l=1;l<=3;l++) {
            if (l==1 || l==3) {
                for (i=0;i<=_tekstoIlgis+6;i++) {
                    cout<<"=";
                }
                cout<<endl;
            } else {
                cout<<"|  "<<setw(_tekstoIlgis)<<_text<<"   |"<<endl;
            }
        }
    }

    if (_kitaEilute > -1) {
        if (_eilutesNum==1 || _eilutesNum==3 || _eilutesNum==_ilgisLenget) {
            for (i=0;i<=_tekstoIlgis+6;i++) {
                cout<<"=";
            }
            cout<<endl;
        } else {
            if (_kitaEilute == 1) {
                cout<<"|  "<<setw(_tekstoIlgis)<<_text<<"   |";
            } else {
                cout<<"|  "<<setw(_tekstoIlgis)<<_text<<"   |";
                cout<<endl;
            }
        }
    }
}

int task16() {
    while (true) {

        // --Masyvai--
        string MV[100]; // mokyniu Varbu ir Pavardziu masyvai
        int PZ[100][10]={0}; //pazymiu masyvas
        string dalykai[10] =
            {
            "Matematika", "Fizika", "Programavimas", "Biologija", "Kuno kultura",
            "Geografija", "Istorija", "Gimtoji kalba", "Anglu kalba", "Dorinis ugdymas"
            };

        int m,p,kt; // m - mokyniu index`as <> p - pazymiu index`as <> kt - keisti arba trinti index`as
        int i,j,l;
        int _tekstoIlgis; // Teksto ilgis

        string _text;

        // --- Startas ---
        _text="Mokiniu pazymiu sistema";
        _tekstoIlgis=_text.length();
        tbl(_tekstoIlgis,_text,1,1,-1);

        //---Meniu---

         string MS[] = {
             "Pasirinkite norima operacija:",
             "Ivesti mokiniu vardus ir ju pazymius - 1 ",
             "Perziureti visu mokiniu pazymius - 2 ",
             "Perziureti mokinio pazymius - 3 ",
             "Atnaujinti moyknio pazymi - 4 ",
             "Pasalinti mokini is saraso - 5 "
         };

         int menuPasir = 6; // Meniu pasirinkimas
         int menuLines = menuPasir + 3; // Meniu eiluciu kiekis
        _tekstoIlgis = 0;
        for (i=0;i<menuPasir;i++) {
            if (_tekstoIlgis<MS[i].length()) {
                _tekstoIlgis = MS[i].length(); // Tikrinam ilgiausia teksta
            }
        }

        for (l=1;l<=menuLines;l++) {
            if (l == 1 || l == 3 || l == menuLines) {
                    tbl(_tekstoIlgis,"=",menuLines,l,1);
                } else if ( l == 2) {
                    tbl(_tekstoIlgis,MS[l-2],menuLines,l,0);
                } else if (l > 3) {
                    tbl(_tekstoIlgis,MS[l-3],menuLines,l,0);
            }
        }



        //---Pazymiu Lentele---
        cout<<endl;
        cout<<"--"<<endl;
        return 0;
    }
}