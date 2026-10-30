#include <iostream>
#include <iomanip>

using namespace std;

// TODO

// 7.1
void undersokHeltalstyper(){
    cout << "One char takes " << 8*sizeof(char) << " byte" << endl;
    cout << "One short takes " << 8*sizeof(short) << " byte." << endl;
    cout << "One int takes " << 8*sizeof(int) << " byte" << endl;
    cout << "One long int takes " << 8*sizeof(long int) << " byte" << endl;
    cout << "One long long int takes " << 8*sizeof(long long int) << " byte" << endl;
}

// 7.2
void provaStorreAnStorst(){
    cout << "provaStorreAnStorst" << endl;

    int storstaHeltalet = INT_MAX;
    int annuStorre = storstaHeltalet + 1;
    cout <<  endl;
    cout << "StörstaHeltalet: " << storstaHeltalet << endl;
    cout << "Större än störst: " << annuStorre << endl;

}
void provaDivision(){
    cout << "provaDivision:" << endl;
    int two = 2;
    int five = 5;
    cout << five/two << endl;
    cout << two/five << endl;
    cout << two/five + two/five + two/five << endl;
}
void provaDivMedNoll(){
    cout << "provaDivMedNoll" << endl;
    int zero = 0;
    int two = 2;
    cout << two/zero << endl;
    cout << zero/zero << endl;
}
void provaHeltal(){
    cout << "provaHeltal:" << endl;
    provaStorreAnStorst();
    provaDivision();
    provaDivMedNoll();
}

// 7.3
void skrivUtVaxelV1(int antalKronor){
    int kronorKvarAttBetala = antalKronor;
    int antal500 = kronorKvarAttBetala/500;
    kronorKvarAttBetala -= antal500*500;
    int antal200 = kronorKvarAttBetala/200;
    kronorKvarAttBetala -= antal200*200;
    int antal100 =kronorKvarAttBetala/100;
    kronorKvarAttBetala -= antal100*100;
    int antal20 = kronorKvarAttBetala/20;
    kronorKvarAttBetala -= antal20*20;
    int antal10 = kronorKvarAttBetala/10;
    kronorKvarAttBetala -= antal10*10;
    int antal5 = kronorKvarAttBetala/5;
    kronorKvarAttBetala -= antal5*5;
    int antal2 = kronorKvarAttBetala/2;
    kronorKvarAttBetala -= antal2*2;
    int antal1 = kronorKvarAttBetala/1;
    kronorKvarAttBetala -= antal1*1;

    cout << antalKronor << " kronor är:" << endl;
    cout << antal500 << " x 500" << endl;
    cout << antal200 << " x 200" << endl;
    cout << antal100 << " x 100" << endl;
    cout << antal20 << " x 20" << endl;
    cout << antal10 << " x 10" << endl;
    cout << antal5 << " x 5" << endl;
    cout << antal2 << " x 2" << endl;
    cout << antal1 << " x 1" << endl;
}

// 7.4
void provaLitteraler(){
    cout << endl << "Testing calculations with literals" << endl;
    // Funkar inte
    cout << 7/10*500.0 << endl;
    // Funkar
    cout << 7/10.0*500 << endl;

    // Detta blir noll
    cout << 3/4 + 3/4 + 3/4 + 3/4 << endl;
    // 3.0/4 = 0
    cout << 3.0/4 + 3/4 << endl;
    // Funkar
    cout << -58/10 << endl;
}

// 7.5
void provaRest(){
    cout << "Testing rest-calculations" << endl;
    cout << 13 % 10 << endl;
    cout << 57 % 10 << endl;
    cout << 39 % 10 << endl;
    cout << -57 % 10 << endl;
    cout << endl;
}

// 7.7
void provaHexUtskrift(){
    cout << "Testing hex-output" << endl;
    int x = 256+10;

    cout << "1) " << x << endl;
    cout << "2) " << hex << x << endl; // "hex" gör "cout" sticky, alltså beräknar allting i basen 16
    cout << "3) " << x << endl;
    cout << "4) " << setw(8) << x << endl;
    cout << "5) " << setw(8) << setfill('0') << x << endl;
    cout << "6) " << setw(8) << x << ", x=" << endl << endl;
    cout << dec << setfill(' '); // Denna kod-rad gör så att "hex" inte blir sticky i "cout"
}

