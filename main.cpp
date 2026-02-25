#include <iostream>
using namespace std;

int task1();
int task2();
int task3();
int task4();
int task5();
int task6();

int main() {
    int p;
    cout << "Kuria programa tikrinti: "<<endl;
    cout << "Kintamieji: Nuo 1 iki 6"<<endl;
    cin >> p;

    if (p == 1) return task1();
    if (p == 2) return task2();
    if (p == 3) return task3();
    if (p == 4) return task4();
    if (p == 5) return task5();
    if (p == 6) return task6();

    cout << "Neteisingas pasirinkimas\n";
    return 0;
}