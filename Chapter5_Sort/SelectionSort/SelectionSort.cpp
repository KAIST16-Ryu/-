// SelectionSort

#include <iostream>

using namespace std;

typedef int ElementType;

bool compare (ElementType *_a, ElementType *_b);
void Input (ElementType **);
void SelectionSort (ElementType *);
void Output (ElementType *);

int num;

int main (void) {

    ElementType *arr = NULL;
    
    Input (&arr);
    SelectionSort (arr);
    Output (arr);

    return 0;
}

bool compare (ElementType *_a, ElementType *_b) {
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

void SelectionSort (ElementType *_arr) {
    int IndexMin;
    ElementType Temp;
    for (int i = 0; i < num-1; i++) {
        IndexMin = i;
        for (int j = i+1; j < num; j++) {
            if (compare((_arr+IndexMin), (_arr+j))) {
                IndexMin = j;
            }
        }
        Temp = _arr[IndexMin];
        _arr[IndexMin] = _arr[i];
        _arr[i] = Temp;
    }
    
    return;
}

void Output (ElementType *_arr) {
    

    return;
}