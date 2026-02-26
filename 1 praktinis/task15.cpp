/*Valiutos keityklos užduotis

Parašykite programą, kuri keičia valiutą į kitą pasirinktą valiutą.

Valiutos keityklos programėlė turi tris pasirinkimus:

    Valiutos kurso palyginimas su kita valiuta. (2 taškai)
    Galimybė įsigyti valiutos (t. y. pirkti valiutą). (2 taškai)
    Galimybė parduoti valiutą (t. y. parduoti valiutą). (2 taškai)

Pagrindinė valiuta yra euras (EUR), todėl konvertavimas galimas:

    iš eurų į pasirinktą valiutą,
    arba atvirkščiai – iš pasirinktos valiutos į eurus.

Vartotojas pasirenka:

    kokią pasirinkimą naudos (palyginti, pirkti ar parduoti);
    valiutą;
    įveda valiutos kiekį, kurį nori pirkti arba parduoti.

Po paskaičiavimų vartotojas ekrane turi pamatyti, kokį kiekį gaus valiutos. (2 taškai)

Skaičiai turi būti apvalinti šimtųjų tikslumu. (1 taškas)

Užduotį atlikite iki vasario 27 d. Kodas turi būti patalpintas į GitHub’ą, atlikti mažiausiai tris atnaujinimus (git add ., git commit, git push). (1 taškas)

Papildoma informacija

Programėlė gali konvertuoti keturias valiutas:

    Eurą (EUR)
    Didžiosios Britanijos svarą (GBP)
    Jungtinių Amerikos Valstijų dolerį (USD)
    Indijos rupiją (INR)

Valiutų konvertavimo pavyzdžiai

Svarbu: kaina nurodyta, kiek už 1 eurą gauname pasirinktos valiutos.

Pvz.:

    jeigu vartotojas nori nusipirkti Didžiosios Britanijos svarų ir duoda 1 €, jis gaus 0,86 £,
    jeigu vartotojas nori parduoti 1 £, jis gaus 0,922 €.

Valiutų kursai

GBP_Bendras   = 0.8729;
GBP_Pirkti    = 0.8600;
GBP_Parduoti  = 0.9220;
USD_Bendras   = 1.1793;
USD_Pirkti    = 1.1460;
USD_Parduoti  = 1.2340;
INR_Bendras   = 104.6918;
INR_Pirkti    = 101.3862;
INR_Parduoti  = 107.8546;*/

#include <iostream>
#include <string>
#include <format>
#include <iomanip>
using namespace std;

