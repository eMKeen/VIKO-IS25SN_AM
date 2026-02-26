#include <iostream>
using namespace std;

int task1();
int task2();
int task3();
int task4();
int task5();
int task6();
//----------
//--salygos ir ciklai
int task7();
int task8();
int task9();
int task10();
int task11();
int task12();
//----------
//--Masyvai
int task13();
int task14();
//----1 Praktinis---
//-----------
int task15();

int main() {
    int p;
    cout << "Kuria programa tikrinti: "<<endl;
    cout << "Kintamieji: Nuo 1 iki 6"<<endl;
    cout << "Salygos ir ciklai: Nuo 7 iki 12"<<endl;
    cout << "Pirmas praktinis - Iskaitai - >>15<<"<<endl;
    cin >> p;

    if (p == 1) return task1();
    if (p == 2) return task2();
    if (p == 3) return task3();
    if (p == 4) return task4();
    if (p == 5) return task5();
    if (p == 6) return task6();
//---------
    if (p == 7) return task7();
    if (p == 8) return task8();
    if (p == 9) return task9();
    if (p == 10) return task10();
    if (p == 11) return task11();
    if (p == 12) return task12();
//----------
    if (p == 13) return task13();
    if (p == 14) return task14();
//----------
    if (p == 15) return task15();

    cout << "Neteisingas pasirinkimas\n";
    return 0;
}