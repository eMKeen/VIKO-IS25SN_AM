/*Parašykite programą, kurioje naudotojas įveda 5 sveikuosius skaičius
 *ir juos išsaugo masyve. Programa turi apskaičiuoti visų masyvo elementų sumą,
 *rasti didžiausią ir mažiausią elementą masyve. Į atsakymų lauką turi būti atspausdinta suma,
 *didžiausias ir mažiausias masyvo elementas.*/

#include <iostream>
#include <iomanip>
using namespace std;

int task13 () {

    int masyvas[5],i,d[2];
    for (i=0;i<5;i++) {
        cout<<"Iveskite "<<i+1<<" masyvo skaiciu"<<endl;
        cin>>masyvas[i-1];
    }
    d[0]=masyvas[0];
    d[1]=masyvas[0];
    int s=0;
    for (i=0;i<5;i++) {
        s=s+masyvas[i];
        if (d[0]<masyvas[i-1]) {
            d[0]=masyvas[i-1];
        } else if (d[1]>=masyvas[i-1]) {
            d[1]=masyvas[i-1];
        }
    }
    cout<<"Didziausias masyvo skaicius yra: "<<d[0]<<endl;
    cout<<"Maziausiais masyvo skaicius yra: "<<d[1]<<endl;
    cout<<"Visu skaiciu suma: "<<s<<endl;
    return 0;
}