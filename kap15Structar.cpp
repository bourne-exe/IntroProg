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

//15.3
struct Datum{
    int m_ar;
    int m_manad;
    int m_dag;
};

Datum datumFranAMD(int ar, int manad, int dag){
    Datum v;
    v.m_ar = ar;
    v.m_manad = manad;
    v.m_dag = dag;
    return v;
}

int arSkottar(int ar){
    if (ar % 4 == 0 && ar % 100 != 0 || ar % 400 == 0)
        return true;
    else return false;
}

int antalDagarIManad(int manad, int ar){
    switch(manad){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2: if(arSkottar(ar))
                return 29;
            return 28;
    }
    return 0;
}

bool arEttTillatetDatum(const Datum& datum){
    if (datum.m_manad < 1 || datum.m_manad > 12)
        return false;
    if (datum.m_dag<1)
        return false;
    if (antalDagarIManad(datum.m_manad, datum.m_ar)>datum.m_dag)
        return false;
    return true;
}

Datum nastaDagsDatum(const Datum& datum){
    Datum nasta = datum;
    nasta.m_dag++;
    if (antalDagarIManad(datum.m_manad, datum.m_ar)<nasta.m_dag){
        nasta.m_dag = 1;
        nasta.m_manad++;
    }
    if (nasta.m_manad > 12){
        nasta.m_manad = 1;
        nasta.m_ar++;
    }
    return nasta;
}

Datum foregaendeDagsDatum(const Datum& datum){
    Datum foregaende = datum;
    foregaende.m_dag--;
    if (foregaende.m_dag == 0){
        foregaende.m_manad--;
    }
    if (foregaende.m_manad == 0){
        foregaende.m_manad = 12;
        foregaende.m_ar--;
    }
    if(foregaende.m_dag == 0)
        foregaende.m_dag = antalDagarIManad(foregaende.m_manad, foregaende.m_ar);
    return foregaende;
}

Datum datumEfterXDagar(const Datum& datum, int x){
    Datum resultat = datum;
    if (x > 0){
        for (int i=0; i<x; i++){
            resultat = nastaDagsDatum(resultat);
        }
    }else if (x < 0){
        for (int i=0; i<-x; i++){
            resultat = foregaendeDagsDatum(resultat);
        }
    }
    return resultat;
}

bool arLikaDatum(const Datum& d1, const Datum& d2){
    return d1.m_ar == d2.m_ar && d1.m_manad == d2.m_manad && d1.m_dag == d2.m_dag;
}

bool arMindreDatum(const Datum& d1, const Datum& d2){
    if(d1.m_ar != d2.m_ar)
        return d1.m_ar<d2.m_ar;
    if(d1.m_manad != d2.m_manad)
        return d1.m_manad<d2.m_manad;
    if(d1.m_dag != d2.m_dag)
        return d1.m_dag<d2.m_dag;
    return false;
}

void testaDatum(){
    //arEttTillatetDatum: giltiga
    assert(arEttTillatetDatum(datumFranAMD(2026, 11, 18)));
    assert(arEttTillatetDatum(datumFranAMD(2024, 2, 29)));  // skottår
    assert(arEttTillatetDatum(datumFranAMD(2000, 2, 29)));  // delbart med 400
    //arEttTillatetDatum: ogiltiga
    assert(!arEttTillatetDatum(datumFranAMD(2026, 2, 29))); // inte skottår
    assert(!arEttTillatetDatum(datumFranAMD(1900, 2, 29))); // delbart med 100, inte 400

    //nastaDagsDatum
    assert(arLikaDatum(nastaDagsDatum(datumFranAMD(2026, 11, 18)), datumFranAMD(2026, 11, 19)));
    assert(arLikaDatum(nastaDagsDatum(datumFranAMD(2026, 11, 30)), datumFranAMD(2026, 12, 1)));

    //foregaendeDagsDatum
    assert(arLikaDatum(foregaendeDagsDatum(datumFranAMD(2026, 11, 18)), datumFranAMD(2026, 11, 17)));
    assert(arLikaDatum(foregaendeDagsDatum(datumFranAMD(2026, 12, 1)), datumFranAMD(2026, 11, 30)));

    //datumEfterXDagar: positivt x
    assert(arLikaDatum(datumEfterXDagar(datumFranAMD(2026, 11, 18), 0), datumFranAMD(2026, 11, 18)));
    assert(arLikaDatum(datumEfterXDagar(datumFranAMD(2026, 11, 18), 1), datumFranAMD(2026, 11, 19)));
    //datumEfterXDagar: negativt x
    assert(arLikaDatum(datumEfterXDagar(datumFranAMD(2026, 11, 18), -1),  datumFranAMD(2026, 11, 17)));
    assert(arLikaDatum(datumEfterXDagar(datumFranAMD(2026, 11, 18), -18), datumFranAMD(2026, 10, 31)));

    //arLikaDatum
    assert(arLikaDatum(datumFranAMD(2026, 11, 18), datumFranAMD(2026, 11, 18)));
    //arMindreDatum
    assert(arMindreDatum(datumFranAMD(2025, 12, 31), datumFranAMD(2026, 1, 1)));
}