// 7.8
void provaHexLitteraler(){
    cout << "Testing Hex-literals" << endl;

    unsigned int x = 0xa7;
    cout << "x = " << x << endl;

    // Hur stor plats tar en int?
    int antal1Oktetter = sizeof(unsigned int);
    int antalHex = 2*antal1Oktetter;
    int antalBit = 8*antal1Oktetter;
    cout << "En (unsigned) int upptar" << antal1Oktetter
         << " Oktetter (dvs. " << antalHex << " hex-siffror, eller "
         << antalBit << " bit)" << endl;

    cout << "x = " << hex << setw(antalHex) << setfill('_') << x << endl << endl;
    cout << dec << setfill(' ');
}

// 7.9.1
void provaBitvisLogik(){
    cout << "Testing bitvis logik" << endl;

    unsigned int x = 0x123456;

    unsigned int mask = 0xF0;

    int antalSiffror = 2*sizeof(int);
    cout << hex << setfill('_');

    cout << "1) " << setw(antalSiffror) << x << endl;
    cout << "2) " << setw(antalSiffror) << mask << endl;
    cout << "2) " << setw(antalSiffror) << ~mask << endl;
    cout << "3) " << setw(antalSiffror) << (x | mask) << endl;
    cout << "4) " << setw(antalSiffror) << (x & ~mask) << endl;
    cout << "5) " << setw(antalSiffror) << (x ^ mask) << endl;

    cout << endl;
    cout << dec << setfill(' ');
}

// 7.9.3
unsigned int xMedEttstalldBit (unsigned int x, int bitnummer){
    unsigned int mask = (1 << bitnummer);
    return (x | mask);
}

unsigned int xMedNollstalldBit (unsigned int x, int bitnummer){
    unsigned int mask = (1 << bitnummer);
    return (x & ~mask);
}

void testaBitFunktionerna(){
    cout << "testar bitfunktionerna." << endl ;
    cout << "Bör bli 1: " << xMedEttstalldBit (0,0) << endl;
    cout << "Bör bli 2: " << xMedEttstalldBit (0,1) << endl;
    cout << "Bör bli 4: " << xMedEttstalldBit (0,2) << endl;
    cout << "Bör bli 1024: " << xMedEttstalldBit (0 , 10) << endl;
    cout << "Bör bli 1025: " << xMedEttstalldBit (1024 , 0) << endl;
    cout << "Bör bli 1025: " << xMedEttstalldBit (1025 , 0) << endl;
    cout << "Bör bli 1: " << xMedNollstalldBit (1025 , 10) << endl;
    cout << "Bör bli 1: " << xMedNollstalldBit (1 , 10) << endl;
    cout << endl;
}



// 7.9.4
unsigned int farginfoFranRGBO(unsigned int r, unsigned int g, unsigned int b, unsigned int opacity){
    unsigned int fargBit = (r << 8);
    fargBit = fargBit | g;
    fargBit = (fargBit << 8);
    fargBit = fargBit | b;
    fargBit = (fargBit << 8);
    fargBit = fargBit | opacity;
    return fargBit;
}

unsigned int blaFranFarginfo(unsigned int farginfo){
    unsigned int mask = 0x0000FF00;
    unsigned int bla = (farginfo & mask);
    return (bla >> 8);
}
unsigned int gronFranFarginfo(unsigned int farginfo){
    unsigned int mask = 0x00FF0000;
    unsigned int gron =(farginfo & mask);
    return (gron >> 16);
}
unsigned int rodFranFarginfo(unsigned int farginfo){
    unsigned int mask = 0xFF000000;
    unsigned int rod =(farginfo & mask);
    return (rod >> 24);
}
unsigned int opacityFranFarginfo(unsigned int farginfo){
    unsigned int mask = 0x000000FF;
    unsigned int opacity =(farginfo & mask);
    return opacity;
}

void testaFranFargFunktionerna(){
    cout << "Testing färgfunktionerna." << endl;
    unsigned int farg = farginfoFranRGBO(10,20,30,40);
    cout << rodFranFarginfo(farg) << endl;
    cout << gronFranFarginfo(farg) << endl;
    cout << blaFranFarginfo(farg) << endl;
    cout << opacityFranFarginfo(farg) << endl;
    cout << endl;
}

// gronFranFargInfo(farginfoFrabnRGBO(10,20,30,40));

void ingangTillHeltal(){
    cout << "ingangTillHeltal..." << endl;
}

