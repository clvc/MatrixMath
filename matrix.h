// from Facebook (unmodified)
class Matrix{
public:
    Matrix();
    Matrix(int,int);
    double det();
    Matrix operator+(Matrix);
    Matrix operator-(Matrix);
    Matrix operator*(int);
    Matrix operator*(Matrix);
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
    void print();
    ~Matrix();
private:
    int rows;
    int cols;
    double **elements;
};
