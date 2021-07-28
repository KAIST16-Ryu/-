// QuickSort.cpp

#include <iostream>

using namespace std;
typedef int ElementType;

void Input (ElementType **_ElementArr);
bool aIsLarge (ElementType *_a, ElementType *_b);
void swap (ElementType *_a, ElementType *_b);
void QuickSort (ElementType *_Arr, int _start, int _end);
void Output (const ElementType *_ElementArr);

int num;

int main (void) {
    ElementType *ElementArr;

    Input (&ElementArr);
    QuickSort(ElementArr, 0, num);
    Output (ElementArr);

    return 0;
}

void Input (ElementType **_ElementArr) {
    cout << "N: ";
    cin >> num;
    (*_ElementArr) = new ElementType [num];

    cout << "Number: ";
    for (int i = 0; i < num; i++) {
        cin >> (*_ElementArr)[i];
    }

    return;
}

bool aIsLarge (ElementType *_a, ElementType *_b) {
    if ((*_a) > (*_b)) return true;
    else return false;
}

void swap (ElementType *_a, ElementType *_b) {
    ElementType Temp;

    Temp = (*_a);
    (*_a) = (*_b);
    (*_b) = Temp;

    return;
}

void QuickSort (ElementType *_Arr, int _start, int _end) {
    /* End BackTracking. */
    if (_end <= _start+1) {
        return;
    }
    /* BackTracking. */
    else {
        int pivot = _start;
        int row = _start;
        int high = _end;
        ElementType temp;
        
        /* Continue Until row & high meet each other. */
        while ( row < high ) {
            while ( (++row < _end) && !aIsLarge((_Arr+row), (_Arr+pivot)) );
            while ( (--high > _start) && aIsLarge((_Arr+high), (_Arr+pivot)) );

            if (row < high) swap( (_Arr+row), (_Arr+high) );
        }

        /* Swap pivot and middle. */
        swap((_Arr+pivot), (_Arr+high));

        /* Divide & Conquer. */
        QuickSort (_Arr, _start, high);
        QuickSort (_Arr, high+1, _end);
    }
}

void Output (const ElementType *_ElementArr) {
    cout << "Result Comes as ..." << endl;
    for (int i = 0; i < num; i++) {
        cout << _ElementArr[i] << " ";
    }
    cout << endl;


    delete [] _ElementArr ;
    return;
}