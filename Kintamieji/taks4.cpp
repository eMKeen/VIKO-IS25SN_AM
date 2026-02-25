/*Susikurkite tris kintamuosius, du sveikuosius kintamuosius a = 13, b = 5
 ir vieną skaičių per kablelį c = 17.5. Išveskite informaciją į konsolę:

cout << a + b – c << endl;
cout << 15 / 2 + c << endl;
cout << a / static_cast<double>(b) + 2 * c << endl;
cout << 14 % 3 + 6.3 + b / a << endl;
cout << static_cast<int>(c) % 5 + a – b << endl;
cout << 13.5 / 2 + 4.0 * 3.5 + 18 << endl;
*/
#include <iostream>

using namespace std;

int task4() {
 int a,b;
 double c;
 a = 13;
 b = 5;
 c = 17.5;

 cout << a + b - c << endl;
 cout << 15 / 2 + c << endl;
 cout << a / static_cast<double>(b) + 2 * c << endl;
 cout << 14 % 3 + 6.3 + b / a << endl;
 cout << static_cast<int>(c) % 5 + a - b << endl;
 cout << 13.5 / 2 + 4.0 * 3.5 + 18 << endl;

 return 0;
}