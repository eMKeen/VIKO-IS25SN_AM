/*Susikurkite penkis kintamuosius skaičiams saugoti ir įveskite juos.
 *Išveskite šių skaičių vidurkį. Nusibraižykite šiai realizacijai blokinę schemą.*/
#include <iostream>
#include <iomanip>
using namespace std;

int task5() {

    int x1,x2,x3,x4,x5;
    double x;

    cout<<">>Iveskite 5 skaicius<<"<<endl;
    cout<<"Iveskite 1 skaiciu:"<<endl;
    cin >> x1;
    cout<<"Iveskite 2 skaicius:"<<endl;
    cin >> x2;
    cout<<"Iveskite 3 skaicius:"<<endl;
    cin >> x3;
    cout<<"Iveskite 4 skaicius:"<<endl;
    cin >> x4;
    cout<<"Iveskite 5 skaicius:"<<endl;
    cin >> x5;

    x = (x1+x2+x3+x4+x5)/5;

    cout<<"Vidurkis ivestu skaiciu yra:"<<x<<endl;

return 0;
}