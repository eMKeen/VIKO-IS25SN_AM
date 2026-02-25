
/*Sukurkite kintamuosius, saugančią informaciją apie automobilį:
 *markė, modelis, pagaminimo metai, litražas ir spalva.
 *Išveskite šiuos duomenis suformatuotus vienoje eilutėje.
 *Pvz.: Automobilis OPEL ZAFIRA yra pagamintas 2010 metais.
 *Jo motoras 2.0 llitrazo. Automobilis yra sidabrinės spalvos.*/
#include <iostream>
#include <string>
#include <format>
using namespace std;

int task3() {
    string marke, modelis, pagamMetai, litraz, spalva;
    marke = "Skoda";
    modelis = "Kodiaq";
    pagamMetai = "2021";
    litraz = "2.0";
    spalva = "Pilkos";

    cout<<format("Automobilis {0} {1} yra pagamintas {2} metais. "
                 "Jo motoras {3} litrazo. Automobilis yra {4} spalvos.",
                 marke,
                 modelis,
                 pagamMetai,
                 litraz,
                 spalva);
    return 0;
}
