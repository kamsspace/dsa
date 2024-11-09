#include <iostream>
using namespace std;

class DiagonalMatrix {
private:
    int n;
    int *A;
public:
    DiagonalMatrix() {
        this->n = 2;
        A = new int[n];
    }
    DiagonalMatrix(int n) {
        this->n = n;
        A = new int[n];
    }

    void Set(int i, int j, int val);
    int Get(int i, int j);
    void Print();
    ~DiagonalMatrix();
};

void DiagonalMatrix::Print() {
    int i, j;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                cout << A[i] << " ";
            else
                cout << "0 ";
        }
    
        cout << endl;
    }
}

void DiagonalMatrix::Set(int i, int j, int val) {
    if (i == j)
        A[i] = val;
}

int DiagonalMatrix::Get(int i, int j) {
    if (i == j)
        return A[i];
    else
        return 0;
}

DiagonalMatrix::~DiagonalMatrix() { delete []A; }

//struct DiagonalMatrix {
//    int A[10];
//    int n;
//};

//void Set(DiagonalMatrix* m, int i, int j, int val) {
//    if (i == j)
//        m->A[i] = val;
//}
//
//int Get(DiagonalMatrix m, int i, int j) {
//    if (i == j)
//        return m.A[i];
//    else
//        return 0;
//}
//
//void Print(DiagonalMatrix m) {
//    int i, j;
//
//    for (i = 0; i < m.n; i++) {
//        for (j = 0; j < m.n; j++) {
//            if (i == j)
//                cout << m.A[i] << " ";
//            else
//                cout << "0 ";
//        }
//
//        cout << endl;
//    }
//}

int main()
{
    DiagonalMatrix matrix(4);

    matrix.Set(0, 0, 5);
    matrix.Set(1, 1, 5);
    matrix.Set(2, 2, 5);
    matrix.Set(3, 3, 5);

    matrix.Print();
    
}
