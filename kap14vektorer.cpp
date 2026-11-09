# include <iostream>
# include <cstdlib>
# include <cmath>
# include <vector>
# include <cassert>

using namespace std;

//14.2

// Skriver ut vektorn på formatet: (a,b,c)
void skrivUtVek(const vector<int>& vek){
    double sum(0);
    for (size_t i=0; i<vek.size(); ++i){
        sum = vek[i];
        cout << sum << " ";
    }
    cout << endl;
}

//Fyller hela vektorn med angivet värde.
void fyllMedVarde(vector<int>& vek, int varde){
    for (size_t i=0; i<vek.size(); ++i){
        vek[i] = varde;
    }
}

//Fyller hela vektorn med slumptal inom angivet intervall
void fyllMedSlumptal(vector<int>& vek, int minsta, int storsta){
    for (size_t i=0; i<vek.size(); ++i){
        vek[i] = minsta + rand() % (storsta - minsta + 1);
    }
}

//Returnerar true om vek innehåller x
bool innehaller(const vector<int>& vek, int x){
    int resultat=0;
    for (size_t i=0; i<vek.size(); ++i){
        if (vek[i] == x)
            return true;
    }
    return false;
}

//Provkör skrivUtVek som måste testas genom att manuellt verifiera utskriften blir korrekt
void provaSkrivUtVek(){
    cout << "provaSkrivUtVek" << endl;
    cout << "Verifiera manuellt att utskriften blir (7, 8, 9, 10)" << endl;
    vector<int> vek{7,8,9,10};
    skrivUtVek(vek);
    cout << "provaSkrivUtVek lyckades??" << endl;
}

//Testfunktion
void testaFyllMedVarde(){
    cout << "testaFyllMedVarde" << endl;
    const int size = 100;
    vector<int> vek(size, 0);
    fyllMedVarde(vek, 42);

    for (size_t i=0; i<size; ++i){
        assert(vek[i]==42);
    }
    cout << "testet lyckades" << endl;
}

//Testfunktion
void testaFyllMedSlumptal(){
    cout << "test med slumptal" << endl;
    const int size = 10000;
    int minsta = -8;
    int storsta = 5;

    vector<int> vek(size, 0);

    fyllMedSlumptal(vek, minsta, storsta);
    bool observeraMinsta = false;
    bool observeraStorsta = false;
    bool observeraMellan = false;
    bool observeraUtanfor = false;

    for (size_t i=0; i<size; i++){
        const int x = vek[i];
        if (x==minsta) observeraMinsta = true;
        if (x==storsta) observeraStorsta = true;
        if (minsta < x && x < storsta) observeraMellan = true;
        if (x< minsta || storsta<x) observeraUtanfor = true;
    }
    assert(observeraMinsta && observeraStorsta && observeraMellan && !observeraUtanfor);

    cout << "testet lyckades" << endl;
}

//Testfunktion
void testaInnehaller(){
    cout << "testar funktionen" << endl;
    const int size = 100;
    vector<int> vek(size, 42);

    vek[0]=44;
    vek[size/2]=45;
    vek[size-1]=46;

    assert(!innehaller(vek, 43));
    assert(innehaller(vek,44));
    assert(innehaller(vek,45));
    assert(innehaller(vek,46));
    vector<int> tom;
    assert(!innehaller(tom,0));

    cout << "testet lyckades!" << endl;
}

void testaVektorfunktioner(){
    cout << "testar funktionen" << endl;
    cout << "(om programmet krashar har du en bug)" << endl;

    provaSkrivUtVek();

    testaFyllMedVarde();
    testaFyllMedSlumptal();
    testaInnehaller();

    cout << "testen lyckades!" << endl;
}