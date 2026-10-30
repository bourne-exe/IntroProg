#include <iostream>
#include <cmath>

using namespace std;

void ingangTillifSatser(){
    cout << "tillgangTillifSatser..." << endl;

}

// 5.1.3
void provaif(){
    cout << "Hej, idag ska vi kolla temperaturen nära dig!" << endl;
    cout << "Ange temperatur:" ;
    int temperature;
    cin >> temperature;
    cout << "Det ser ut att vara " << temperature << " grader varmt. " ;
    if (temperature > 25){
        cout << "Det är ganska varmt ute " << endl;
        cout << "Du bör dricka mycket vatten och looksmaxxa" << endl;
        if (temperature >= 40)
            cout << "Håll dig inomhus om du kan" << endl;
        else cout << "Perfekt väder för en utomhusaktivitet" << endl;
    }
    else
        cout << "Drick gärna något varmt" << endl;
    cout << "Ha en bra dag!" << endl;
}

// 5.2.3
bool t1(){ cout << "t1 = "; return true; }
bool t2(){ cout << "t2 = "; return true; }
bool f1(){ cout << "f1 = "; return false; }
bool f2(){ cout << "f2 = "; return false; }

void provaBoolUttryck(){
    cout << "Provar booliska uttryck." << endl;

    bool b1 = t1() && (t2() || f1());
    cout << "resultat " << b1 << endl;
    bool b2 = t1() || t2() || f1();
    cout << "resultat " << b2 << endl;
    bool b3 = f1() || (t2() && (f1() || f2()));
    cout << "resultat " << b3 << endl;
    cout << endl;
}

int dinalder(){
    cout << "Din ålder:";
    int alder;
    cin >> alder;
    if (alder < 20){
        return false;
    }
    else{
        return alder;
    }
}

bool harPass(){
    cout << "Har du pass? (ja/nej)?:";
    string svar;
    cin >> svar;
    if (svar == "ja"){
        return true;
    }
    else{
        return false;
    }
}

bool harKorkort(){
    cout << "Har du körkort (ja/nej)?:";
    string svar;
    cin >> svar;
    if (svar == "ja"){
        return true;
    }
    else{
        return false;
    }
}

bool forKopa01Version1(){
    return dinalder() && (harKorkort() || harPass());
}

void provaForKopa01Version1() {
    if (forKopa01Version1()){
        cout << "Du får köpa!" << endl;
    } else{
        cout << "Du får inte köpa." << endl;
    }
}

// 5.5.1
void skrivMedelvarde(const double summa, const int antalTermer){
    if (antalTermer==0)
        cout << "medelvärdet kan ej beräknas" << endl;
    else {
        double medelvarde = summa/antalTermer;
        cout << "medelvärdet är: " << medelvarde << endl;
    }
}

void provaSkrivMedelvarde(){
    skrivMedelvarde(3+5+4+3, 4);
    skrivMedelvarde(0, 0);
}