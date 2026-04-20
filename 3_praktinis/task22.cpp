/*Užduotis: „Restorano mini apskaitos sistema“

Tikslas:

Sukurti C++ programą, kuri padeda vietiniam restoranui automatizuoti pusryčių užsakymų ir sąskaitų generavimo procesą.

    Rodyti klientui pusryčių meniu, kuriame būtų visi restorano siūlomi patiekalai ir jų kainos.

    Leisti klientui pasirinkti kelis skirtingus patiekalus ir nurodyti norimą porcijų kiekį kiekvienam patiekalui.

    Apskaičiuoti sąskaitą pagal pasirinktus patiekalus ir porcijų skaičių, įtraukiant 21% PVM mokestį. Rezultatas turi būti suformatuotas iki dviejų skaitmenų po kablelio.

    Išsaugoti sąskaitą faile (pvz., receipt.txt) ir paraleliai ją išvesti į ekraną.

    Patiekalo pasirinkime vartotojas turi galėti nurodyti kelias vieno tipo patiekalo porcijas.

    Kavinės meniu turi būti saugomas atskirame tekstiniame faile (pvz., menu.txt). Programa privalo šį failą nuskaityti funkcijoje getData ir užpildyti masyvą menuList pagal jame pateiktus duomenis.

Pusryčių meniu (failo menu.txt turinio pavyzdys):
Patiekalo pavadinimas 	Kaina (EUR)
Kiaušinienė 	1.45
Kiaulienos šoninė su keptu kiaušiniu 	2.45
Keksiukas su vyšnia 	0.99
Prancūziškas skrebutis 	1.99
Vaisių salotos 	2.49
Pusryčių dribsniai 	0.69
Kava 	0.50
Arbata 	0.75

Programoje turi būti naudojama struktūra:

struct menuItemType {
    string menuItem;     // patiekalo pavadinimas
    double menuPrice;    // patiekalo kaina (2 skaitmenys po kablelio)
};

Privalomos funkcijos:

    getData – nuskaito meniu duomenis iš failo (pvz., menu.txt) ir įkelia į masyvą menuList;
    showMenu – išveda visą pusryčių meniu ir paaiškina, kaip vartotojui pasirinkti patiekalus;
    printCheck – apskaičiuoja tarpines sumas, PVM (21%) ir galutinę sumą; rezultatą išveda į ekraną ir įrašo į receipt.txt.

Pavyzdinė išvestis:

Sveiki atvykę į restoraną „Pavadinimas“

Kiaulienos šoninė su keptu kiaušiniu   2.45€
Keksiukas su vyšnia                    0.99€
Kava                                   0.50€

Mokesčiai (21%)                        0.84€
Galutinė suma                          4.78€

Pavyzdys, kai pasirenkamos kelios porcijos:

Sveiki atvykę į restoraną „Pavadinimas“

1  Kiaulienos šoninė su keptu kiaušiniu   2.45€
2  Keksiukas su vyšnia                    0.99€
1  Kava                                   0.50€

Mokesčiai (21%)                           1.03€
Galutinė suma                             5.93€
*/

#include <iostream>
#include <string>
#include <format>
#include <iomanip>
#include <iterator>
#include <fstream>
using namespace std;

int ilgiausiaiTekstas(string _tekstoMasyvas[],int n);
void tbl2(int _tekstoIlgis, string _text, int _ilgisLenget, int _eilutesNum, int _kitaEilute);
void showMenu(int _tekstoIlgis, string _text[][2], int _eilutesNumeris, int _select);

struct menuItemType {
    string menuItem;
    double menuPrice;

    void getData(ifstream& _mf) {
        getline(_mf, menuItem, ';');
        _mf >> menuPrice;
        _mf.ignore();
    }


    void printCheck(double suma) {
        cout << "Moketi: " << suma << endl;
    }
};

