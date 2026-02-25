/*Susikurkite kintamąjį egzamino įvertinimui saugoti.
 *Naudojant įdėtinės sąlygos operatorių "else if" patikrinkite šias sąlygas
 *iš išveskite atitinkamą įvertinimą žodžiais: jei pažymys yra lygus 10 išvesti "puiku";
 *jei pažymys lygus arba didesnis nei 9 išvesti "labai gerai";
 *jei pažymys yra lygus arba didesnis nei 7 išvesti "gerai";
 *jei pažymys yra lygus arba didesnis nei 5 išvesti "patenkinamai";
 *jei pažymys mažesnis nei 5 išvesti "egzaminas neišlaikytas*/

#include <iostream>
#include <iomanip>
using namespace std;

int task8() {
    double x;
    cout<<"Iveskite egzamino ivertinima"<<endl;
    cin>>x;

if (x<0 || x>10) {
    cout<<"Pazymis yra blogai ivestas"<<endl;
    } else if (x<5) {
        cout<<"Jusu ivertinimas: Egzaminas neislaikytas"<<endl;
        } else if (x<7) {
            cout<<"Jusu ivertinimas: Patenkinamai"<<endl;
        } else if (x<9) {
            cout<<"Jusu ivertinimas: Gerai"<<endl;
        } else if (x<10) {
            cout<<"Jusu ivertinimas: Labai gerai"<<endl;
        } else {
            cout<<"Jusu ivertinimas: Puikiai"<<endl;
        }
return 0;
}