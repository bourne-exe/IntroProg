#include <iostream>

using namespace std;

// TO DO


// 9.1.1
int GLOBAL_VARIABEL {0};
void funkC (){
    int x {7};
    cout << "funkC : x är " << x << endl;
    cout << "funkC: x lagras på adress " << &x << endl;
    cout << "funkC : GLOBAL_VARIABEL är " << GLOBAL_VARIABEL << endl ;
    GLOBAL_VARIABEL = 77;
}
void funkB(){
    int x{5};
    GLOBAL_VARIABEL = 15;
    cout << "funkB: x är " << x << endl ;
    cout << "funkB: x lagras på adress " << &x << endl;
    cout << "funkB: GLOBAL_VARIABEL är " << GLOBAL_VARIABEL << endl ;
    funkC ();
    cout << "funkB: x är " << x << endl ;
    cout << "funkB: GLOBAL_VARIABEL är " << GLOBAL_VARIABEL << endl ;
}
void funkA(){
    funkB ();
    funkC ();
    cout << "funkA: GLOBAL_VARIABEL lagras på adress " << &GLOBAL_VARIABEL << endl;
}


// 9.4.1
void anvandStatic(){
    static int a = 42;
    cout << "först " << a << " ";
    a=108;
    cout << "sedan " << a << endl;
}

void provaStatic(){
    anvandStatic();
    anvandStatic();
}

void ingangTillMerOmVariabler(){
    cout << endl << " ingangTillMerOmVariabler ......." << endl;
}

// TO DO

