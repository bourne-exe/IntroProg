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

//14.3

//Returnerar minsta värdet i vektorn
int minst(const vector<int>& vek){
    int minsta = vek[0];
    for (size_t i=1; i<vek.size(); ++i){
        if (vek[i] < minsta)
            minsta = vek[i];
    }
    return minsta;
}

//Returnerar största värdet i vektorn
int storst(const vector<int>& vek){
    int storsta = vek[0];
    for (size_t i=1; i<vek.size(); ++i){
        if (vek[i] > storsta)
            storsta = vek[i];
    }
    return storsta;
}

//Returnerar indexpositionen till det minsta värdet i vektorn
int indexTillMinsta(const vector<int>& vek){
    int minsta = vek[0];
    int indexMin = 0;
    for (size_t i=1; i<vek.size(); ++i){
        if (vek[i] < minsta){
            minsta = vek[i];
            indexMin = i;
        }
    }
    return indexMin;
}

//Returnerar indexpositionen till det största värdet i vektorn
int indexTillStorsta(const vector<int>& vek){
    int storsta = vek[0];
    int indexStorst = 0;
    for (size_t i=1; i<vek.size(); ++i){
        if (vek[i] > storsta){
            storsta = vek[i];
            indexStorst = i;
        }
    }
    return indexStorst;
}

//Returnerar true om om vektorn är sorterad, dvs. om v[i] <=v[v+1]
bool arSorterad(const vector<int>& vek){
    for (size_t i=0; i+1<vek.size(); ++i){
        if (vek[i] > vek[i+1])
            return false;
    }
    return true;
}

//Testfunktioner (skall krasha om det finns en bug)

void testaMinst(){
    cout << "testar funktionen" << endl;
    const int size = 100;
    vector<int> vek(size,42);
    vek[0] = 40;
    assert(minst(vek) == 40);
    vek[size-1] = 30;
    assert(minst(vek) == 30);
    vek[size/2] =-10;
    assert(minst (vek) == -10);
    cout << "testet lyckades!" << endl;
}

void testaStorst(){
    cout << "testa störst" << endl;
    const int size = 100;
    vector<int> vek(size,-42);
    vek[0]=-10;
    assert(storst(vek) == -10);
    vek[size-1] =-5;
    assert(storst(vek) == -5);
    vek[size/2] = -1;
    assert(storst(vek) == -1);
    cout << "testet lyckades!" << endl;
}

void testaIndexTillMinsta (){
    cout << "... testaIndexTillMinsta " << endl;
    const int size = 100;
    vector<int> vek (size,42);
    vek[0] = 40;
    assert(indexTillMinsta(vek) == 0);
    vek[size-1] = 30;
    assert(indexTillMinsta(vek) == size-1);
    vek[size/2] = -10;
    assert(indexTillMinsta(vek) == size/2);
    cout << "testet lyckades!" << endl;
}

void testaIndexTillStorsta(){
    cout << "testaIndexTillStorsta" << endl;
    const int size = 100;
    vector<int>vek(size,-42);
    vek[0] = -10;
    assert(indexTillStorsta(vek) == 0);
    vek [size -1] = -5;
    assert(indexTillStorsta(vek) == size-1);
    vek[size/2] = 1;
    assert(indexTillStorsta(vek) == size/2);
    cout << "testet lyckades " << endl;
}

void testaArSorterad(){
    cout << "testaArSorterad " << endl;
    const int size = 100;
    //skapa en vektor vek där varje tal förekommer flera gånger
    vector<int> vek(size ,0);
    for(size_t i=0; i<size; ++i)
    vek[i] = -10 + i /3;
    assert(arSorterad(vek));
    //skapa tre vektorer som inte är riktigt sorterade
    vector<int> v1=vek;
    vector<int> v2=vek;
    vector<int> v3=vek;
    v1[0] = v1[1]+1;
    v2[size/2] = v2[size/2+1]+1;
    v3[size-1] = v2[size-2]-1;
    assert(!arSorterad(v1));
    assert(!arSorterad(v2));
    assert(!arSorterad(v3));
    vector<int> tom;
    assert(arSorterad(tom));
    cout << "testet lyckades" << endl ;
}

void testaFlerVektorfunktioner(){
    cout << " testaFlerVektorfunktioner ..." << endl;
    cout << "(om programmet kraschar har du en bug)" << endl;
    testaMinst();
    testaStorst();
    testaIndexTillMinsta();
    testaIndexTillStorsta();
    testaArSorterad();
    cout << "testet lyckades!" << endl;
}