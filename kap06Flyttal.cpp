#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;
using namespace this_thread;

// 6.1
void proveUtskriftAvFlyttal(){
    cout << "provaUtskriftAvFlyttal" << endl;
    double tal = 7.77777777;
    cout << "Talet är: " << tal << endl;
    cout << "Med tre värdesiffror: " << setprecision(3) << tal << endl;
    cout << "Med tre decimaler: " << fixed << setprecision(3) << tal << endl;
    cout << "Talet är: " << tal << endl;
}
void ingangTillFlyttal(){
    cout << endl << "ingangTillFlyttal....." << endl;
}

// 6.2
void beraknaBokkostnad(){
    double BokPris;
    double antalSidor;
    double procentAttLasa;
    double minuterPerSida;

    cout << "Vilket pris har boken?: ";
    cin >> BokPris;
    cout << "Hur många sidor har boken?: ";
    cin >> antalSidor;
    cout << "Hur många procent av sidorna kommer du att läsa?: ";
    cin >> procentAttLasa;
    cout << "Hur många minuter tar det att läsa och förstå en sida?: ";
    cin >> minuterPerSida;
    cout << "Tystnad, beräkning pågår..." << endl;
    sleep_for(milliseconds(3000));

    double sidorAttLasa =
        antalSidor * (procentAttLasa / 100);
    double totaltAntalTimmar =
        (sidorAttLasa*minuterPerSida) / 60;
    double kostnadPerTimme = BokPris / totaltAntalTimmar;

    cout << "Du beräknas ägna boken ca " << fixed << setprecision(1) << totaltAntalTimmar << " timmar." << endl;
    cout << "Boken beräknas därför kosta dig " << fixed << setprecision(2) << kostnadPerTimme << " kr/timme." << endl;
}

// 6.4
void provaInfinity(){
    double zero = 0;
    double two = 2;
    cout << endl;
    cout << "Division with zero:" << endl;
    cout << zero/zero << endl;
    cout << two/zero << endl;
    cout << -two/zero << endl;
    cout << endl;
    cout << "A little game with infinity:" <<endl;
    double oo = two/zero;
    cout << two + oo << endl;
    cout << oo + oo << endl;
    cout << oo - oo << endl;
    cout << -oo - oo << endl;

    cout << endl;
    cout << "Division with infinity:" << endl;
    cout << two/oo << endl;
    cout << -two/oo << endl;
    cout << oo/oo << endl;
    cout << -oo/oo << endl;
    cout << endl;
}

void provaFlytttal(){
    cout << endl << "provaFLyttal" << endl;
    provaInfinity();
}

// 6.5
void provaAttJamforaFlyttal(){
    cout << "Trying to compare floating point" << endl;
    double tal1 = 0.3;
    double tal2 = 0.1+0.1+0.1;

    if (tal1==tal2){
        cout << tal1 << " och " << tal2 << " är lika." << endl;
    }
    else cout << tal1 << " och " << tal2 << " är OLIKA!" << endl;

    cout << setprecision(20) << tal1 << " och " << tal2 << endl;
    cout << endl;
}

// 6.5.1

int a(){
    cout << "Write a value on a: ";
    int a;
    cin >> a;
    return a;
}

int b(){
    cout << "Write a value on b: ";
    int b;
    cin >> b;
    return b;
}

bool ungefarLika(double a, double b){
    if (a>=b){
        return ((a-b) <= 0.001);
    }
    return ((b-a <= 0.001));
}
void testaUngefarLika(){
    cout << "Testing ungefarLika" << endl;
    const double epsilon = 0.0005;
    const double delta = 0.002;
    const double x = 123.5;
    bool ok1 = ungefarLika(x, x + epsilon);
    bool ok2 = ungefarLika(x, x - epsilon);
    bool ok3 = !ungefarLika(x, x + delta);
    bool ok4 = !ungefarLika(x, x - delta);

    if (ok1 && ok2 && ok3 && ok4){
        cout << "ungefarLika passed the test!" << endl;
    }
    else cout << "ungefarLika has at least one bug!" << endl;
    cout << endl;
}