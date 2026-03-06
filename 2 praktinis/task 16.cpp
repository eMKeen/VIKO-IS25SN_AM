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
#include <iterator>
using namespace std;

int ilgiausiaiTekstas(string _tekstoMasyvas[],int n);
void tbl(int _tekstoIlgis, string _text, int _ilgisLenget, int _eilutesNum, int _kitaEilute);


int task16() {
    // --Masyvai ir kiti--
    string MV[100]; // mokiniu Vardu ir Pavardziu masyvai
    int _uzmt = 0;// index`o uzimtumas
    int PZ[100][10]={0}; //pazymiu masyvas
    string dalykai[10] =
        {
        "Matem", "Fiz", "IT", "Bio", "Kuno K",
        "Geo", "Ist", "Gim K", "Ang K", "Dor U"
        };
    string dalykaiPilnas[] =
        { "Pasirinkite dalyka: ",
        "Matematika", "Fizika", "Informatika", "Biologija", "Kuno Kultura",
        "Geografija", "Istorija", "Gimtoji Kalba", "Anglu Kalba", "Dorinis Ugdymas"
        };
    string _mokinis = "Mokiniai  | No";
    int _ilgisBendras[11] = {0};  //Bazinis lenteles ilgis
    int _ilgisVardu = _mokinis.length();

    int m,p,kt,ms,ms1; // m - mokiniu index`as <> p - pazymiu index`as <> kt - keisti arba trinti index`as
    int i,l;
    int _tekstoIlgis; // Teksto ilgis
    string _text;

    _ilgisBendras[0] = _mokinis.length();
    for (i=0; i<10; i++) {
        _ilgisBendras[0] += dalykai[i].length();
        _ilgisBendras[i+1] = dalykai[i].length();
    }

    // --- Dailykai pilnas transformacija ---
    for (i=1; i<size(dalykaiPilnas); i++) {
        dalykaiPilnas[i] += format(" - {}",i);
    }

    // --- Startas ---

    _text="Mokiniu pazymiu sistema";
    _tekstoIlgis=_text.length();
    tbl(_tekstoIlgis,_text,1,1,-1);

    //---Meniu---

    string MS[] = {
        "Pasirinkite norima operacija:",
        "Ivesti mokiniu vardus ir ju pazymius - 1 ",
        "Perziureti visu mokiniu pazymius - 2 ",
        "Perziureti mokinio pazymius - 3 ",
        "Atnaujinti mokinio pazymi - 4 ",
        "Pasalinti mokini is saraso - 5 ",
        "Nutraukti programa - 0 "
    };

    while (true) {

        int _menuPasir = size(MS);                       //Masyvo ilgis
        _tekstoIlgis = ilgiausiaiTekstas(MS, _menuPasir);// Tikrinimas ilgiausio elemento (vnt)

        int _menuLines = _menuPasir + 3; // Meniu eiluciu kiekis
        for (l=1;l<=_menuLines;l++) {
            if (l == 1 || l == 3 || l == _menuLines) {
                    tbl(_tekstoIlgis,"=",_menuLines,l,0);
                } else if ( l == 2) {
                    tbl(_tekstoIlgis,MS[l-2],_menuLines,l,1);
                } else if (l > 3) {
                    tbl(_tekstoIlgis,MS[l-3],_menuLines,l,1);
            }
        }

        //---Ivestis Meniu----
        cin >> ms;
        while (_uzmt == 0 && ms >= 2 && ms <= 5) {  // tikrinam ar yra ivestis
            cout << format("! - Siometu irasu nera \n"
                           "! - Kad ivesti nauja irasa spauskite - 1\n"
                           "! - Nutraukti programa spauskite - 0") << endl;
            cin >> ms;
        }

        while (true) {
            switch (ms) {
                case 0: {
                    return 0;
                }
                case 1: {
                    //--- Select 1 Meniu -----
                    _text = format("Iveskite kiek mokyniu norite ivesti | Limitas - {}, jau ivesta - {}", 100,_uzmt);
                    _tekstoIlgis=_text.length();
                    tbl(_tekstoIlgis,_text,1,1,-1);
                    cin>>ms1;
                    while (ms1 <1 || ms1>100-_uzmt) {
                        _text = format("Ivedimo intervalas nuo 1 iki {}, pakartokite:",100-_uzmt);
                        _tekstoIlgis=_text.length();
                        tbl(_tekstoIlgis,_text,1,1,-1);
                        cin>>ms1;
                    }
                    if (_uzmt != 0) {
                        ms1 =  ms1 + _uzmt;
                    }
                    for ( m=_uzmt; m<ms1; m++) {
                        cout << format("<<===================>> \n"
                        "Iveskite mokinio varda : ");
                        cin.ignore();
                        getline (cin,MV[m]);
                        if (m+1 < 10) {
                            MV[m] += format("  |  {}",m+1);
                        } else if (m+1 >= 10 && m+1 <100) {
                            MV[m] += format("  | {}",m+1);
                        } else if (m+1 == 100) {
                            MV[m] += format("  |{}",m+1);
                        }
                        _uzmt++;
                        for (p=0; p<10; p++) {
                            cout << format("{} - Iveskite pazymi, dalikas: {} : ",p+1,dalykai[p]);
                            cin>>PZ[m][p];
                            while (PZ[m][p] < 0 || PZ[m][p] > 10) {
                                cout<<"! - Blogai ivestas pazymys, galimi variantai nuo 0 iki 10. Pakartotike : ";
                                cin>>PZ[m][p];
                            }
                        }
                    }
                }break;
                case 2: {
                    //-----Select Maniu 2 ----
                    int _chk = ilgiausiaiTekstas(MV, _uzmt);// Tikrinimas ilgiausio elemento (vnt)

                    //---- Pirmo stulpelio ilgis ir bendras lenteles ilgis ----
                    if (_chk > _ilgisVardu) {
                        _ilgisVardu = _chk;
                        _ilgisBendras[0] += _ilgisVardu - _mokinis.length();
                    }  else if (_ilgisVardu > _mokinis.length() && _chk >= _mokinis.length()) {
                         _ilgisBendras[0] -= _ilgisVardu - _chk;
                    }

                    _menuLines = _uzmt + 4;  // Meniu eiluciu kiekis
                    for (m=1; m<=_menuLines; m++) {
                        if (m == 1 || m == 3 || m == _menuLines) {
                            tbl(_ilgisBendras[0]+40,"=",_menuLines,m,0);
                        } else if (m == 2) {
                            for (p=0; p<11; p++) {
                                if (p == 0) {
                                    tbl(_ilgisVardu,_mokinis,_menuLines,m,0);
                                } else if (p <10) {
                                    tbl(_ilgisBendras[p],dalykai[p-1],_menuLines,m,0);
                                } else if (p == 10) {
                                    tbl(_ilgisBendras[p],dalykai[p-1],_menuLines,m,1);
                                }
                            }
                        } else if (m > 3) {
                            for (p=0; p<11; p++) {
                                if (p == 0) {
                                    tbl(_ilgisVardu,MV[m-4],_menuLines,m,0);
                                } else if (p <10) {
                                    tbl(_ilgisBendras[p],to_string(PZ[m-4][p-1]),_menuLines,m,0);
                                } else if (p == 10) {
                                    tbl(_ilgisBendras[p],to_string(PZ[m-4][p-1]),_menuLines,m,1);
                                }
                            }
                        }
                    }
                    string _wait;
                    cout<<endl;
                    cout<<">>>>Kad testi spauskite ENTER<<<<"<<endl;
                    cin.ignore();
                    getline(cin,_wait);
                }break;
                case 3: {
                    //-----Select Maniu 3 ----
                    _text = format("Iveskite eiles numeri, kuri norite peziureti. Irasu - {}",_uzmt);
                    _tekstoIlgis=_text.length();
                    tbl(_tekstoIlgis,_text,1,1,-1);
                    cin>>ms1;
                    while (ms1 < 1 || ms1 > _uzmt) {
                        _text = format("Ivedimo intervalas nuo 1 iki {}, pakartokite:",_uzmt);
                        _tekstoIlgis=_text.length();
                        tbl(_tekstoIlgis,_text,1,1,-1);
                        cin>>ms1;
                    }

                    int _chk = ilgiausiaiTekstas(MV, _uzmt);// Tikrinimas ilgiausio elemento (vnt)

                    //---- Pirmo stulpelio ilgis ir bendras lenteles ilgis ----
                    if (_chk > _ilgisVardu) {
                        _ilgisVardu = _chk;
                        _ilgisBendras[0] += _ilgisVardu - _mokinis.length();
                    }  else if (_ilgisVardu > _mokinis.length() && _chk >= _mokinis.length()) {
                         _ilgisBendras[0] -= _ilgisVardu - _chk;
                    }

                    _menuLines = 5;  // Meniu eiluciu kiekis - Tik 1 mokinys
                    for (m=1; m<=_menuLines; m++) {
                        if (m == 1 || m == 3 || m == _menuLines) {
                            tbl(_ilgisBendras[0]+40,"=",_menuLines,m,0);
                        } else if (m == 2) {
                            for (p=0; p<11; p++) {
                                if (p == 0) {
                                    tbl(_ilgisVardu,_mokinis,_menuLines,m,0);
                                } else if (p <10) {
                                    tbl(_ilgisBendras[p],dalykai[p-1],_menuLines,m,0);
                                } else if (p == 10) {
                                    tbl(_ilgisBendras[p],dalykai[p-1],_menuLines,m,1);
                                }
                            }
                        } else if (m > 3) {
                            for (p=0; p<11; p++) {
                                if (p == 0) {
                                    tbl(_ilgisVardu,MV[ms1-1],_menuLines,m,0);
                                } else if (p <10) {
                                    tbl(_ilgisBendras[p],to_string(PZ[m-4][p-1]),_menuLines,m,0);
                                } else if (p == 10) {
                                    tbl(_ilgisBendras[p],to_string(PZ[m-4][p-1]),_menuLines,m,1);
                                }
                            }
                        }
                    }
                    string _wait;
                    cout<<endl;
                    cout<<">>>>Kad testi spauskite ENTER<<<<"<<endl;
                    cin.ignore();
                    getline(cin,_wait);

                }break;
                case 4: {
                    //-----Select Maniu 4 ----
                    _text = format("Iveskite mokinio eiles numeri, kurio pazymi norite atnaujinti. Irasu - {}",_uzmt);
                    _tekstoIlgis=_text.length();
                    tbl(_tekstoIlgis,_text,1,1,-1);
                    cin>>ms1;
                    while (ms1 < 1 || ms1 > _uzmt) {
                        _text = format("Ivedimo intervalas nuo 1 iki {}, pakartokite:",_uzmt);
                        _tekstoIlgis=_text.length();
                        tbl(_tekstoIlgis,_text,1,1,-1);
                        cin>>ms1;
                    }

                    _menuPasir = size(dalykaiPilnas);                       //Masyvo ilgis
                    _tekstoIlgis = ilgiausiaiTekstas(dalykaiPilnas, _menuPasir);// Tikrinimas ilgiausio elemento (vnt)

                    _menuLines = _menuPasir + 3; // Meniu eiluciu kiekis
                    for (l=1;l<=_menuLines;l++) {
                        if (l == 1 || l == 3 || l == _menuLines) {
                            tbl(_tekstoIlgis,"=",_menuLines,l,0);
                        } else if ( l == 2) {
                            tbl(_tekstoIlgis,dalykaiPilnas[l-2],_menuLines,l,1);
                        } else if (l > 3) {
                            tbl(_tekstoIlgis,dalykaiPilnas[l-3],_menuLines,l,1);
                        }
                    }
                    cin>>kt;
                    while (kt < 1 || kt > _menuPasir) {
                        _text = format("Ivedimo intervalas nuo 1 iki {}, pakartokite:",_menuPasir-1);
                        _tekstoIlgis=_text.length();
                        tbl(_tekstoIlgis,_text,1,1,-1);
                        cin>>kt;
                    }
                    cout << format("Iveskite nauja pazymi: ");
                    int _naujasPazymis;
                    cin>>_naujasPazymis;
                    PZ[ms1-1][kt-1] = _naujasPazymis;
                    cout << format(">>>>Pazymis sekmingai pakeistas<<<<")<<endl;

                    string _wait;
                    cout<<">>>>Kad testi spauskite ENTER<<<<"<<endl;
                    cin.ignore();
                    getline(cin,_wait);
                }break;
                case 5: {
                    //-----Select Maniu 5 ----
                    _text = format("Iveskite eiles numeri, kuri norite pasalinti. Irasu - {}",_uzmt);
                    _tekstoIlgis=_text.length();
                    tbl(_tekstoIlgis,_text,1,1,-1);
                    cin>>ms1;
                    while (ms1 < 1 || ms1 > _uzmt) {
                        _text = format("Ivedimo intervalas nuo 1 iki {}, pakartokite:",_uzmt);
                        _tekstoIlgis=_text.length();
                        tbl(_tekstoIlgis,_text,1,1,-1);
                        cin>>ms1;
                    }
                    for (i=ms1; i<_uzmt; i++) {
                        if (i < 10) {
                            MV[i-1] = MV[i].erase(MV[i].length() - 3) + format("  {}",i);
                        } else if (i >= 10 && i <100) {
                            MV[i-1] = MV[i].erase(MV[i].length() - 2) + format(" {}",i);
                        } else if (i == 100) {
                            MV[i-1] = MV[i].erase(MV[i].length() - 1) + format("{}",i);
                        }
                        for (l=0; l<10; l++) {
                            PZ[ms1-1][l] = PZ[ms1][l];
                        }
                    }
                    _uzmt--;

                }break;
                default: {
                    _text="Tokio pasirinkimo nera, pakartokite";
                    _tekstoIlgis=_text.length();
                    tbl(_tekstoIlgis,_text,1,1,-1);
                    cin>>ms;
                }break;
            }break;
        }

        //----Pabaiga----

        cout<<endl;
    }
}