//15.4
struct Valuta{
    string m_namn;
    vector<int> m_valorer;
};

const Valuta SEK{"svenska kronor", {500,200,100,50,20,10,5,2,1}};

bool arGiltig(const Valuta& v){
    for (size_t i=1; i<v.m_valorer.size(); ++i){
        if (v.m_valorer[i-1] <= v.m_valorer[i])
            return false;
    }
    return true;
}

bool arLika(const Valuta& a, const Valuta& b){
    return a.m_namn == b.m_namn && a.m_valorer == b.m_valorer;
}

struct Vaxel4{
    Valuta m_valuta;
    vector<int> m_antal;
};

bool arLika(const Vaxel4& a, const Vaxel4& b){
    return a.m_antal == b.m_antal && arLika(a.m_valuta, b.m_valuta);
}

Vaxel4 vaxel4FranValutaAntal(const Valuta& valuta, const vector<int>& antalAvValor){
    assert(arGiltig(valuta));
    assert(valuta.m_valorer.size()== antalAvValor.size());

    Vaxel4 vaxeln{valuta, antalAvValor};
    return vaxeln;
}

Vaxel4 vaxel4FranValutaBelopp(const Valuta& valuta, int belopp){
    assert(arGiltig(valuta));

    int kvarAttBetala = belopp;
    vector<int> antal;

    for (size_t i=0; i<valuta.m_valorer.size(); ++i){
        int valor = valuta.m_valorer[i];
        int hurManga = kvarAttBetala/valor;
        antal.push_back(hurManga);
        kvarAttBetala %= valor;
    }

    return Vaxel4{valuta, antal};
}

int beloppFranVaxel(const Vaxel4& vaxel){
    int belopp = 0;
    for (size_t i=0; i<vaxel.m_valuta.m_valorer.size(); ++i){
        int valor = vaxel.m_valuta.m_valorer[i];
        belopp += valor * vaxel.m_antal[i];
    }
    return belopp;
}

void skrivUtVaxel(const Vaxel4& vaxel){
    for (size_t i=0; i<vaxel.m_antal.size(); ++i){
        int valor = vaxel.m_valuta.m_valorer[i];
        int antal = vaxel.m_antal[i];
        if (antal > 0)
            cout << antal << " st " << valor << endl;
    }
}

void automattestaVaxel4(){
    cout << "testar funktion" << endl;

    assert(arLika(vaxel4FranValutaBelopp(SEK, 947), vaxel4FranValutaAntal(SEK, {1,2,0,0,2,0,1,1,0})));
    Vaxel4 vaxel = vaxel4FranValutaBelopp(SEK, 836);
    assert(beloppFranVaxel(vaxel) == 836);

    cout << "testet funkar!" << endl;
}

void provaVaxel4(){
    Vaxel4 vaxel = vaxel4FranValutaBelopp(SEK, 947);
    skrivUtVaxel(vaxel);
}
