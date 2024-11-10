#include <iostream>
using namespace std;

class Element {
public:
    int i;
    int j;
    int val;
};

class Sparse {
private:
    int i;
    int j;
    int n;
    Element *e;
public:
    Sparse(int i, int j, int n) {
        this->i = i;
        this->j = j;
        this->n = n;
        e = new Element[this->n];
    }

    ~Sparse() {
        delete[] e;
    }

    Sparse operator+(Sparse &s);
    friend istream &operator>>(istream &is, Sparse &s);
    friend ostream &operator<<(ostream &os, Sparse &s);
};

// Corrected operator+ for adding two sparse matrices
Sparse Sparse::operator+(Sparse &s) {
    if (i != s.i || j != s.j) {
        cout << "Matrices have different dimensions!" << endl;
        return Sparse(0, 0, 0); // Return an empty matrix as an error indicator
    }

    Sparse *sum = new Sparse(i, j, n + s.n);
    int k = 0, l = 0, m = 0;

    while (k < n && l < s.n) {
        if (e[k].i < s.e[l].i || (e[k].i == s.e[l].i && e[k].j < s.e[l].j)) {
            sum->e[m++] = e[k++];
        } else if (e[k].i > s.e[l].i || (e[k].i == s.e[l].i && e[k].j > s.e[l].j)) {
            sum->e[m++] = s.e[l++];
        } else {
            sum->e[m] = e[k];
            sum->e[m++].val = e[k++].val + s.e[l++].val;
        }
    }

    // Append remaining elements
    while (k < n) sum->e[m++] = e[k++];
    while (l < s.n) sum->e[m++] = s.e[l++];
    sum->n = m;

    return *sum;
}

// Corrected operator>> for reading sparse matrix elements
istream &operator>>(istream &is, Sparse &s) {
    cout << "Enter non-zero elements (i, j, value): " << endl;
    for (int r = 0; r < s.n; r++) {
        is >> s.e[r].i >> s.e[r].j >> s.e[r].val;
    }
    return is;
}


ostream &operator<<(ostream &os, Sparse &s) {
    int k = 0;
    for (int r = 0; r < s.i; r++) {
        for (int c = 0; c < s.j; c++) {
            if (k < s.n && s.e[k].i == r && s.e[k].j == c) {
                os << s.e[k++].val << " ";
            } else {
                os << "0 ";
            }
        }
        os << endl;
    }
    return os;
}

int main() {
    Sparse sp1(5, 5, 5);
    Sparse sp2(5, 5, 5);

    cin >> sp1;
    cin >> sp2;

    Sparse sum = sp1 + sp2;
    cout << "First matrix: " << endl << sp1;
    cout << "Second matrix: " << endl << sp2;
    cout << "Sum matrix: " << endl << sum;

    return 0;
}
