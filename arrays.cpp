#include <iostream>
using namespace std;

struct Array {
    int *A;
    int length;
    int size;
};

void add(Array *a, int value) {
    int i;

    if (a->length < a->size)
        a->A[a->length++] = value;
}

void insert(Array* a, int pos, int value) {
    int i;

    if (pos >= 0 && pos <= a->length) {
        for (i = a->length; i > pos; i--)
            a->A[i] = a->A[i - 1];
        a->A[pos] = value;
        a->length++;
    }
}

int Delete(Array* a, int pos) {
    int deletedItem = 0, i;

    if (pos >= 0 && pos < a->length) {
        deletedItem = a -> A[pos];

        for (i = pos; i < a->length - 1; i++)
            a->A[i] = a->A[i + 1];
        a->length--;
        return deletedItem;
    }

    return 0;
}

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int LinearSearch(Array* a, int value) {
    int i;
    
    for (i = 0; i < a->length; i++) {
        if (value == a->A[i]) {
            swap(&a->A[i], &a->A[0]);
            return i;
        }
    }

    return -1;
}

int BinarySearch(Array a, int value) {
    int left, mid, right;
    left = 0;
    right = a.length - 1;

    while (left <= right) {
        mid = (left + right) / 2;

        if (value == a.A[mid])
            return mid;
        else if (value < a.A[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}

int RecBinarySearch(Array a, int value, int left, int right) {
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (value == a.A[mid])
            return mid;
        else if (value < a.A[mid])
            return RecBinarySearch(a, value, left, mid - 1);
        else
            return RecBinarySearch(a, value, mid+1, right);
    }

    return -1;
}

int get(Array a, int pos) {
    if (pos >= 0 && pos < a.length)
        return a.A[pos];
    return -1;
}

void set(Array a, int pos, int value) {
    if (pos >= 0 && pos < a.length)
        a.A[pos] = value;
}

int max(Array a) {
    int max = a.A[0], i;

    for (i = 1; i < a.length; i++) {
        if (a.A[i] > max)
            max = a.A[i];
    }

    return max;
}

int min(Array a) {
    int min = a.A[0], i;

    for (i = 1; i < a.length; i++) {
        if (a.A[i] < min)
            min = a.A[i];
    }

    return min;
}

int sum(Array a) {
    int s = 0, i;

    for (i = 0; i < a.length; i++)
        s += a.A[i];

    return s;
}

float avg(Array a) {
    return (float) sum(a) / a.length;
}

void reverse(Array* a) {
    int* b;
    int i, j;

    b = new int[a->length];

    for (i = a->length - 1, j = 0; i >= 0; i--, j++)
        b[j] = a->A[i];
    for (i = 0; i < a->length; i++)
        a->A[i] = b[i];
}

void reverse2(Array* a) {
    int i, j;

    for (i = a->length - 1, j = 0; j < i; i--, j++)
        swap(&a->A[i], &a->A[j]);
}

void InsertionSort(Array* a, int value) {
    int i;

    i = a->length - 1;

    if (a->length == a->size) 
        return;
    
    while (i >= 0 && value < a->A[i]) {
        a->A[i + 1] = a->A[i];
        i--;
    }

    a->A[i] = value;
    a->length++;
}

bool isSorted(Array a) {
    int i;
    
    for (i = 1; i < a.length; i++) {
        if (a.A[i - 1] > a.A[i])
            return false;
    }

    return true;
}

void classify(Array* a) {
    int i, j;

    i = 0, j = a->length - 1;

    while (i < j) {
        while (a->A[i] < 0) i++;
        while (a->A[j] >= 0) j--;
        if (i < j)
            swap(&a->A[i], &a->A[j]);
    }
}

Array* merge(Array* a, Array* b) {
    int i, j, k;
    Array* c;
    c = new Array;
    i = j = k = 0;

    while (i < a->length && j < b->length) {
        if (a->A[i] < b->A[j])
            c->A[k++] = a->A[i++];
        else
            c->A[k++] = b->A[j++];
    }

    while (i < a->length)
        c->A[k++] = a->A[i++];
    while (j < b->length)
        c->A[k++] = b->A[j++];

    c->length = a->length + b->length;
    c->size = 20;
    return c;
}

Array* Union(Array* a, Array* b) {
    int i, j, k;
    Array* c;
    c = new Array;
    i = j = k = 0;

    while (i < a->length && j < b->length) {
        if (a->A[i] < b->A[j])
            c->A[k++] = a->A[i++];
        else if (a->A[i] > b->A[j])
            c->A[k++] = b->A[j++];
        else {
            c->A[k++] = b->A[j++];
            i++;
        }
    }

    while (i < a->length)
        c->A[k++] = a->A[i++];
    while (j < b->length)
        c->A[k++] = b->A[j++];

    c->length = k;
    c->size = 20;
    return c;
}

Array* intersection(Array* a, Array* b) {
    int i, j, k;
    Array* c;
    c = new Array;
    i = j = k = 0;

    while (i < a->length && j < b->length) {
        if (a->A[i] < b->A[j])
            i++;
        else if (a->A[i] > b->A[j])
            j++;
        else if (a->A[i] == b->A[j]) {
            c->A[k++] = b->A[j++];
            i++;
        }
    }

    c->length = k;
    c->size = 20;
    return c;
}

void print(Array a) {
    int i;
    cout << "Values: ";

    for (i = 0; i < a.length; i++) {
        cout << a.A[i] << " ";
    }
    cout << endl;
}

Array* difference(Array* a, Array* b) {
    int i, j, k;
    Array* c;
    c = new Array;
    i = j = k = 0;

    while (i < a->length && j < b->length) {
        if (a->A[i] < b->A[j])
            c->A[k++] = a->A[i++];
        else if (a->A[i] > b->A[j])
            j++;
        else {
            i++;
            j++;
        }
    }

    while (i < a->length)
        c->A[k++] = a->A[i++];

    c->length = k;
    c->size = 20;
    return c;
}

int main()
{
    Array myArray;
    int operation, position, newValue, deletedValue;

    cout << "Give the size of array: ";
    cin >> myArray.size;

    myArray.A = new int[myArray.size];
    myArray.length = 0;

    do {

        cout << endl << "Menu Items" << endl;
        cout << "1. Add" << endl;
        cout << "2. Insert" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Search" << endl;
        cout << "5. Find Sum" << endl;
        cout << "6. Print" << endl;
        cout << "7. Exit" << endl;

        cout << endl << "Choose your operation ";
        cin >> operation;

        switch (operation) {
        case 1:
            cout << endl << "Enter a new value ";
            cin >> newValue;
            add(&myArray, newValue);
            break;

        case 2:
            cout << endl << "Enter a position and a new value ";
            cin >> position >> newValue;
            insert(&myArray, position, newValue);
            break;

        case 3:
            cout << endl << "Enter a position to delete ";
            cin >> position;
            deletedValue = Delete(&myArray, position);
            cout << "Deleted value is " << deletedValue << endl;
            break;

        case 4:
            cout << endl << "Enter a value to search ";
            cin >> newValue;
            position = LinearSearch(&myArray, newValue);
            cout << "Value is at position " << position << endl;
            break;

        case 5:
            cout << "Sum is " << sum(myArray);
            break;

        case 6:
            print(myArray);
            break;
        default: 
            cout << "Invalid choice!" << endl;
        }
    } while (operation < 7);


    /*int A[3][4] = { {1,2,3,4}, {2,4,6,8}, {3,5,7,9} };
    int *B[3];

    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
    B[1][2] = 15;

    int** C;
    C = new int* [3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << A[i][j] << B[i][j] << C[i][j] << endl;
        }
    }*/

}
