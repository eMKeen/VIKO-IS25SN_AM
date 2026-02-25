/*Klientas padėjo 1000€ indėlį į banką su 5% metinių palūkanų. Kokią pinigų sumą jis gaus po 10 metų. */
#include <iostream>
#include <iomanip>
using namespace std;

int task11() {

    double x1;
    int i,m;

    cout<<"Iveskite kokia indelio suma:"<<endl;
    cin>>x1;
    cout<<"Iveski nuomatytu metu kieki:"<<endl;
    cin>>m;

    for (i=1;i<=m;i++) {
        x1=x1+x1/20;
        cout<<"metai - "<<i-1<<" per kurios yra - "<<x1<<" pinigu"<<endl;
    }
    cout<<"Per "<<m<<" metus, jus sukaupsite "<<x1<<" pinigu"<<endl;
    return 0;
}