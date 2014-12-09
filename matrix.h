// from Facebook (unmodified)
#ifndef MATRIX_H
#define MATRIX_H

#include <cstdlib>
#include <fstream>
#include <iostream>
class Matrix{
public:
    Matrix();
    Matrix(int,int);
    Matrix(const Matrix&);
    double det();
    Matrix operator+(const Matrix&) const;
    Matrix operator-(const Matrix&) const;
    Matrix operator*(double);
    Matrix operator*(const Matrix&) const;
    Matrix &operator=(const Matrix&);
    Matrix transpose();
    double getElement(int, int);
    void setElement(int, int, double);
    int getRows() const;
    int getCols() const;
    bool print(std::ostream&);
    Matrix cof();
    void pivot(int&,int);
    Matrix rref();
    //To do:
    int* eigVals();
    Matrix inv();
    bool diagonalizable();
    Matrix orthoDiagonalize();
    Matrix orthoNormalize();
    Matrix eigVector(int);
    Matrix eigVectors(); //set of vectors
    Matrix basisForNullSpace(); //set of vectors
    Matrix basisForSLESolutionSpace(Matrix); //set of vectors
    ~Matrix();
private:
    int rows;
    int cols;
    double **elements;
    void copy(const Matrix&);
    void deleteAll();
};

Matrix inv(Matrix);
Matrix rref(Matrix);
Matrix cof(Matrix);

#endif
