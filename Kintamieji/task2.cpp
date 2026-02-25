/*Sukurkite kintamuosius ir jiems priskirkite informaciją apie krepšinio/futbolo klubą
 *(pvz.: Kauno Žalgiris, Vilniaus Rytas, Madrido Real, Londono Arsenalas):
 *Pavadinimas, Įkūrimo metai, Savinininkas, Arena (gali būti stadionas),
 *Vietų skaičius.
 *Išveskite informaciją apie sporto klubą.*/
#include <iostream>
#include <string>
#include <format>
using namespace std;
int task2 () {
    string kluboPavadinimas, ikurimoMetai, savininkas, arena;

    kluboPavadinimas = "Vilniaus Rytas";
    ikurimoMetai = "2001.02.15";
    savininkas = "Jonas Jonaitis";
    arena = "Vilniaus Ryto";

    int vietuSkaicius = 650;

    cout<<format(
        "Klubo pavadinimas: {0}\n\n "
                "Ikurimo metai: {1}\n\n "
                "Savininkas: {2}\n\n "
                "Arenos pavadinimas: {3}\n\n "
                "Vietu Skaicius: {4}\n\n ",
                kluboPavadinimas,
                ikurimoMetai,
                savininkas,
                arena,
                vietuSkaicius
    );
    return 0;
}