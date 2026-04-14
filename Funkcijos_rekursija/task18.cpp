/*Praktinė užduotis: Funkcijos C++ kalboje
Tikslas

Sukurti ir panaudoti funkcijas sprendžiant skirtingas programavimo užduotis.
Užduotys
🔹 1. Skaičiaus kvadratas

Sukurk funkciją, kuri priima sveiką skaičių ir grąžina jo kvadratą. Pagrindinėje programoje įvesk skaičių, iškviesk funkciją ir išvesk rezultatą.
🔹 2. Ar skaičius lyginis?

Sukurk funkciją, kuri nustato, ar įvestas skaičius yra lyginis, ir grąžina true arba false. Pagrindinėje programoje išvesk tekstą „Lyginis“ arba „Nelyginis“.
🔹 3. Skaičiaus skaitmenų suma

Sukurk funkciją, kuri apskaičiuoja įvesto sveiko skaičiaus skaitmenų sumą. Funkcijoje naudok ciklą skaitmenims išskirti.
🔹 4. Didžiausias masyvo elementas

Sukurk funkciją, kuri randa ir grąžina didžiausią elementą masyve. Pagrindinėje programoje vartotojas įveda masyvą, o funkcija apskaičiuoja rezultatą.
🔹 5. Ar žodis yra palindromas?

Sukurk funkciją, kuri patikrina, ar įvestas žodis yra palindromas (skaitomas vienodai iš abiejų pusių).
Reikalavimai

    Naudoti funkcijas kiekvienai užduočiai
    Naudoti tinkamus duomenų tipus (int, bool, string)
*/

#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int skaiciausKvadratas(int _skaicius, int _laipsnis) {
    int _kvadratas = pow(_skaicius , _laipsnis) ;
    return _kvadratas;
}


bool LygNelyg(int _skaicius) {
    if (_skaicius % 2 != 0) {
        return false;
    }
    return true;
}

int skaiciausSkaitmenuSuma(int _skaicius) {

    int _suma = 0;
    while (_skaicius != 0) {
        _suma += (_skaicius % 10);
        _skaicius = _skaicius / 10;
    }
    return _suma;
}

int didziausiasSkaicius(int _skaiciusM[], int _masivoIlgis) {
    int _max = _skaiciusM[0];
    for (int i=0; i < _masivoIlgis; i++) {
        if ( _max < _skaiciusM[i]) {
            _max = _skaiciusM[i];
        }
    }
    return _max;
}

bool arPalindromas(string _tekstas) {
    int _tekstoIlgis = _tekstas.length();
    for (int i=0; i < _tekstoIlgis / 2; i++) {
        if (_tekstas[i] != _tekstas[_tekstoIlgis - 1 - i]) {
            return false;
        }
    }
    return true;
}

int task18() {
    while (true) {
        int _skaiciusM[0], _skaicius, _laipsnis, _masivoIlgis;
        int _i;
        string _tekstas;

        cout << "Pasirinkite kuri veiksma norite atlikti" << endl;
        cout << "Skaicius laipsnyje               - 1" << endl;
        cout << "Ar skaicius lyginis / nelyginis  - 2" << endl;
        cout << "Ivesto skaiciaus, skaiciu suma   - 3" << endl;
        cout << "Didziausiais masyvo skaicius     - 4" << endl;
        cout << "Ar ivestas zodis yra palindromas - 5" << endl;
        cout << "Uzbaigti programa                - 0" << endl;
        cout << "======================================" << endl;
        cout << "Iveskit pasirinkima" << endl;
        cin >> _i;

        switch (_i) {
            case 0: return 0;
            case 1: {
                cout << "Ivesto skaicius" << endl;
                cin >> _skaicius;
                cout << "Sio skaiciau kvadratas yra = " << skaiciausKvadratas(_skaicius,2) << endl;
                cout << "Spauskit enter" << endl;
                cin.ignore();
                string _wait;
                getline(cin, _wait);
                break;
            }
            case 2: {
                cout << "Ivesto skaicius" << endl;
                cin >> _skaicius;
                if ( LygNelyg(_skaicius) ) {
                    cout << "Skaicius yra Lyginis" << endl;
                } else { cout << "Skaicius yra Nelyginis" << endl;}
                cout << "Spauskit enter" << endl;
                cin.ignore();
                string _wait;
                getline(cin, _wait);
                break;
            }
            case 3: {
                cout << "Ivesto skaicius" << endl;
                cin >> _skaicius;
                cout << "Ivesto skaiciaus skaitmenu suma yra = " << skaiciausSkaitmenuSuma(_skaicius) << endl;
                cout << "Spauskit enter" << endl;
                cin.ignore();
                string _wait;
                getline(cin, _wait);
                break;
            }
                case 4: {
                cout << "Iveskite kokiek norite ivesti skaiciu" << endl;
                cin >> _masivoIlgis;
                for (int i=0; i < _masivoIlgis; i++) {
                    cout << "Ivesto skaicius" << endl;
                    cin >> _skaiciusM[i];
                }
                cout << "Didziausiais skaicius yra - " << didziausiasSkaicius(_skaiciusM,_masivoIlgis) << endl;
                cout << "Spauskit enter" << endl;
                cin.ignore();
                string _wait;
                getline(cin, _wait);
                break;
            }
                case 5: {
                cout << "Ivesto Zodi" << endl;
                cin >> _tekstas;
                if ( arPalindromas(_tekstas) ) {
                    cout << "Jusu ivestas zodis yra Palindromas" << endl;
                } else { cout << "Jusu ivestas zodis Nepalindromas" << endl;}
                cout << "Spauskit enter" << endl;
                cin.ignore();
                string _wait;
                getline(cin, _wait);
                break;
            }

        }
    }
}