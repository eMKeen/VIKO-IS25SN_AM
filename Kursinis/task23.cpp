// Duomenu failo generacija <random> tvarka
#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int task23()
{
    int _kiekis;
    int _minRiba;
    int _maxRiba;
    string _fileName;

    cout << "Iveskite generuojamu skaiciu kieki: ";
    cin >> _kiekis;

    cout << "Iveskite maziausia reiksme: ";
    cin >> _minRiba;

    cout << "Iveskite didziausia reiksme: ";
    cin >> _maxRiba;

    cout << "Iveskite failo pavadinima: ";
    cin >> _fileName;

    ofstream _failas("../kursinis/DB/" + _fileName);

    if (!_failas)
    {
        cout << "Nepavyko atidaryti failo!" << endl;
        return 0;
    }

    random_device _rn;
    mt19937 _gen(_rn());

    uniform_int_distribution<int> _dist(_minRiba, _maxRiba);

    for (int i = 0; i < _kiekis; i++)
    {
        _failas << _dist(_gen) << '\n';
    }

    _failas.close();

    cout << "Sugeneruota " << _kiekis << " skaiciu i faila " << _fileName << endl;

    return 0;
}