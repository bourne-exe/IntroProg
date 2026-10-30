#include <iostream>
#include <cassert>

using namespace std;

void testingMyKnowledge(){
    cout << "Testing my knowledge" << endl;

    assert(2.5 + 3 == 5.5);
    assert(5/2==2);
    assert(1.0/2*10==5.0);
    assert((3 | 16)==19);
    assert((3 | 15)==15);
    assert((3 & 16)==0);
    assert((3 & 15)==3);
    assert(3 << 2 == 12);

    cout << "<< Testing code <<" << endl;
}

bool ungefarLika(double, double);

void automattestaUngefarLika(){
    cout << ">> automattestaUngefarLika >>" << endl;

    assert(ungefarLika(2,2.000005));
    assert(ungefarLika(2.00005,2));
    assert(!ungefarLika(2,3));
    assert(!ungefarLika(3,2));

    cout << "<< automattestaUngefarLika <<" << endl;
}



void ingangTillTestaKod(){
    cout << endl << "ingangTillTeskaKod..." << endl;
}