int task22() {
    string _restoranas = "Sveiki atvykę į \"Kaimynų\" restoraną";

    menuItemType _menuList[100];
    int i;
    int _menuKiekis = 0;
    int _tekstoIlgis;
    string _text[100][2];

    ifstream _mf; // meniu failas
    _mf.open("../3_praktinis/DB/menu.txt");

    if (_mf.is_open()) {
        cout << "failas atidarytas" << endl;
        cout << endl;

        //Reikia naudoti >>GetData<<

        while (_mf) {
            _menuList[_menuKiekis].getData(_mf);
            if (_mf.fail()) {break;}
            _text[_menuKiekis][0] = _menuList[_menuKiekis].menuItem;
            _text[_menuKiekis][1] = to_string(_menuList[_menuKiekis].menuPrice).substr(0,4);
            _menuKiekis++;
        }
    } else {
        cout << "faila nepavyko atidaryti" << endl;
    }
    _mf.close();

    _tekstoIlgis = _restoranas.length();
    for (i = 0; i < _menuKiekis; i++) {
        if ( _tekstoIlgis < _text[i][0].length() + _text[i][1].length()) {
            _tekstoIlgis = _text[i][0].length() + _text[i][1].length();
        }
    }
    _tekstoIlgis += 4; //Baziniai papildomi elementai
    tbl2(_tekstoIlgis,_restoranas,1,1,-1);
    cout << endl;

    for ( i = 0; i < _menuKiekis; i++) {
        if (i == 0 ) {
            showMenu(_tekstoIlgis,_text,i,0);
        } else {
            showMenu(_tekstoIlgis,_text,i,1);
        }


        //cout << _menuList[i].menuItem << " - " << _menuList[i].menuPrice << endl;
    }


    cin.ignore();
    string wait;
    getline(cin, wait);
    return 0;
}

void showMenu(int _tekstoIlgis, string _text[][2], int _eilutesNumeris, int _select) {
    string _menuName = "Meniu";
    int _start = 0;
    int _pasirinkimas;
    if (_tekstoIlgis% 2 == 1) {_tekstoIlgis++;} // reikalingas lyginis
    switch (_select) {
        case 0: {
            //Menu
            _start = _tekstoIlgis - _menuName.length();
            for (int i = 0; i < _start/2; i++) {
                cout << " ";
            }
            cout << _menuName << endl << endl;

            //Select 1
            _pasirinkimas = 4;
            _start = _tekstoIlgis - _text[_eilutesNumeris][0].length() - _text[_eilutesNumeris][1].length() - _pasirinkimas;
            cout << " " << _eilutesNumeris + 1 << "  - " << _text[_eilutesNumeris][0];
            for ( int i = 0 ; i < _start; i++ ) {
                cout << " ";
            }
            cout << _text[_eilutesNumeris][1] << endl;
        }break;
        default: {
            //Select 2 ir ...
            if ( _eilutesNumeris + 1 < 10) { //Pasirinkimo numeris + tarpas
                _pasirinkimas = 4;
                _start = _tekstoIlgis - _text[_eilutesNumeris][0].length() - _text[_eilutesNumeris][1].length() - _pasirinkimas;
                cout << " " << _eilutesNumeris + 1 << "  - " << _text[_eilutesNumeris][0];
            } else {
                _pasirinkimas = 5;
                _start = _tekstoIlgis - _text[_eilutesNumeris][0].length() -_text[_eilutesNumeris][1].length() - _pasirinkimas;
                cout << " " << _eilutesNumeris + 1 << " - " << _text[_eilutesNumeris][0];
            }
            for ( int i = 0 ; i < _start ; i++ ) {
                cout << " ";
            }

            cout << _text[_eilutesNumeris][1] << endl;
        }break;
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

void tbl2(int _tekstoIlgis, string _text, int _ilgisLenget, int _eilutesNum, int _kitaEilute) {
    int i,l;

    if (_kitaEilute == -1) {
        for (l=1;l<=3;l++) {
            if (l==1 || l==3) {
                for (i=0;i<=_tekstoIlgis;i++) {
                    cout<<"=";
                }
                cout<<endl;
            } else {
                cout<<"| "<<setw(_tekstoIlgis)<<_text<<"  |"<<endl;
            }
        }
    }

    if (_kitaEilute > -1) {
        if (_eilutesNum==1 || _eilutesNum==3 || _eilutesNum==_ilgisLenget) {
            for (i=0;i<_tekstoIlgis;i++) {
                cout<<"=";
            }
            cout<<endl;
        } else {
            if (_kitaEilute == 0) {
                cout<<"| "<<setw(_tekstoIlgis)<<_text<<"  |";
            } else {
                cout<<"| "<<setw(_tekstoIlgis)<<_text<<"  |";
                cout<<endl;
            }
        }
    }
}