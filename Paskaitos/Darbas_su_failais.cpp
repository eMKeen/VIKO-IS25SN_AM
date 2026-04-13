//Paskaita darbas su failai
#include <iostream>
#include <fstream>
using namespace std;

int Darbas_su_failais() {

    string _tekstas;

    int _masyvasSkaiciu [15];
    int _kiekis, _suma;
    _kiekis = 0;
    _suma = 0;
    double _vidurkis;

    ifstream _f;

    _f.open("../Paskaitos/DB/Failas.txt");

    if (_f.is_open()) {
        cout<<"Failas atidarytas"<<endl;
        while (!_f.eof()) {
            _f >> _masyvasSkaiciu[_kiekis];
            _kiekis++;
        }
    } else {
        cout << "Nepavyko" <<endl;
        return 0;
    }

    for (int i = 0; i < _kiekis; i++) {
        cout << _masyvasSkaiciu[i] << endl;
        _suma += _masyvasSkaiciu[i];
    }

    _f.close();

    _vidurkis = (double)_suma / _kiekis;
    cout << "Bendrai skaiciu - " << _kiekis << endl;
    cout << "Suma: " << _suma << endl;
    cout << "Vidurkis: " << _vidurkis << endl;
    ofstream _rf;

    _rf.open("../Paskaitos/DB/Rezultatu_Failas.txt");

    if (_rf.fail()) {
        cout << "Nepavyko atidaryti rezultatu failo" << endl;
        return 0;
    }

    _rf << "Rezultatas Duomenu faile" << endl;
    _rf << "Bendrai skaiciu faile - " << _kiekis << endl;
    _rf << "Suma: " << _suma << endl;
    _rf << "Vidurkis: " << _vidurkis << endl;

    _rf.close();

return 0;
}


