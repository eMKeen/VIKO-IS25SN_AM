//Selection Sort && Heap Sort
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

void selectionSort(vector<int>& _data); //SelectionSort F-ja
void maxHeapify(vector<int>& _data, int _size, int _select); //Heap(piramides) kurimas/atstatymas F-ja
void heapSort(vector<int>& _data); //HeapSort F-ja

int task23_SS() {
    string _inputFile; //Failo is kurio nuskaitys kintamasis (pavadinimas)
    string _outputFile;//Failo i kuri irasis kintamasis (pavadinimas)
    // Is kokio failo ims
    cout << "Iveskite pradinio failo pavadinima: ";
    cin >> _inputFile;
    // I koki faila des
    cout << "Iveskite rezultato failo pavadinima: ";
    cin >> _outputFile;

    //Failo su DuomenuRinkiniu nuskaitymas - Directorija + failo pavadinimas (kintamasis)
    ifstream _inFile("../Kursinis/DB/" + _inputFile);
    //Tikrintojas ar atsidare
    if (!_inFile) {
        cout << "Nepavyko atidaryti failo!" << endl;
        return 0;
    }
    //Nuskaitimas visu elementu i vectoriu
    vector<int> _numbers;
    int _value;
    while (_inFile >> _value) { //vykdo kol imanoma nuskatyti
        _numbers.push_back(_value); //Naujai nuskatyta elementa patalpina i vectoriaus gala
    }

    //Menu select
    cout << "Pasirkinkte sortiravima" << endl;
    cout << "Isrinkimo rikiavimas (Selection Sort) - 1" << endl;
    cout << "Piramidinis rikiavimas (Heap Sort) - 2" << endl;
    cout << "Uzbaigti programa - 0" << endl;
    int _ms;
    cin >> _ms;
    _inFile.close();
    // Laiko matavimas
    //Laikrodis su labai dideliu tankiu skaiciavimo - high_resolution_clock
    auto _start = chrono::high_resolution_clock::now(); //startas
    switch (_ms) {
        // Selection
        case 1: {
            selectionSort(_numbers);
        }break;
            // Heap
            case 2: {
                heapSort(_numbers);
        }break;
            // Exit
            default:{
            return 0;
            }
    }
    auto _end = chrono::high_resolution_clock::now(); //pabaiga
    //microseconds - 1ms = 1000 microseconds
    auto _duration = chrono::duration_cast<chrono::microseconds>(_end - _start); //Kiekis

    //export
    if (_ms == 1 ) {
        _outputFile = _outputFile + "_SS"; // output failo pavadinimas + Sort rusys
    } else if (_ms == 2 ) {
        _outputFile = _outputFile + "_HS"; // output failo pavadinimas + Sort rusys
    }
    ofstream _outFile("../kursinis/DB/Rezultatas/" + _outputFile);

    //Tikrinimas
    if (!_outFile) {
        cout << "Nepavyko sukurti rezultato failo!" << endl;
        return 0;
    }
    //Outputas surikiuotu Duomenu Rinkinio
    for (int i = 0; i < _numbers.size(); i++) {
        if (i < _numbers.size() - 1) {
            _outFile << _numbers[i] << '\n';
        } else {
            _outFile << _numbers[i]; //Paskutinis elementas
        }
    }
    _outFile.close();
    //Isvedimas rezultato (elementu kiekis ir laikas rikiavimui
    cout << "Elementu kiekis: " << _numbers.size() << endl;
    cout << "Rikiavimo laikas: " << _duration.count() << " microSec" << endl;
    return 0;
}


//Selection Sort
void selectionSort(vector<int>& _data) { //Paima originala, kopija letintu algoritma
    int _size = _data.size(); //Ziurim vectoriaus ilgi
    for (int i = 0; i < _size - 1; i++) { //Tikrinamo elemento indexas
        int _minIndex = i; //Traktuojamas kaip maziausios elemento indexas
        for (int j = i + 1; j < _size; j++) { //Su kurio tikriname indexas
            if (_data[j] < _data[_minIndex]) { //Maziausio elemento patikra
                _minIndex = j;
            }
        }
        if (_minIndex != i) { //Jeigu rastas maziasnis elementas, sukeciamas
            swap(_data[i], _data[_minIndex]);
        }
    }
}

// HeapSort
//Paima orginalu vectoriu, ilgi, sakninio elemento indexa
void maxHeapify(vector<int>& _data, int _size, int _select) {
    int _didziausiasElementas = _select; //sakninis elementas
    int _left = 2 * _select + 1; // kairine saka
    int _right = 2 * _select + 2; //desinine saka

    // tikriname ar indexas ne iskrenta is vectoriaus, ar kairinis ne didesnis uz sakni
    if (_left < _size && _data[_left] > _data[_didziausiasElementas]) {
        _didziausiasElementas = _left; //Jeigu didesnis priskiriame index`a
    }
    // tikriname ar indexas ne iskrenta is vectoriaus, ar desininis ne didesnis uz sakni
    if (_right < _size && _data[_right] > _data[_didziausiasElementas]) {
        _didziausiasElementas = _right; //Jeigu didesnis priskiriame index`a
    }
    // tikriname ar didesnio elemento indexas tas pats, jeignu ne, sukeiciam elementus
    if (_didziausiasElementas != _select) {
        swap(_data[_select], _data[_didziausiasElementas]);
        maxHeapify(_data, _size, _didziausiasElementas); //Reuksinam funkcija
    }
}
//Paimam orginalu vectoriu
void heapSort(vector<int>& _data) {
    int _size = _data.size(); //Ziurim vectoriaus ilgi
    // Einam per visus mazgus nuo apacios i virsu
    for (int i = _size / 2 - 1; i >= 0; i--){
        maxHeapify(_data, _size, i);
    }
    //Po viena elementa keliam i galutine vieta
    for (int i = _size - 1; i > 0; i--) {
        swap(_data[0], _data[i]);
        maxHeapify(_data, i, 0);
    }
}