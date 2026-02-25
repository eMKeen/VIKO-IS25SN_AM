/*Susikurkite kelis kintamuosius studento pažymiams vertinti.
 *Raskite studento pažymių vidurkį.
 *Patikrinkite ar pažymių vidurkis yra teigiamas (daugiau arba lygu 5-iems).
 *Jeigu vidurkis teigiamas išveskite "Vidurkis teigiamas".
 *Naudokite tik sąlygos operatoių "if".*
 * Papildykite pirmą uždavinį sąlygos operatoriumi "if-else".
 * Jeigu pažymių vidurkis yra neigiamas išveskite "Vidurkis yra neigiamas".
 */
#include <iostream>
#include <iomanip>
using namespace std;

int task7() {

    double x,x1,x2,x3,x4;

    cout<<"Iveskite pirmo dalyko pazymi:"<<endl;
    cin>>x1;
    cout<<"Iveskite antro dalyko pazymi:"<<endl;
    cin>>x2;
    cout<<"Iveskite trecio dalyko pazymi:"<<endl;
    cin>>x3;
    cout<<"Iveskite ketvirto dalyko pazymi:"<<endl;
    cin>>x4;

    x = (x1+x2+x3+x4)/4;

    if (x - static_cast<int>(x) >= 0.45) {
        x = static_cast<int>(x+1);
    }
    else {
        x = static_cast<int>(x);
    }

    if (x>=5 && x<=10){
        cout<<"Studento pazymiu vidurkis yra teigiamas ir yra: "<<x<<endl;
    }
    else {
        if (x>=0 && x<5){
            cout<<"Studento pazymiu vidurkis yra neigiamas ir yra: "<<x<<endl;
        }
        else {
            cout<<"Jus ivesti skaiciai yra klaidingi"<<endl;
        }
    }
    return 0;
}