int ilgiausiaiTekstas(string _tekstoMasyvas[],int n) {  // Tikrinam ilgiausia teksta

    int _tekstoIlgis = 0;
    for (int i=0; i < n; i++) {
        if (_tekstoIlgis<_tekstoMasyvas[i].length()) {
            _tekstoIlgis = _tekstoMasyvas[i].length();
        }
    }
    return _tekstoIlgis;
}

void tbl(int _tekstoIlgis, string _text, int _ilgisLenget, int _eilutesNum, int _kitaEilute) {
    int i,l;

    if (_kitaEilute == -1) {
        for (l=1;l<=3;l++) {
            if (l==1 || l==3) {
                for (i=0;i<=_tekstoIlgis+6;i++) {
                    cout<<"=";
                }
                cout<<endl;
            } else {
                cout<<"|  "<<setw(_tekstoIlgis)<<_text<<"   |"<<endl;
            }
        }
    }

    if (_kitaEilute > -1) {
        if (_eilutesNum==1 || _eilutesNum==3 || _eilutesNum==_ilgisLenget) {
            for (i=0;i<_tekstoIlgis+4;i++) {
                cout<<"=";
            }
            cout<<endl;
        } else {
            if (_kitaEilute == 0) {
                cout<<"| "<<setw(_tekstoIlgis)<<_text<<" |";
            } else {
                cout<<"| "<<setw(_tekstoIlgis)<<_text<<" |";
                cout<<endl;
            }
        }
    }
}