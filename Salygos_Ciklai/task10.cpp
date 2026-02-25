/*Parašykite programą, kuri apskaičiuotų visų nelyginių skaičių sumą intervale [1; 20]*/
#include <iostream>
#include <iomanip>

using namespace std;

int task10() {

    int x1,x2,d,i;
    d=0;
    cout<<"Iveskite nuo kokio skaiciaus pradeti skaiciuoti:"<<endl;
    cin>>x1;
    cout<<"Iveskite iki kokio skaiciaus skaiciuoti"<<endl;
    cin>>x2;

    for (i=x1;i<=x2;i++) {

        if (i%2 != 0) {
            d=d+i;
        }
    }
    cout<<"Ivestu skaiciu suma:"<<d<<endl;
    return 0;
}