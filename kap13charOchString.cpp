#include <iostream>
#include <string>
#include <cassert>
#include <cctype>

using namespace std;

//13.1
void experimentMedChar(){
    cout << "experimentMedChar..." << endl;

    char ch1 = 'R';
    char ch2 = 82;
    int i1 = 'R';
    int i2 = 82;

    cout << ch1 << endl;
    cout << ch2 << endl;
    cout << i1 << endl;
    cout << i2 << endl;
}

//13.1.1
void skrivNagraAsciiTecken(){
    cout << "SkrivNagraAsciiTecken..." << endl;

    const char tabulator = 9;

    for (int asciital = 'a'-5; asciital <='z'+5; ++asciital){
        char tecken = asciital;
        cout << asciital << tabulator << tecken << endl;
    }
}

//13.2.1
void stringdemo1(){
    string str1 = "ABC";
    cout << str1 << " har storlek " << str1.size() << endl;
    cout << "str1[1] == " << str1[1] << endl;

    cout << endl;

    string str2 = "ÅÄÖ";
    cout << str2 << " har storlek " << str2.size() << endl;
    cout << "str2[1] == " << str2[1] << endl;
}

//13.2.11
string versalstrang(const string& str){
    string str1 = str;
    for (unsigned int i=0; i<str1.size(); ++i){
        str1[i] = toupper(str1[i]);
    }
    return str1;
}

void automattestaVersalstrang(){
    cout << "testar versalStrang" << endl;
    assert (versalstrang("abc ABC 123 .,- xyz") == "ABC ABC 123 .,- XYZ");

    cout << "test av versalStrang lyckades!" << endl;
}
