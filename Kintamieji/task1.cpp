/*Sukurkite kintamuosius ir jiems priskirkite informaciją apie studentą:
Vardas, Pavardė, Amžius, Grupė,
Kursas, Studijų programos pavadinimas.
Išveskite informaciją apie studentą.  */

#include <iostream>
#include <string>
#include <format>
#include <iomanip>
using namespace std;

int task1 () {
    int A, K;
    string vardasPavarde, grupeNum, studProgPav;

    cout <<"Iveskite Varda Pavarde: "<< endl;
    getline(cin, vardasPavarde);
    cout <<"Iveskite Grupes Koda: "<<endl;
    getline(cin, grupeNum);
    cout <<"Iveskite Studiju programos pavadinima: "<< endl;
    getline(cin, studProgPav);
    cout <<"Iveskite Jusu amziu: "<<endl;
    cin >> A;
    cout <<"Iveskite Jusu Kurso numeri: "<<endl;
    cin >> K;
    cout<<format("Vardas Pavarde: {0}\nJums yra metu: {1}\nJusu grupe: {2}\nKursas: {3}\nStudiju programos pavadinimas: {4}",vardasPavarde,A,grupeNum,K,studProgPav);
    return 0;
}