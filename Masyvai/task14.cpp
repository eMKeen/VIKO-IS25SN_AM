/*Tyrime dalyvavo 40 studentų. Jiems buvo duotas žaisti toks pats
 *kompiuterinis žaidimas ir paprašyta jį įvertinti nuo 1 iki 10 balų.
 *Patalpinti atsakymus į masyvą ir gauti apklausos rezultatus.
 *T.y. koks vertinimas kiek kartų pasikartojo.*/

#include <iostream>
using namespace std;

int task14() {

    int mas[40],i;
    int sk[10]={0};

    for (i = 0; i < 40; i++) {
        cout<<"Eiles numeris: "<<i+1<<endl;
        cout<<"Iveskite ivertinimo bala nuo 1 iki 10"<<endl;
        cin>>mas[i];
        while (mas[i]<1 || mas[i]>10) {
            cout<<"Blogai ivestas ivertinimas. Pakartokite dar karta"<<endl;
            cin>>mas[i];
        }
    }
    for (i = 0; i < 40; i++) {
        if (mas[i] <= 10 && mas[i] >0) {
            sk[mas[i]-1]++;
        }
    }
    cout<<"Pasikartojusiuju skaiciu kiekis:"<<endl;
    for (i = 0; i < 10; i++) {
        if (sk[i] >0) {
            cout<<"Ivertinimo "<<i+1<<" pasikartojo: "<<sk[i]<<" kartu"<<endl;
        }
    }
    return 0;
}