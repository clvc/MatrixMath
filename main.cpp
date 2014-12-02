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
    cout << "Hello world!" << endl;
    Matrix m(2,2);
    m.print(cout);
    Matrix n = m;
    n.print(cout);
    Matrix o(3,3);
    o.print(cout);
    // LIES
    o = m;
    o.print(cout);
}
