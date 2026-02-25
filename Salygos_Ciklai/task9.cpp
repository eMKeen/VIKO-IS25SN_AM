/*Trečią (task8) užduotį perrašykite naudodami jungiklio operatorių "switch".*/
#include <iostream>
#include <iomanip>
using namespace std;

int task9() {

    int x;
    cout<<"Iveskite egzamino ivertinima"<<endl;
    cin>>x;

    switch (x) {
        case 10:
            cout<<"Puikiai";
            break;
        case 9:
            cout<<"Labai gerai";
        case 8:
        case 7:
            cout<<"Gerai";
            break;
        case 6:
        case 5:
            cout<<"Patenkinamai";
            break;
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            cout<<"Egzaminas neislaikytas";
            break;
        default:
            cout<<"Pazymis blogai ivestas";
    }
    return 0;
}