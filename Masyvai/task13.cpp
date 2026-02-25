/*Parašykite programą, kurioje naudotojas įveda 5 sveikuosius skaičius
 *ir juos išsaugo masyve. Programa turi apskaičiuoti visų masyvo elementų sumą,
 *rasti didžiausią ir mažiausią elementą masyve. Į atsakymų lauką turi būti atspausdinta suma,
 *didžiausias ir mažiausias masyvo elementas.*/

#include <iostream>
#include <iomanip>
using namespace std;

int task13 () {

    int masyvas[5],i,d,s;
    for (i=0;i<5;i++) {
        cout<<"Iveskite "<<i+1<<" masyvo skaiciu"<<endl;
        cin>>masyvas[i-1];
    }
    d=masyvas[0];
    s=masyvas[0];
    for (i=0;i<5;i++) {
        if (d<masyvas[i-1]) {
            d=masyvas[i-1];
        } else if (s>=masyvas[i-1]) {
            s=masyvas[i-1];
        }
    }
    cout<<"Didziausias masyvo skaicius yra: "<<d<<endl;
    cout<<"Maziausiais masyvo skaicius yra: "<<s<<endl;
    return 0;
}