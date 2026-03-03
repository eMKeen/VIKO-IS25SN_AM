/*Užduotis „Mokinių pažymių sistema“

Tikslas:

Sukurti C++ programą, kuri leidžia vartotojui:

    Įvesti mokinių vardus ir jų pažymius.
    Peržiūrėti visų mokinių arba konkretaus mokinio pažymius.
    Atnaujinti konkretų pažymį konkrečiam mokiniui.
    Pašalinti mokinį iš sąrašo.

Reikalavimai:

    Naudoti du masyvus: vienmatis masyvas skirtas mokinių vardams saugoti,
    dvimatis masyvas skirtas pažymiams: eilutės – mokiniai, stulpeliai – pažymiai.
    Leisti į masyvą įvesti iki 100 mokinių, kiekvienas iš jų gali turėti iki 10 pažymių.
    Naudoti ciklus ir sąlyginius sakinius duomenų valdymui.
    Sukurti paprastą meniu, leidžiantį vartotojui pasirinkti veiksmą.
*/

#include <iostream>
#include <string>
#include <format>
#include <iomanip>
using namespace std;

int task16() {
    while (true) {

        // --Masyvai--
        string MV[100]; // mokyniu Varbu ir Pavardziu masyvai
        int PZ[100][10]={0}; //pazymiu masyvas
        int m,p,kt; // m - mokyniu index`as <> p - pazymiu index`as <> kt - keisti arba trinti index`as
        int i,j,l,tl;

        string tx;

        tx="Mokiniu pazymiu sistema";
        tl=tx.length();

        for (l=1;l<=3;l++) {
            if (l==1 || l==3) {
                for (i=0;i<=tl+6;i++) {
                    cout<<"=";
                }
            } else {
                for (j=1;j<=tl+6;j++) {
                    if (j==1) {
                        cout<<endl;
                        cout<<"|";
                    } else if (j==tl+6) {
                        cout<<"|"<<endl;
                    } else if ( j<4 || j>tl+3) {
                        cout<<" ";
                    } else if (j==4) {
                        cout<<tx;
                    }
                }
            }
        }
        return 0;
    }
}