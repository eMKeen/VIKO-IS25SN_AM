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
#include <iterator>
using namespace std;

int ilgiausiaiTekstas(string _tekstoMasyvas[],int n);
void tbl(int _tekstoIlgis, string _text, int _ilgisLenget, int _eilutesNum, int _kitaEilute);


int task16() {
    // --Masyvai ir kiti--
    string MV[100]; // mokyniu Vardu ir Pavardziu masyvai
    int _uzmt = 0;// index`o uzimtumas
    int PZ[100][10]={0}; //pazymiu masyvas
    string dalykai[10] =
    {
        "Matematika", "Fizika", "Programavimas", "Biologija", "Kuno kultura",
        "Geografija", "Istorija", "Gimtoji kalba", "Anglu kalba", "Dorinis ugdymas"
        };

    int m,p,kt,ms,ms1; // m - mokyniu index`as <> p - pazymiu index`as <> kt - keisti arba trinti index`as
    int i,j,l;
    int _tekstoIlgis; // Teksto ilgis

    string _text;

    while (true) {


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
             "Pasalinti mokini is saraso - 5 ",
             "Nutraukti programa - 0 "
         };

        int _menuPasir = size(MS);                       //Masyvo ilgis
        _tekstoIlgis = ilgiausiaiTekstas(MS, _menuPasir);// Tikrinimas ilgiausio elemento (vnt)

        int _menuLines = _menuPasir + 3; // Meniu eiluciu kiekis
        for (l=1;l<=_menuLines;l++) {
            if (l == 1 || l == 3 || l == _menuLines) {
                    tbl(_tekstoIlgis,"=",_menuLines,l,0);
                } else if ( l == 2) {
                    tbl(_tekstoIlgis,MS[l-2],_menuLines,l,1);
                } else if (l > 3) {
                    tbl(_tekstoIlgis,MS[l-3],_menuLines,l,1);
            }
        }

        //---Ivestis Meniu----
        cin >> ms;

        while (true) {
            switch (ms) {
                case 0: {
                    return 0;
                }
                case 1: {
                    //--- Select 1 Meniu -----
                    _text = format("Iveskite kiek mokyniu norite ivesti | Limitas - {}, jau ivesta - {}", 100,_uzmt);
                    _tekstoIlgis=_text.length();
                    tbl(_tekstoIlgis,_text,1,1,-1);
                    cin>>ms1;
                    while (ms1 <1 || ms1>100-_uzmt) {
                        _text = format("Ivedimo intervalas nuo 1 iki {}, pakartokite:",100-_uzmt);
                        _tekstoIlgis=_text.length();
                        tbl(_tekstoIlgis,_text,1,1,-1);
                        cin>>ms1;
                    }
                    if (_uzmt != 0) {
                        ms1 =  ms1 + _uzmt;
                    }
                    for ( m=_uzmt; m<ms1; m++) {
                        cout << format("<<===================>> \n"
                        "Iveskite mokinio varda : ");
                        cin>>MV[m];
                        _uzmt++;
                        for (p=0; p<10; p++) {
                            cout << format("{} - Iveskite pazymi, dalikas: {} : ",p+1,dalykai[p]);
                            cin>>PZ[m][p];
                            while (PZ[m][p] < 1 || PZ[m][p] > 10) {
                                cout<<"! - Blogai ivestas pazymys, galimi variantai nuo 1 iki 10. Pakartotike : ";
                                cin>>PZ[m][p];
                            }
                        }
                    }
                }break;
                case 2: {

                }break;
                case 3: {

                }break;
                case 4: {

                }break;
                case 5: {

                }break;
                default: {
                    _text="Tokio pasirinkimo nera, pakartokite";
                    _tekstoIlgis=_text.length();
                    tbl(_tekstoIlgis,_text,1,1,-1);
                    cin>>ms;
                }break;
            }break;
        }


        //---Pazymiu Lentele---

        //----Pabaiga----

        cout<<endl;
        cout<<"--"<<endl;
        //return 0;
    }
}

int ilgiausiaiTekstas(string _tekstoMasyvas[],int n) {  // Tikrinam ilgiausia teksta

    int _tekstoIlgis = 0;
    for (int i=0; i < n; i++) {
        if (_tekstoIlgis<_tekstoMasyvas[i].length()) {
            _tekstoIlgis = _tekstoMasyvas[i].length();
        }
    }
    return _tekstoIlgis;
}

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
            if (_kitaEilute == 0) {
                cout<<"|  "<<setw(_tekstoIlgis)<<_text<<"   |";
            } else {
                cout<<"|  "<<setw(_tekstoIlgis)<<_text<<"   |";
                cout<<endl;
            }
        }
    }
}