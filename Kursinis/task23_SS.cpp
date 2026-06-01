//Selection Sort
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

//Selection Sort
void selectionSort(vector<int>& _data) {
    int _size = _data.size();
    for (int i = 0; i < _size - 1; i++) {
        int _minIndex = i;
        for (int j = i + 1; j < _size; j++) {
            if (_data[j] < _data[_minIndex]) {
                _minIndex = j;
            }
        }
        if (_minIndex != i) {
            swap(_data[i], _data[_minIndex]);
        }
    }
}

int task23_SS() {
    string _inputFile;
    string _outputFile;
    // Is kokio failo ims
    cout << "Iveskite pradinio failo pavadinima: ";
    cin >> _inputFile;
    // I koki faila des
    cout << "Iveskite rezultato failo pavadinima: ";
    cin >> _outputFile;

    ifstream _inFile("../Kursinis/DB/" + _inputFile);
    if (!_inFile) {
        cout << "Nepavyko atidaryti failo!" << endl;
        return 0;
    }

    vector<int> _numbers;
    int _value;
    while (_inFile >> _value) {
        _numbers.push_back(_value);
    }

    _inFile.close();
        // Laiko matavimas
        auto _start = chrono::high_resolution_clock::now();
        selectionSort(_numbers);
        auto _end = chrono::high_resolution_clock::now();
        auto _duration =
        chrono::duration_cast<chrono::microseconds>(_end - _start);
    ofstream _outFile("../kursinis/DB/Rezultatas/" + _outputFile);

    if (!_outFile) {
        cout << "Nepavyko sukurti rezultato failo!" << endl;
        return 0;
    }
    for (int i = 0; i < _numbers.size(); i++) {
        if (i < _numbers.size() - 1) {
            _outFile << _numbers[i] << '\n';
        } else {
            _outFile << _numbers[i];
        }
    }
    _outFile.close();

    cout << "Elementu kiekis: " << _numbers.size() << endl;
    cout << "Rikiavimo laikas: " << _duration.count() << " microSec" << endl;
    return 0;
}