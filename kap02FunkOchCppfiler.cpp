#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace this_thread;
using namespace chrono;

// 2.2
void raknaTillTre(){
    sleep_for ( milliseconds ( 500 ) );
    cout << "Ett" << endl;
    sleep_for ( milliseconds ( 500 ) );
    cout << "Två" << endl;
    sleep_for ( milliseconds ( 500 ) );
    cout << "Tre" << endl;
    sleep_for ( milliseconds ( 500 ) );
}

void raknaTillFyra(){
    raknaTillTre();
    cout << "Fyra" << endl;
}

// 2.5
void ingangTillFunkOchCppfiler(){
    cout << "Räkna första gången!" << endl;
    raknaTillTre();
    cout << "Räkna en gång till fyra" << endl;
    raknaTillFyra();
}