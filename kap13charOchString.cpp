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

//13.2.12
string rubrikstrang(const string& str){
    string str1 = str;
    for (size_t i=0; i<str1.size(); ++i){
        if (i==0){
            str1[i] = toupper(str1[i]);
        } else if (str1[i-1] == ' '){
            str1[i] = toupper(str1[i]);
        } else str1[i] = tolower(str1[i]);
    }
    return str1;
}

void automattestaRubrikstrang(){
    cout << "testar rubrikstrang" << endl;

    assert (rubrikstrang("ha en BRA DAG !") == "Ha En Bra Dag !");
    assert (rubrikstrang("HA EN BRA DAG !") == "Ha En Bra Dag !");
    assert (rubrikstrang("") == "");
    cout << "test av rubrikstrang lyckades!" << endl;
}

//13.2.14
string reducerad(const string& str){
    string resultat = "";
    int forstaBokstav = 0;
    bool foregoendeTeckenVarMellanslag = false;

    for (size_t i=0; i<str.size(); ++i){
        const char tecken = str[i];
        if (tecken == ' '){
            if (foregoendeTeckenVarMellanslag)
                continue;
            resultat += ' ';
            foregoendeTeckenVarMellanslag = true;
        }
        else{
            resultat += tecken;
            foregoendeTeckenVarMellanslag = false;
        }
    }
    return resultat;
}

void automattestaReducerad(){
    cout << "testar reducerad" << endl;

    assert(reducerad("  Ha en bra dag!   ") == " Ha en bra dag! ");
    assert(reducerad(" A   B  C") == " A B C");
    assert(reducerad("ABC") == "ABC");

    cout << "testen av reducared lyckades!" << endl;
}

//13.2.15
string trimmad(const string& str) {
    string resultat = "";
    size_t antalMellanslag = 0;

    for (size_t i=0; i<str.size(); ++i) {
        const char tecken = str[i];
        if (tecken == ' ') {
            ++antalMellanslag;
        }
        else{
            if (resultat != "")
                resultat += string(antalMellanslag, ' ');
            resultat += tecken;
            antalMellanslag = 0;
        }
    }
    return resultat;
}


void automattestaTrimmad(){
    cout << "testar trimmad" << endl;
    assert(trimmad("   Ha en bra dag!  ") == "Ha en bra dag!");
    assert(trimmad(" A   B C ") == "A   B C");
    assert(trimmad("     ") == "");
    assert(trimmad("") == "");
    assert(trimmad("abc") == "abc");
    cout << "testen lyckades!" << endl;
}

//13.2.16
bool arVokal(char ch){
    string vokaler = "aeiouyAEIOUY";

    for (size_t i=0; i<vokaler.size(); ++i){
        if (vokaler[i] == ch)
            return true;
    }
    return false;
}
bool arKonsonant(char ch){
    string konsonanter = "bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";

    for (size_t i=0; i<konsonanter.size(); ++i){
        if (konsonanter[i] == ch)
            return true;
    }
    return false;
}
void automattestaArVokalOchArKonsonant(){
    cout << "automattestar arVokal och arKonsonant" << endl;

    string vokaler = "aeiouyAEIOUY";
    string konsonanter = "bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
    string andraTecken = ". ,?!; ";

    for (size_t i=0; i<vokaler.size(); ++i){
        assert(arVokal(vokaler[i]));
    }
    for (size_t i=0; i<konsonanter.size(); ++i){
        assert(arKonsonant(konsonanter[i]));
    }
    for (size_t i=0; i<andraTecken.size(); ++i){
        assert(!arVokal(andraTecken[i]) && !arKonsonant(andraTecken[i]));
    }
    cout << "testerna av arVokal/ArKonsonant lyckades!" << endl;
}
