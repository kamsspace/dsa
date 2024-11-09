#include <iostream>
using namespace std;

class LowerTriangle {
private:
    int n;
    int* A;
public:
    LowerTriangle() {
        n = 2;
        A = new int[n*(n+1)/2];
    }
    LowerTriangle(int n) {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }

    void Set(int i, int j, int val);
    int Get(int i, int j);
    void Print();
    int GetDimensions() { return n; }
    ~LowerTriangle();
};

void LowerTriangle::Print() {
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i >= j)
                cout << A[i * (i - 1) / 2 + j - 1] << " ";
            else
                cout << "0 ";
        }

        cout << endl;
    }
}

void LowerTriangle::Set(int i, int j, int val) {
    if (i >= j)
        A[i * (i-1)/2 + j - 1] = val;
}

int LowerTriangle::Get(int i, int j) {
    if (i >= j)
        return A[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}

LowerTriangle::~LowerTriangle() { delete[]A; }

int main()
{
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;
    LowerTriangle lowTriMatrix(d);

    int x;
    cout << "Enter all elements: ";
    
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= d; j++) {
            cin >> x;
            lowTriMatrix.Set(i, j, x);
        }
    }

    lowTriMatrix.Print();
}
