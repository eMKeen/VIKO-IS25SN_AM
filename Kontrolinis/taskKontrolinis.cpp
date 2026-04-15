#include <iostream>
#include <iomanip>
using namespace std;

int K1() {
    int _skaicius, _checker;
    _checker = 0;
    cout << "iveskite skaiciu" << endl;
    cin >> _skaicius;
    _skaicius = abs(_skaicius);
    if (_skaicius == 0 ) {
        _checker = 1;
    } else {
        while (_skaicius != 0 ) {
            _skaicius /= 10;
            _checker++;
        }
    }
    if (_checker == 4) {
        cout << "Ivestas skaicius yra keturzenklis" << endl;
    } else { cout << "Ivestas skaicius nera keturzenklis" << endl; }
    return 0;
}

#include <iostream>
using namespace std;

int K2() {
    int _skaicius;
    cout << "iveskite skaiciu" << endl;
    cin >> _skaicius;
    while (true) {
        if (_skaicius % 7 != 0 ) {
            cout << "Iveskite skaicius kuris dalinasi is 7" << endl;
            cin >> _skaicius;
        } else {
            cout << "Ivestas skaicius dalinasi is 7" << endl;
            break;
        }
    }
    return 0;
}

#include <iostream>
using namespace std;

int K3() {
    int _skaiciusM[5];
    int _suma = 0;
    int max, min;
    for (int i = 0; i < 5; i++) {
        cout << "Iveskite skaiciu" << i + 1 << " : ";
        cin >> _skaiciusM[i];
    }
    max = _skaiciusM[0];
    min = _skaiciusM[0];
    for (int i = 0; i < 5; i++) {
        _suma += _skaiciusM[i];
        if (_skaiciusM[i] > max) {
            max = _skaiciusM[i];
        }
        if (_skaiciusM[i] < min) {
            max = _skaiciusM[i];
        }
    }
    cout << "Suma: " << _suma << endl;
    cout << "Didziausias: " << max << endl;
    cout << "Maziausias: " << min << endl;
    return 0;
}