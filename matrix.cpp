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

// continue on
