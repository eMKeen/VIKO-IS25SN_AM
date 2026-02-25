/*Parašyti for ciklą, kuris eitų per kiekvieną skaičių nuo 1 iki 20. Jame apsirašyti sąlygos operatorių "if",
 *kuris patikrintų ar dabartinis skaičius dalinasi iš 4, jei taip tai šį skaičių išvesti.*/
#include <iostream>
#include <iomanip>

using namespace std;

int task12() {

    int x1,x2,i;

    cout<<"Iveskite nuo kokio skaiciaus pradeti analizuoti:"<<endl;
    cin>>x1;
    cout<<"Iveskite iki kokio skaiciaus analizuoti"<<endl;
    cin>>x2;

    for (i=x1;i<=x2;i++) {

        if (i%4 == 0) {
            cout<<"Skaicius - "<<i<<" dalinasi is 4, atsakimas: "<<i/4<<endl;
        }
    }
    return 0;
}