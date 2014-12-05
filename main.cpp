#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

#include "matrix.h"

using namespace std;

// I've made the main and the library in separate files
// I realize this might not make sense for a lot of people
// so feel free to change it
int main() {
    
    Matrix m(2,2);
    
    cout << "empty 2x2" << endl;
    m.print(cout);
    Matrix n = m;
    cout << "copy of above" << endl;
    n.print(cout);
    
    cout << "empty 3x3" << endl;
    Matrix o(3,3);
    o.print(cout);
            
    cout << "o: 3x3 with each element = -row + col" << endl;
    for(int i=0; i<o.getRows(); i++)
        for(int j=0; j<o.getCols(); j++)
            o.setElement(i, j, -i+j);
    o.print(cout);
    
    cout << "p: 3x3, each element is ((row+1) + (col + 1)) / 10" << endl;
    Matrix p(3,3);
    for(int i=0; i<p.getRows(); i++)
        for(int j=0; j<p.getCols(); j++)
            p.setElement(i,j, (i+1)+(j+1)/10.0);
    p.print(cout);
    
    cout << "p + o" << endl;
    Matrix q(3,3);
    q = (p+o);  //Theres a super weird error in the addition function that's worth checking out
    q.print(cout);
    cout << "3o" << endl;
    q = o*3;
    q.print(cout);
    cout << "o - p" << endl;
    q = o-p;    //but somehow the nearly identical subraction function is fine
    q.print(cout);
    cout << "p*o" << endl;
    q = p*o;
    q.print(cout);
    
    cout << "p*o ^ T" << endl;
    q.transpose().print(cout);
    
    cout << "det(o)" << endl;
    cout << o.det() << endl;
    
}
