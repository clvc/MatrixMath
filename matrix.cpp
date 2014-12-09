#include "matrix.h"

using namespace std;

Matrix::Matrix() {
    rows = 0;
    cols = 0;
    elements = NULL;
    cerr << "DEFAULT CONSTRUCTOR" << endl;
}

Matrix::Matrix(int r, int c) {
    rows = r;
    cols = c;
    elements = new double*[rows]; 
    for (int i = 0; i < rows; i++) {
        elements[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            elements[i][j] = 0;
        }
    }
    cerr << "TWO INTS CONSTRUCTOR" << endl;
}

Matrix::Matrix(const Matrix& matrix) {
    elements = NULL;
    copy(matrix);
    cerr << "COPY CONSTRUCTOR" << endl;
}

Matrix::~Matrix() {
    deleteAll();
    cerr << "BOOM" << endl;
}

void Matrix::deleteAll() {
    for (int i = 0; i < rows; i++) {
        delete[] elements[i];
    }
    delete[] elements;
    elements = NULL;
    cerr << "DELETEALL" << endl;
}

Matrix &Matrix::operator=(const Matrix &that) {
    if (this != &that) {
        copy(that);
    }
    cerr << "ASSIGNMENT OPERATOR" << endl;
    return *this;
}

void Matrix::copy(const Matrix &that) {
    if (elements) deleteAll();
    rows = that.rows;
    cols = that.cols;
    elements = new double*[rows];
    for (int r = 0; r < rows; r++) {
        elements[r] = new double[cols];
        for (int c = 0; c < cols; c++) {
            elements[r][c] = that.elements[r][c];
        }
    }
    cerr << "COPY" << endl;
}

bool Matrix::print(ostream &out) {
    bool success = true;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            success = success && (out << elements[r][c] << " ");
        }
        out << endl;
    }
    return success;
}


void Matrix::setElement(int row, int col, double element) {
    elements[row][col] = element;
    cerr << "SET ELEMENT" << endl;
}

int Matrix::getRows() const{
    return rows;
}

int Matrix::getCols() const{
    return cols;
}

Matrix Matrix::operator+(const Matrix& that) const{
    
    if((*this).rows==that.rows&&(*this).cols==that.cols) {
        Matrix m(that.rows,that.cols);
        for(int i=0; i<that.rows; i++)
            for(int j=0; j<that.cols; j++)
                m.elements[i][j] = (*this).elements[i][j] + that.elements[i][j];
        cerr << "ADDITION" << endl;
        return m;
    }
    else {
        cerr << "ADDITION ERROR" << endl;
        return Matrix(0,0);
    }
    
}

Matrix Matrix::operator-(const Matrix& that) const{
    
    if((*this).rows==that.rows&&(*this).cols==that.cols) {
        Matrix m(that.rows,that.cols);
        for(int i=0; i<that.rows; i++)
            for(int j=0; j<that.cols; j++)
                m.elements[i][j] = (*this).elements[i][j] - that.elements[i][j];
        cerr << "SUBTRACTION" << endl;
        return m;
    }
    else {
        cerr << "SUBTRACTION ERROR" << endl;
        return Matrix(0,0);
    }
    
}

Matrix Matrix::operator*(const Matrix& that) const{
    
    if((*this).cols==that.rows) {
        Matrix m((*this).rows,that.cols);
        for(int i=0; i<(*this).rows; i++)
            for(int j=0; j<that.cols; j++)
                for(int k=0; k<(*this).cols; k++)
                    m.elements[i][j] += (*this).elements[i][k] * that.elements[k][j];
        cerr << "MULTIPLICATION" << endl;
        return m;
    }
    else {
        cerr << "MULTIPLICATION ERROR" << endl;
        return Matrix(0,0);
    }
    
}

Matrix Matrix::operator*(int a) {
    
    Matrix m = *this;
    for(int i=0; i<m.rows; i++)
        for(int j=0; j<m.cols; j++)
            m.elements[i][j] *= a;
    cerr << "SCALAR MULTIPLICATION" << endl;
    return m;
    
}

Matrix Matrix::transpose() {
    Matrix m(cols, rows);
    for(int i=0; i<m.rows; i++)
        for(int j=0; j<m.cols; j++)
            m.elements[i][j] = elements[j][i];
    return m;
    
}

double Matrix::det() {    //MOST DISGUSTING THING EVER
    if(rows!=cols)
        cerr << "DETERMINANT ERROR" << endl;
    else if(rows==1)
        return elements[0][0];
    else if(rows==2)
        return  elements[0][1]*elements[1][0] - elements[0][0]*elements[1][1];
    else{
        
        double sum = 0;
        
        for(int a=0; a<(*this).rows; a++){
            Matrix m(rows-1,rows-1);
            int counter = 0;
            for(int i=0; i<m.rows; i++){
                for(int j=0; j<m.cols; j++){
                    if(j==a)
                        counter = 1;
                    m.elements[i][j] = (*this).elements[i+1][j+counter];
                }
            }
            if(a%2==0)
                sum += (*this).elements[0][a]*m.det();
            else
                sum -= (*this).elements[0][a]*m.det();
        }
        return sum;
    }
}

double Matrix::getElement(int r, int c){
    return elements[r][c];
}

Matrix Matrix::cof() {
    
    if(rows==cols){
        Matrix m(rows,cols);
        Matrix deter(rows-1,cols-1);
    
        for (int i=0; i < m.rows; i = i+1) {
            for (int j=0; j < m.cols; j = j+1) {
                
                int inc_x = 0, inc_y = 0;
                bool check_x = false, check_y = false;
                for (int x=0; x<rows-1; x++) {
                    for (int y=0; y<cols-1; y++) {
                        if (!check_x && x>=i) {
                            inc_x = 1;
                            check_x = true;
                        }
                        if (!check_y && y>=j) {
                            inc_y = 1;
                            check_y = true;
                        }
                        deter.elements[x][y] = elements[x+inc_x][y+inc_y];
                    }
                }
    
                if((i+j)%2==0)
                    m.elements[i][j] = deter.det();
                else
                    m.elements[i][j] = 0-deter.det();
            }
        }
        cerr << "COFACTOR" << endl;
        return m;
    }
    else {
        cerr << "COFACTOR ERROR" << endl;
        return Matrix(0,0);
    }
}

Matrix Matrix::rref(){
    Matrix m = (*this);
    int pivotCol = 0;
    int pivotRow = 0;
    
    while (pivotCol <= cols){
        m.pivot(pivotRow,pivotCol);
        pivotCol++;
    }
    
    return m;
}

void Matrix::pivot(int &pivotRow, int pivotCol) {
    int firstNonZero = -1;
    for (int i=pivotRow; i<rows; i++) {
        if (elements[i][pivotCol] != 0)
            firstNonZero = i;
    }
    if (firstNonZero == -1)
        return;
    else {
        if (firstNonZero != pivotRow) {
            for (int j=pivotCol; j<cols; j++) {
                double temp = elements[firstNonZero][j];
                elements[firstNonZero][j] = elements[pivotRow][j];
                elements[pivotRow][j] = temp;
            }
        }
        for (int j = cols-1; j>=pivotCol; j--) {
            elements[pivotRow][j] /= elements[pivotRow][pivotCol];
        }
        if (pivotRow<rows-1) {
            for (int k = pivotRow+1; ; k<rows; k++) {
                for (int j = cols-1; j>=pivotCol; j--) {
                    elements[k][j] = elements[k][j] - elements[k][pivotCol]*elements[pivotRow][j];
                }
            }
        }
        pivotRow++;
        return;
    }
}


// continue on
