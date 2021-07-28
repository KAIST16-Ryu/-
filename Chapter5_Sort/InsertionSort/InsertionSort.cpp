// InsertionSort

#include <iostream>
#include <cstring>

using namespace std;

typedef int ElementType;

bool compare(ElementType *, ElementType *);
void Input (ElementType **);
void InsertionSort (ElementType *);
void Output (ElementType *);

int num;

int main (void) {

    ElementType *arr = NULL;
    
    Input (&arr);
    InsertionSort (arr);
    Output (arr);

    return 0;
}

bool compare(ElementType *_a, ElementType *_b) {
    if ((*_a) > (*_b)) return true;
    else return false;
}

void Input (ElementType **_arr) {
    cout << "N: ";
    cin >> num;
    (*_arr) = new ElementType [num];

    cout << "Number: ";
    for (int i = 0; i < num; i++) {
        cin >> (*_arr)[i];
    }

    return;
}

void InsertionSort (ElementType *_arr) {
    if (num == 1) return;
    else {
        ElementType temp;
        for (int i = 1; i < num; i++) {
            for (int j = 0; j < i; j++) {
                if (compare ((_arr+j), (_arr+i))){
                    temp = _arr[i];
                    _arr[i] = 0;

                    memmove ((_arr+j+1), (_arr+j), sizeof(ElementType)*(i-j));
                    _arr[j] = temp;
                }
            }
        }

    }
    
    return;
}

void Output (ElementType *_arr) {
    cout << "Result Comes as ..." << endl;
    for (int i = 0; i < num; i++) {
        cout << _arr[i] << " ";
    }
    cout << endl;

    return;
}