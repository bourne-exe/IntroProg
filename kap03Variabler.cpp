#include <iostream>
#include <string>
#include <cmath>
#include <string>

using namespace std;

// 3.3
void provaTilldelning(){
    int x{10};
    int y{20};

    x = y;
    cout << "x är" << x << " och y är " << y << endl;
    y = 100;
    cout << "x är" << x << " och y är " << y << endl;
}

// 3.5
void lasOchBytVarden(){
    cout << "Ange x:" << endl;
    int x;
    cin >> x;
    cout << "Ange y:" << endl;
    int y;
    cin >> y;
    cout << "x är " << x << " och y är " << y << endl;
    cout << " Nu byter värderna med varandra!" << endl;
    cout << "x är " << y << " och y är " << x << endl;
}

// 3.6.1
void SagHej(){
    cout << "Ange ditt förnamn;" << endl;
    string fornamn;
    cin >> fornamn;
    cout << "Tack " << fornamn << ", ange nu ditt efternamn:" << endl;
    string efternamn;
    cin >> efternamn;
    cout << "Hej " << fornamn << " " << efternamn << endl;
}