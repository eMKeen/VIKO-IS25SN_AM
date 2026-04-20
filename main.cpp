#include <iostream>
#include <windows.h>
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
//----2 praktinis ---
int task16();
//----Paskaitu prog ---
int Darbas_su_failais();
int task18();
//----Kontrolinis ---
int K1();
int K2();
int K3();
//----3_praktinis ---
int task22();

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int p;
    cout << "Kuria programa tikrinti: "<<endl;
    cout << "Kintamieji: Nuo 1 iki 6"<<endl;
    cout << "Salygos ir ciklai: Nuo 7 iki 12"<<endl;
    cout << "Pirmas praktinis - Iskaitai - >>15<<"<<endl;
    cout << "Antras praktinis - Iskaitai - >>16<<"<<endl;
    cout << "Darbas su Failais           - >>17<<"<<endl;
    cout << "Funkcijos                   - >>18<<"<<endl;
    cout << "Kontrolionio scriptas 1 - >>19<<"<<endl;
    cout << "Kontrolionio scriptas 2 - >>20<<"<<endl;
    cout << "Kontrolionio scriptas 3 - >>21<<"<<endl;
    cout << "Trevias praktinis - iskaitai - >>22<<"<<endl;
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
    //----------
    if (p == 16) return task16();
    //----------
    if (p == 17) return Darbas_su_failais();
    if (p == 18) return task18();
    //----------
    if (p == 19) return K1();
    if (p == 20) return K2();
    if (p == 21) return K3();
    //----------
    if (p == 22) return task22();

    cout << "Neteisingas pasirinkimas\n";
    return 0;
}