int task15() {
    while (true) {

        //--Valiutos kintamieji masyvai--
        //--0-> Bendras; 1->Pirkti; 2->Parduoti
        double GBB[3]={0.8729,0.8600,0.9220};
        double USD[3]={1.1793,1.1460,1.2340};
        double INR[3]={104.6918,101.3862,107.8546};
        double EUR[3]={1,1,1};
        double VP[3]={0}; //--Valiutos pasirinkimo kintamasis
        double VK[2]={0}; //--Valiutos kiekis
        int v1,v2; //--Valiutos pasirinkimo kintamasis, 1 - turima valiuta, 2 - i kuria konvertuosime--
        string ATS[4]={"GBP","USD","INR","EUR"};

        int p; //--Pasirinkimo kintamasis--
        cout<<"--Valiutos keityklos programele--"<<endl;
        cout<<" --Pasrinkite norima operacija--\n"<<endl;
        cout<<" 1: Valiutos kurso palyginimas su kita valiuta."<<endl;
        cout<<" 2: Galimybe isigyti valiutos"<<endl;
        cout<<" 3: Galimybe parduoti valiuta\n"<<endl;
        cout<<" Iveskite Jusu pasirinkima: "<<endl;
        cin>>p;
        while (p<1 || p>3) {
            cout<<"--Tokio pasirinkimo nera--"<<endl;
            cout<<"--Pakartokite pasirinkima--\n"<<endl;
            cin>>p;
        }

        cout<<"--Pasirinkite turima valliuta--"<<endl;
        cout<<" 1: Didziosios Britanijos svara (GBP)"<<endl;
        cout<<" 2: Jungtiniu Amerikos Valstiju doleri (USD)"<<endl;
        cout<<" 3: Indijos rupija (INR)"<<endl;
        cout<<" 4: Eura (EUR)"<<endl;
        cin>>v1;
        while (v1<1 || v1>4) {
            cout<<"--Tokio pasirinkimo nera--"<<endl;
            cout<<"--Pakartokite pasirinkima--\n"<<endl;
            cin>>v1;
        }

        cout<<"\nValiutos kieki:"<<endl;
        cin>>VK[0];

        if (v1==4) {
            cout<<"\n--Pasirinkite valiuta su kuria norite atlikti pasirinkta operacija--"<<endl;
            cout<<" 1: Didziosios Britanijos svara (GBP)"<<endl;
            cout<<" 2: Jungtiniu Amerikos Valstiju doleri (USD)"<<endl;
            cout<<" 3: Indijos rupija (INR)"<<endl;
            while (true) {
                cin>>v2;
                switch(v2) {
                    case 1:
                        for (int i=0;i<3;i++) {
                            VP[i]=GBB[i];
                        } break;
                    case 2:
                        for (int i=0;i<3;i++) {
                            VP[i]=USD[i];
                        } break;
                    case 3:
                        for (int i=0;i<3;i++) {
                            VP[i]=INR[i];
                        }break;
                    default:
                        cout<<"Tokio pasirinkimo nera"<<endl;
                        cout<<"--Pakartokite pasirinkima--\n"<<endl;
                        continue;
                }break;
            }
        } else {
            switch(v1) {
                case 1:
                    for (int i=0;i<3;i++) {
                        VP[i]=GBB[i];
                    } break;
                case 2:
                    for (int i=0;i<3;i++) {
                        VP[i]=USD[i];
                    } break;
                case 3:
                    for (int i=0;i<3;i++) {
                        VP[i]=INR[i];
                    }break;
                default:
                    break;
            }
        }

        if (v1==4) {
            cout<<"--->JUSU UZKLAUSOS REZULTATAS<<---"<<endl;

            switch (p) {
                case 1:
                    VK[1]=VK[0]*VP[p-1];
                    cout<<format("Jusu {0:.2f} {1} atitinka {2:.2f} {3}",VK[0],ATS[v1-1],VK[1],ATS[v2-1]);
                    break;
                case 2:
                    VK[1]=VK[0]*VP[p-1];
                    cout<<format("Uz {0:.2f} {1} Galesite isigyti {2:.2f} {3}",VK[0],ATS[v1-1],VK[1],ATS[v2-1]);
                    break;
                case 3:
                    VK[1]=VK[0]/(EUR[0]/VP[p-1]);
                    cout<<format("Jusu {0:.2f} {1} galesite parduoti uz {2:.2f} {3}",VK[0],ATS[v1-1],VK[1],ATS[v2-1]);
                    break;
                default:
                    break;
            }
        } else {
            cout<<"--->JUSU UZKLAUSOS REZULTATAS<<---"<<endl;

            switch (p) {
                case 1:
                    VK[1]=VK[0]/VP[p-1];
                    cout<<format("Jusu {0:.2f} {1} atitinka {2:.2f} {3}",VK[0],ATS[v1-1],VK[1],ATS[3]);
                    break;
                case 2:
                    VK[1]=VK[0]/VP[p-1];
                    cout<<format("Uz {0:.2f} {1} Galesite isigyti {2:.2f} {3}",VK[0],ATS[v1-1],VK[1],ATS[3]);
                    break;
                case 3:
                    VK[1]=VK[0]/VP[p-1];
                    cout<<format("Jusu {0:.2f} {1} galesite parduoti uz {2:.2f} {3}",VK[0],ATS[v1-1],VK[1],ATS[3]);
                    break;
                default:
                    break;
            }
        }

        int REP; //--Programojs kartojimas
        cout<<"\n.............................."<<endl;
        cout<<"Ar norite pakartoti operacija?\n"<<endl;
        cout<<"Iveskite : 1 - Kartoti"<<endl;
        cout<<"Iveskite : 2 - Iseiti"<<endl;
        cin>>REP;

        while (REP>2 || REP<1) {
            cout<<"--Tokio pasirinkima--"<<endl;
            cout<<"--Pakartokite pasirinkima--\n"<<endl;
            cin>>REP;
        }
        if (REP==2) {return 0;}
    }
}