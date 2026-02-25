/*Sunkesnis: Įveskite dviženkli skaičių ir raskite jo skaitmenų sumą.
 *Skaitmenų sumai rasti naudokite tik matematinius veiksmus.
 *Nusibraižykite šiai realizacijai blokinę schemą. */
#include <iostream>
#include <iomanip>
using namespace std;

int task6() {

    int a;
    cout<<"Iveski dvizenkli skaiciu nuo 10 iki 99"<<endl;
    cin >> a;

    if (a<100 && a>9) {
        cout<<"Jusu ivesto skaiciaus skaitmenu suma ligi:"<<endl;
        cout<< a/10+a%10<<endl;
    }
    else {
        cout<<"Jusu Ivestas skaicius virsija numatytas ribas"<<endl;
    }
return 0;
}