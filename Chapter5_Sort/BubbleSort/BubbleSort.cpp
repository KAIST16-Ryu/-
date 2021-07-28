// BubbleSort

#include <iostream>

using namespace std;

typedef int ElementType;

void SwapIfBigger (ElementType *, ElementType *);
void Input (ElementType **);
void BubbleSort (ElementType *);
void Output (ElementType *);

int num;

int main (void) {

    ElementType *arr = NULL;
    
    Input (&arr);
    BubbleSort (arr);
    Output (arr);

    return 0;
}

void SwapIfBigger (ElementType *_a, ElementType *_b) {
    if ((*_a) > (*_b)) {
        ElementType Temp = (*_a);
        (*_a) = (*_b);
        (*_b) = Temp;
    }
    
    return;
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

void BubbleSort (ElementType *_arr) {
    for (int i = num-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            SwapIfBigger ((_arr+j), (_arr+j+1));
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