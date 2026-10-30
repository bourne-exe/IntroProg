#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void ingangTillFunkInUt(){
    cout << endl << "ingangTillFunkInUt....." << endl;
}

// 4.1
void skrivHypotenusa(double x, double y){
    double rKvadrat = x*x + y*y;
    double r = sqrt( rKvadrat );
    cout << "x är " << x << " och y är " << y << "." << endl
         << "Summan av kvadraterna blir " << rKvadrat << endl
         << "Vilket gör att hypotenusans längd blir " << r << endl;
}

void provaHypotenusa(){
    cout << "provaHypotenusa " << endl;

    double a = 1;
    double b = 2;
    skrivHypotenusa(a,b);

    double x = 2;
    double y = 3;
        skrivHypotenusa(y,x);
    skrivHypotenusa(30,40);
}