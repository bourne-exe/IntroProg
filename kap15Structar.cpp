#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

struct Vaxel3{
    int m_antal500;
    int m_antal200;
    int m_antal100;
    int m_antal20;
    int m_antal10;
    int m_antal5;
    int m_antal1;
};

//15.2

Vaxel3 vaxel3FranAntal(int a500, int a200, int a100, int a20, int a10, int a5, int a1){
    Vaxel3 antal;
    antal.m_antal500 = a500;
    antal.m_antal200 = a200;
    antal.m_antal100 = a100;
    antal.m_antal20 = a20;
    antal.m_antal10 = a10;
    antal.m_antal5 = a5;
    antal.m_antal1 = a1;
    return antal;
}

Vaxel3 vaxel3FranBelopp(int belopp){
    Vaxel3 v;
    v.m_antal500 = belopp/500;
    belopp = belopp % 500;
    v.m_antal200 = belopp/200;
    belopp = belopp % 200;
    v.m_antal100 = belopp/100;
    belopp = belopp % 100;
    v.m_antal20 = belopp/20;
    belopp = belopp % 20;
    v.m_antal10 = belopp/10;
    belopp = belopp % 10;
    v.m_antal5 = belopp/5;
    belopp = belopp % 5;
    v.m_antal1 = belopp/1;
    return v;
}

int beloppFranVaxel(const Vaxel3& vaxel){
    return vaxel.m_antal500*500 + vaxel.m_antal200*200 + vaxel.m_antal100*100 + vaxel.m_antal20*20 + vaxel.m_antal10*10 + vaxel.m_antal5*5 + vaxel.m_antal1*1;
}

void skrivUtVaxel(const Vaxel3& vaxel){
    cout << vaxel.m_antal500 << "st 500-sedlar" << endl;
    cout << vaxel.m_antal200 << "st 200-sedlar" << endl;
    cout << vaxel.m_antal100 << "st 100-sedlar" << endl;
    cout << vaxel.m_antal20 << "st 20-sedlar" << endl;
    cout << vaxel.m_antal10 << "st 10-sedlar" << endl;
    cout << vaxel.m_antal5 << "st 5-sedlar" << endl;
    cout << vaxel.m_antal1 << "st 1-sedlar" << endl;
}

bool arLika(const Vaxel3 &v1, const Vaxel3 &v2){
    return v1.m_antal500 == v2.m_antal500 && v1.m_antal200 == v2.m_antal200 && v1.m_antal100 == v2.m_antal100 && v1.m_antal20 == v2.m_antal20 && v1.m_antal10 == v2.m_antal10 && v1.m_antal5 == v2.m_antal5 && v1.m_antal1 == v2.m_antal1;
}

void skrivUtVaxelV3(int belopp){
    skrivUtVaxel(vaxel3FranBelopp(belopp));
}
