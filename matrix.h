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
    Matrix operator*(int);
    Matrix operator*(const Matrix&) const;
    Matrix &operator=(const Matrix&);
    Matrix cof();
    Matrix inv();
    Matrix transpose();
    bool diagonalizable();
    double getElement();
    int getRows();
    int getCols();
    int* eigVals();
    Matrix orthoDiagonalize();
    Matrix orthoNormalize();
    Matrix eigVector(int);
    Matrix eigVectors(); //set of vectors
    Matrix basisForNullSpace(); //set of vectors
    Matrix basisForSLESolutionSpace(Matrix); //set of vectors
    bool print(std::ostream&);
    ~Matrix();
private:
    int rows;
    int cols;
    double **elements;
    void copy(const Matrix&);
    void deleteAll();
};
#endif
