#include "matrix.h"
#include <cstdlib>

Matrix::Matrix() {
    // should we do stuff? nahhhhh
}

Matrix::Matrix(int r, int c) {
    rows = r;
    cols = c;
    elements = (double **) malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        elements[i] = (double *) malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            elements[i][j] = 0;
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        free(elements[i]);
    }
    free(elements);
    // do stuff!
}

// continue on
