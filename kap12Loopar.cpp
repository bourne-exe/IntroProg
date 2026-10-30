#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

void kylskapMedWhileTrue(){
    while (true){
        cout << "tempteratur: ";
        int x;
        cin >> x;
        if (x<-273){
            break;
        }
        if (x<=2){
            cout << "För kallt!" << endl;
        }
        if (x>=8){
            cout << "För varmt!" << endl;
        }
        if (2<x && x<8){
            cout << "Lagom" << endl;
        }
    }
}

void kylskapMedWhileVillkor(){
    cout << "Kylskåp med while villkor" << endl;

    double temperatur = 0;
    while (temperatur>-273){
        cout << "temperatur: ";
        cin >> temperatur;

        if (temperatur>-273){
            if (temperatur<=2){
                cout << "För kallt!" << endl;
            }
            if (temperatur>=8){
                cout << "För varmt!" << endl;
            }
            if (2<temperatur && temperatur<8){
                cout << "Lagom" << endl;
            }
        }
    }
    cout << "lämnar kylskåpsloop" << endl;
}

int aritmetiskSummaFranAnalys(int n){
    return n*(n+1)/2;
}

int aritmetiskSummaFranLoop(int n){
    int summa = 0;
    for (int i = 1; i <= n; i++){
        summa = summa + i;
    }
    return summa;
}

void jamforSummaberakningar(int n){

    int resultat = aritmetiskSummaFranLoop(n);
    int diff = resultat - aritmetiskSummaFranAnalys(n);
    cout << "aritmetiskSummaFranLoop(" << n << ") = " << resultat << ", diff = " << diff << endl;

    assert (diff == 0);
}

void jamforFleraSummaberakningar(){
    cout << "jamfor flera summaberäkningar" << endl;

    for (int n=0; n<100 ; n += 20)
        jamforSummaberakningar(n);
}


unsigned int  PSEUDOSLUMPTAL = 42;

unsigned int ettSlumptal(){
    return rand();
    //PSEUDOSLUMPTAL = 1664525*PSEUDOSLUMPTAL + 1013904223;
    //return PSEUDOSLUMPTAL;
}

void genereraNagraSlumptal(){
    cout << "skriver 5 stora slumptal: " << endl;

    for (int i=0; i<5; ++i)
        cout << ettSlumptal() << " ";
    cout << endl;

    cout << "skriver 30 mindre slumptal: " << endl;

    for (int i=0; i<30; ++i)
        cout << ettSlumptal() % 6 << " ";
    cout << endl;
}

void undersokaSlumptalsgeneratorn(){
    cout << "undersokSlumptalsgeneratorn" << endl;

    unsigned long long int antalAnrop = 0;
    unsigned long long int foregaendeAntal = 0;

    int antal42or = 0;

    while (antal42or<4){
        unsigned int i = ettSlumptal();
        antalAnrop+=1;
        if (i==42){
            cout << "såg 42 efter " << antalAnrop << " anrop.";
            if (antal42or==0)
                cout << " (den första 42:an)" << endl;
            else cout << "  dvs. " << antalAnrop-foregaendeAntal << " steg efter föregående 42:a" << endl;

            foregaendeAntal = antalAnrop;
            antal42or += 1;
        }
    }
}

void provaMinaSlumptal(){
    cout << "provaMinaSlumptal" << endl;

    genereraNagraSlumptal();
    undersokaSlumptalsgeneratorn();
}

// 12.5.4
void froaSlumptalsgeneratorn(unsigned int fro){
    PSEUDOSLUMPTAL = fro;
}

unsigned int froatSlumptal(){
    froaSlumptalsgeneratorn(time(nullptr));
    return ettSlumptal();
}

void provaFroatSlumptal(){
    cout << "provaFroatSlumptal" << endl;
    cout << "skriver 5 fröade slumptal" << endl;

    for (int i=0;i<5;++i)
        cout << froatSlumptal() << " ";
    cout << endl;
}


//12.6
int nyttTal(int n){
    return rand() % n;
}

int anvandarensGissning(){
    int i;
    cin >> i;
    return i;
}

void utforSpelomgang(){
    cout << "Utför en spelomgång." << endl;
    const int n = 100;
    const int datornsTal = nyttTal(n);
    int antalUffordaGissningar = 0;
    cout << "Datorn tänker på ett tal mellan noll och " << n << ". Gissa vilket!" << endl;

    int i;
    while (i != datornsTal){
        cout << "din gissning; ";
        i = anvandarensGissning();
        antalUffordaGissningar++;
        if (i > datornsTal)
            cout << "för stort." << endl;
        if (i < datornsTal)
            cout << "för litet." << endl;
    }
    cout << "Vilken tur!" << endl;
    cout << "Du fick rätt på " << antalUffordaGissningar << ":e försöket!" << endl;
}


//12.7
double integralX2FranAnalys(double a, double b){
    return (b*b*b - a*a*a)/3;
}

double integralX2FranLoop(double a, double b){
    const double dx = 0.01;
    double area = 0;
    for (double x=a; x<(b-dx) ; x+=dx){
        area += x*x*dx;
        return area;
    }
}

void jamforIntegralberakningar(double a, double b){
    double resultatLoop = integralX2FranLoop(a,b);
    double resultatAnalys = integralX2FranAnalys(a,b);
    double diff = resultatLoop - resultatAnalys;
    cout << "integralX2FranLoop("<<a<<","<<b<<") = " << resultatLoop << ", diff = " << diff << endl;
}

void jamforFleraIntegralberakningar(){
    jamforIntegralberakningar(-1,1);
    jamforIntegralberakningar(0,1);
    jamforIntegralberakningar(1,2);
    jamforIntegralberakningar(2,10);
    cout << endl;
}


//12.8
double kvadratroten ( double x){
    double a = 1;
    for (int i=0; i<10; i++){
        double k = x/a;
        a = ((a+k)/2);
    }
    return a;
}
void jamforKvadratrotsberakningar ( double x){
    double resultat = kvadratroten (x);
    double diff = resultat - sqrt (x);
    cout << "kvadratroten (" << x << ") beräknad till " << resultat << " diff " << diff << endl;
}
void jamforFleraKvadratrotsberakningar(){
    jamforKvadratrotsberakningar (0.1) ;
    jamforKvadratrotsberakningar (2);
    jamforKvadratrotsberakningar (10);
    jamforKvadratrotsberakningar (100);
    jamforKvadratrotsberakningar (1234*1234);
    cout << endl;
}

//12.9


