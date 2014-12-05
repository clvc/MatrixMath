#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

#include "matrix.h"

using namespace std;

int main() {
    
        Matrix m(2,2);
        m.print(cout);
        
        Matrix o(3,3);
        for(int i=0; i<o.getRows(); i++) {
            for(int j=0; j<o.getCols(); j++) {
                if(i<=j)
                   o.setElement(i, j, 1);
                else
                   o.setElement(i, j, 0);
            }
        }
        o.print(cout);
        o.cof().print(cout);
        
        Matrix p(3,3);
        for(int i=0; i<p.getRows(); i++){
            for(int j=0; j<p.getCols(); j++){
                if(i>=j)
                    p.setElement(i, j, 1);
                else
                    p.setElement(i, j, 0);
            }
        }
        p.print(cout);
        p.cof().print(cout);
        
        Matrix q(3,3);
        q = (p+o);  //Theres a super weird error in the addition function that's worth checking out
        q.print(cout);
        q = o*3;
        q.print(cout);
        q = o-p;    //but somehow the nearly identical subraction function is fine
        q.print(cout);
        q = p*o;
        q.print(cout);
        
        q.transpose().print(cout);
        
        cout << o.det() << endl;
        
        q = (p+o).cof();
        q.print(cout);
        q = (p*o).cof();
        q.print(cout);   

return 0;         
}
