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
#include <climits>
using namespace std;

int ilgiausiaiTekstas(string _tekstoMasyvas[],int n);
void tbl2(int _tekstoIlgis, string _text, int _ilgisLenget, int _eilutesNum, int _kitaEilute);
void showMenu(int _tekstoIlgis, string _text, double _price, int _eilutesNumeris, int _select, int _pasirinkimas);
int myliuLietuvybe(const string& txt);
int menuSelect(int _select, int _kiekis, int _notNULL);
void printCheck(int _tekstoIlgis, string _text, double _price, int _eilutesNumeris, int _select, int _pasirinkimas);
bool krepselis(int _menuKiekis, int _patiekaluPasirinkimas[][2]);


struct menuItemType {
    string menuItem;
    double menuPrice;

    void getData(ifstream& _mf) {
        getline(_mf, menuItem, ';');
        _mf >> menuPrice;
        _mf.ignore();
    }
};

int task22() {
    string _restoranas = "Sveiki atvykę į \"Kaimynų\" restoraną";

    menuItemType _menuList[100];
    int i;
    int _select;
    int _menuKiekis = 0;
    int _tekstoIlgis;
    string _text[100][2];
    int _eilesNumeris;
    int _pasirinkimas;
    double _totalPrice;


    ifstream _mf; // meniu failas
    _mf.open("../3_praktinis/DB/menu.txt");

    if (_mf.is_open()) {
        cout << "failas atidarytas" << endl;
        cout << endl;

        while (_mf) {
            _menuList[_menuKiekis].getData(_mf);
            _text[_menuKiekis][0] = _menuList[_menuKiekis].menuItem;
            _text[_menuKiekis][1] = to_string(_menuList[_menuKiekis].menuPrice).substr(0,4);
            _menuKiekis++;
            if (_mf.fail()) {break;}
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
    int _patiekaluPasirinkimas[100][2] = {0};

    _tekstoIlgis += 4; //Baziniai papildomi elementai
    tbl2(_tekstoIlgis,_restoranas,1,1,-1);
    cout << endl;

    string mainMenu[] = {
        "Pasirikite norimą operaciją",
        " 1 - Rinktis Patiekalą",
        " 2 - Peržiūrėti Pasirinkimą",
        " 3 - Pašalinti prekę",
        " 4 - Spausdinti Čėkį",
        " 0 - Baigti programa"
    };
    while (true) {


        int _menuPasir = size(mainMenu);
        int _ilgiausiasTektas = ilgiausiaiTekstas(mainMenu,_menuPasir);


        int _menuLines = _menuPasir + 3; // Meniu eiluciu kiekis
        for ( int l = 1; l <= _menuLines; l++) {
            if (l == 1 || l == 3 || l == _menuLines) {
                tbl2(_ilgiausiasTektas,"=",_menuLines,l,0);
            } else if ( l == 2) {
                tbl2(_ilgiausiasTektas,mainMenu[l-2],_menuLines,l,1);
            } else if (l > 3) {
                tbl2(_ilgiausiasTektas,mainMenu[l-3],_menuLines,l,1);
            }
        }
        _select = menuSelect(i, size(mainMenu) - 2,0);

        switch (_select) {
            case 0: {
                return 0;
            }
            case 1: {
                while (true) {
                    for ( i = 0; i < _menuKiekis; i++) {
                        if (i == 0 ) {
                            showMenu(_tekstoIlgis,_menuList[i].menuItem,_menuList[i].menuPrice,i,0,0);
                        } else {
                            showMenu(_tekstoIlgis,_menuList[i].menuItem,_menuList[i].menuPrice,i,1,0);
                        }
                    }
                    cout <<endl;
                    cout << " Pasirinkite patiekalą : ";
                    _select = menuSelect(i, _menuKiekis + 1,1);
                    cout << endl;
                    cout << " Pasirinkite patiekalų kiekį : ";
                    i = menuSelect(i, 50,1);
                    cout << endl;
                    _patiekaluPasirinkimas[_select - 1][0] += i;
                    cout << "-----------------------------" << endl;
                    cout << "Grišti į pagrindinį menių - 0" << endl;
                    cout << "Pasirinkti kitą patiekalą - 1" << endl;
                    _select = menuSelect(i, 2,0);
                    if ( _select == 0) {break;}
                }
            } break;
            case 2: {
                if (krepselis(_menuKiekis,_patiekaluPasirinkimas)) {break;}
                _eilesNumeris = 0;
                _totalPrice = 0;
                cout << "--------------------------" << endl;
                cout << "Jūsų pasirinkti patiekalai" << endl << endl;
                for (i = 0; i < _menuKiekis; i++) {
                    if (_patiekaluPasirinkimas[i][0] != 0) {
                        _totalPrice += _patiekaluPasirinkimas[i][0] * _menuList[i].menuPrice;
                        _pasirinkimas = _patiekaluPasirinkimas[i][0];
                        _patiekaluPasirinkimas[i][1] = _eilesNumeris;
                        showMenu(_tekstoIlgis,_menuList[i].menuItem,_menuList[i].menuPrice,_eilesNumeris,1,_pasirinkimas);
                        _eilesNumeris++;
                    }
                }
                double _mokesciai = _totalPrice * 0.21;
                _totalPrice += _mokesciai;
                showMenu(_tekstoIlgis,"Mokesčiai (21%)",_mokesciai,-1,-1,-1);
                showMenu(_tekstoIlgis,"Galutinė suma",_totalPrice,-1,-2,-1);
                cout << "--------------------------" << endl;
                cout << " Spauskite ENTER kad testi" << endl;
                string wait;
                cin.ignore();
                getline(cin,wait);
            } break;
            case 3: {
                while (true) {
                    if (krepselis(_menuKiekis,_patiekaluPasirinkimas)) {break;}
                    _eilesNumeris = 0;
                    _totalPrice = 0;
                    cout << "--------------------------" << endl;
                    cout << "Jūsų pasirinkti patiekalai" << endl << endl;
                    for (i = 0; i < _menuKiekis; i++) {
                        if (_patiekaluPasirinkimas[i][0] != 0) {
                            _totalPrice += _patiekaluPasirinkimas[i][0] * _menuList[i].menuPrice;
                            _pasirinkimas = _patiekaluPasirinkimas[i][0];
                            _patiekaluPasirinkimas[i][1] = _eilesNumeris;
                            showMenu(_tekstoIlgis,_menuList[i].menuItem,_menuList[i].menuPrice,_eilesNumeris,1,_pasirinkimas);
                            _eilesNumeris++;
                        }
                    }
                    cout <<endl;
                    cout << " Pasirinkite patiekalą : ";
                    _select = menuSelect(i, _eilesNumeris,1);
                    cout << endl;
                    cout << " Pasirinkite patiekalų kiekį : ";
                    i = menuSelect(i, 50,1);
                    cout << endl;
                    int _checker = false;
                    for ( int j = 0; j < _menuKiekis; j++) {
                        if (_patiekaluPasirinkimas[j][1] == _select - 1) {
                            if (_patiekaluPasirinkimas[j][0] >= i) {
                                _checker = true;
                                _patiekaluPasirinkimas[j][0] -= i;
                                if (_patiekaluPasirinkimas[j][0] == 0) {
                                    _patiekaluPasirinkimas[j][1] = 0;
                                }
                            }
                        }
                    }
                    if ( _checker == true) {
                        cout << "-----------------------------" << endl;
                        cout << "Grišti į pagrindinį menių - 0" << endl;
                        cout << "Pasirinkti kitą patiekalą - 1" << endl;
                        _select = menuSelect(i, 2,0);
                        if ( _select == 0) {break;}
                    } else if ( _checker == false) {
                        cout << "------------------------------------------------------------------------" << endl;
                        cout << "Jūs pasirinkote ne tinkamą kiekį arba Jūsų krepšelyje tokiso prekės nėra" << endl;
                        cout << "Grišti į pagrindinį menių - 0" << endl;
                        cout << "Pasirinkti kitą patiekalą - 1" << endl;
                        _select = menuSelect(i, 2,0);
                        if ( _select == 0) {break;}
                    }
                }
            } break;
                case 4: {
                    if (krepselis(_menuKiekis,_patiekaluPasirinkimas)) {break;}
                    string _raktas ="Kvito numeris: ";
                    int _eilutesNumeris = 0;
                    ifstream _rn("../3_praktinis/DB/receipt.txt");
                    if (_rn.is_open()) {
                        string _finder;
                        int _lastNumeris = 0;
                        while (getline(_rn,_finder)) {
                            size_t _poz = _finder.find(_raktas);
                            if (_poz != string::npos) {
                                _lastNumeris= stoi(_finder.substr(_poz + _raktas.length()));
                                if (_eilutesNumeris < _lastNumeris) {
                                    _eilutesNumeris = _lastNumeris;
                                }
                            }
                        }
                        _rn.close();
                    }
                    _totalPrice = 0;
                    printCheck(_tekstoIlgis,"\"Kaimynų\" Restoranas",0,_eilutesNumeris + 1,0,_pasirinkimas);
                    for (i = 0; i < _menuKiekis; i++) {
                        if (_patiekaluPasirinkimas[i][0] != 0) {
                            _totalPrice += _patiekaluPasirinkimas[i][0] * _menuList[i].menuPrice;
                            _pasirinkimas = _patiekaluPasirinkimas[i][0];
                            printCheck(_tekstoIlgis,_menuList[i].menuItem,_menuList[i].menuPrice,_eilutesNumeris + 1,1,_pasirinkimas);
                            _eilesNumeris++;
                        }
                    }
                    double _mokesciai = _totalPrice * 0.21;
                    _totalPrice += _mokesciai;
                    printCheck(_tekstoIlgis,"Mokesčiai (21%)",_mokesciai,_eilutesNumeris + 1,-1,-1);
                    printCheck(_tekstoIlgis,"Galutinė suma",_totalPrice,_eilutesNumeris + 1,-2,-1);
                    for ( int j = 0; j < _menuKiekis; j++) {
                        _patiekaluPasirinkimas[j][0] = 0;
                        _patiekaluPasirinkimas[j][1] = 0;
                    }
                    cout << "--------------------------------------------" << endl;
                    cout << " Spauskite ENTER kad pateikti nauja užsakymą" << endl;
                    string wait;
                    cin.ignore();
                    getline(cin,wait);
                } break;
        }
    }
}

void showMenu(int _tekstoIlgis, string _text, double _price, int _eilutesNumeris, int _select, int _pasirinkimas) {
    string _menuName = "Meniu";
    string _showText;
    int _start = 0;
    int _lineKorekcija;
    _lineKorekcija = _text.length() - myliuLietuvybe(_text);

    if (_select == 0) {
        _start = _tekstoIlgis - _menuName.length();
        for (int i = 0; i < _start/2; i++) {
            cout << " ";
        }
        cout << _menuName << endl << endl;
    }

    if (_pasirinkimas == 0) {
        if ( _eilutesNumeris < 10) { //Pasirinkimo numeris + tarpas
            _showText = " " + to_string(_eilutesNumeris +1) + "  - " + _text;
        } else {
            _showText = " " + to_string(_eilutesNumeris +1) + " - " + _text;
        }
        cout << format("{:<{}}{:>6.2f}€",_showText,_tekstoIlgis + _lineKorekcija,_price) << endl;
    }

    if (_pasirinkimas > 0) {
        if ( _eilutesNumeris < 10) { //Pasirinkimo numeris + tarpas
            _showText = " " + to_string(_eilutesNumeris +1) + "  - " + _text;
        } else {
            _showText = " " + to_string(_eilutesNumeris +1) + " - " + _text;
        }
        double _subTotal = _pasirinkimas * _price;
        cout << format("{:<{}}{:>6.2f}€",_showText,_tekstoIlgis + _lineKorekcija,_price) << endl;
        cout << format("{:>{}}vnt x {} -{:>6.2f}€",_pasirinkimas,_tekstoIlgis - 15,_price,_subTotal) << endl;
    }

    if (_select == -1) {
        cout << endl;
        cout << format("{:<{}}{:>6.2f}€",_text,_tekstoIlgis + _lineKorekcija,_price) << endl;
    } else if (_select == -2) {
        cout << format("{:<{}}{:>6.2f}€",_text,_tekstoIlgis + _lineKorekcija,_price) << endl << endl;
    }
}

void printCheck(int _tekstoIlgis, string _text, double _price, int _eilutesNumeris, int _select, int _pasirinkimas) {
    string _raktas = "Kvito numeris: ";
    ofstream _rf("../3_praktinis/DB/receipt.txt", ios::app); // receipt failas
    if (_rf.fail()) {
        cout << "--------------------------" << endl;
        cout << "  Faila nepavyko atidaryti" << endl;
        cout << " Spauskite ENTER kad testi" << endl;
        string wait;
        cin.ignore();
        getline(cin,wait);
    } else {
        int _lineKorekcija;
        _lineKorekcija = _text.length() - myliuLietuvybe(_text);

        if (_select == 0 ) {
            _rf << format("{:-<{}}","-",_tekstoIlgis + _lineKorekcija + 6) << endl;
            _rf << format("{:<{}}{:<{}}","",_tekstoIlgis/2 - _text.length()/2,_text,_tekstoIlgis/2 - _text.length()/2) << endl;
            _rf << format("{:-<{}}","-",_tekstoIlgis + _lineKorekcija + 6) << endl;
            _rf << endl << endl;
            return;
        }

        if (_pasirinkimas > 0) {
            double _subTotal = _pasirinkimas * _price;
            _rf << format("{:<{}}{:>6.2f}€",_text,_tekstoIlgis + _lineKorekcija,_price) << endl;
            _rf << format("{:>{}}vnt x {} -{:>6.2f}€",_pasirinkimas,_tekstoIlgis - 15,_price,_subTotal) << endl;
        }

        if (_select == -1) {
            _rf << endl;
            _rf << format("{:<{}}{:>6.2f}€",_text,_tekstoIlgis + _lineKorekcija,_price) << endl;
        } else if (_select == -2) {
            _rf << format("{:<{}}{:>6.2f}€",_text,_tekstoIlgis + _lineKorekcija,_price) << endl << endl;
            _rf << format("Kvito numeris: {}",_eilutesNumeris) << endl;
            _rf << format("{:-<{}}","-",_tekstoIlgis + _lineKorekcija + 6) << endl;
        }
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

    int _lineKorekcija;
    _lineKorekcija = _text.length() - myliuLietuvybe(_text);
    string _centrasPavadinimas, _tarpas;

    for (i = 0; i < (_tekstoIlgis + _lineKorekcija)/8; i++) {
        _tarpas += " ";
    }
    _centrasPavadinimas = "| " + _tarpas + _text + _tarpas + "  |";
    if (_kitaEilute == -1) {
        for (l=1;l<=3;l++) {
            if (l==1 || l==3) {
                for (i=0;i<=_tekstoIlgis + _lineKorekcija;i++) {
                    cout<<"=";
                }
                cout<<endl;
            } else {
                cout << left << setw(_tekstoIlgis + _lineKorekcija) << _centrasPavadinimas << endl;
            }
        }
    }

    if (_kitaEilute > -1) {
        if (_eilutesNum==1 || _eilutesNum==3 || _eilutesNum==_ilgisLenget) {
            for (i=0;i<_tekstoIlgis + _lineKorekcija;i++) {
                cout<<"=";
            }
            cout<<endl;
        } else {
            if (_kitaEilute == 0) {
                cout<<" "<<left << setw(_tekstoIlgis + _lineKorekcija)<<_text<<"  ";
            } else {
                cout<<" "<<left << setw(_tekstoIlgis + _lineKorekcija)<<_text<<"  ";
                cout<<endl;
            }
        }
    }
}

int myliuLietuvybe(const string& txt) {
    int _ilgis = 0;

    for (int i = 0; i < txt.length(); i++) {
        unsigned char c = txt[i];
        if ((c & 0b11000000) != 0b10000000) {
            _ilgis++;
        }
    }

    return _ilgis;
}

int menuSelect(int _select, int _kiekis, int _notNULL) { //start _notNULL
    while (true) {
        while (!(cin >> _select) || _select < 0) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "------------------------------------------------" << endl;
            cout << ">> Pasirinkimas ne tinkamas, rinkites iš menių<<" << endl;
            cout << ">>Pakartokite įvedimą" << endl;
        }

        if ( _select >= _notNULL && _select <= _kiekis) {
            return _select;
        }
        cout << "------------------------------------------------" << endl;
        cout << ">> Pasirinkimas ne tinkamas, rinkites iš menių<<" << endl;
        cout << ">>Pakartokite įvedimą" << endl;
    }
}

bool krepselis(int _menuKiekis, int _patiekaluPasirinkimas[][2]) {
    int _krepselis = 0;
    for ( int i = 0; i < _menuKiekis; i++) {
        if (_patiekaluPasirinkimas[i][0] != 0) {
            _krepselis++;
        }
    }
    if (_krepselis == 0) {
        cout << "-------------------------------------------------" << endl;
        cout << " Jūsų krepšelis tusčias, prašome pasirinkti prekę" << endl;
        cout << " Spauskite ENTER kad testi" << endl;
        string wait;
        cin.ignore();
        getline(cin,wait);
        return true;
    }
    return false;
}