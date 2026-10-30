#include <iostream>
#include <cassert>

using namespace std;


// 10.1.1
void BytVarden(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void testaBytVarden(){
    int a{42};
    int b{108};
    BytVarden(a,b);
    cout << a << " är nu " << a << endl;
    cout << b << " är nu " << b << endl;
    assert(a==108 && b==42);
}

// 10.3.1
void skrivResultat ( int x){
    cout << " resultatet blev " << x << endl ;
}
int sju (){
    cout << " returnerar 7 ";
    return 7;
}
int tva (){
    cout << " returnerar 2 ";
    return 2;
}
int summan ( int x, int y){
    int summa = x + y;
    cout << " returnerar summan " << summa ;
    return summa ;
}
void provaNastlatAnrop(){
    skrivResultat ( summan ( tva () , sju () ) );
}

// 10.4
double storst (double a, double b){
    if (a>b){
        return a;
    }
    else return b;
}
double storst (double a, double b, double c){
    return storst(storst(a,b), c);
}
double storst ( double a, double b, double c, double d){
    return storst(storst(a,b,c), d);
}
double storst ( double a, double b, double c, double d, double e){
    return storst(storst(a,b,c,d), e);
}
void provaAllaStorst(){
    cout << storst ( 3 ,7 ) << endl ; // 7
    cout << storst ( 3, 8, 7, 5 ) << endl ; // 8
    cout << storst (1 , 3, 2, 9, 8) << endl ; // 9
    cout << storst (5.2 , 4.3 , 10.5 , 10.4) << endl ; // 10.5
    assert ( storst (2.0 , 2.5 , 1.0) > 2.4 );
    assert ( storst (2 , 3, 1, 8 ,3) == 8 );
}