// QsortWithoutRecursion.cpp

#include <iostream>

using namespace std;

typedef int ElementType;

void Input (ElementType **_ElementArr);
void swap (ElementType *_a, ElementType *_b);
int Partition (ElementType *_Arr, int _start, int _end);
void QsortWithoutRecursion (ElementType *_Arr, int _start, int _end);
void Output (const ElementType *_ElementArr);

int num;

int main (void) {

    ElementType *ElementArr=NULL;

    Input (&ElementArr);
    QsortWithoutRecursion (ElementArr, 0, num);
    Output(ElementArr);
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

void swap (ElementType *_a, ElementType *_b) {
    ElementType temp;

    temp = (*_a);
    (*_a) = (*_b);
    (*_b) = temp;

    return;
}

int Partition (ElementType *_Arr, int _start, int _end) {
    int pivot = _start;
    int start = _start;
    int end = _end;

    while (start < end) {
        while ((++start < _end) && (_Arr[start] <= _Arr[pivot]));
        while ((--end > _start) && (_Arr[end] > _Arr[pivot]));

        if (start < end) swap ((_Arr+start), (_Arr+end));

        else {
            swap ((_Arr+end), (_Arr+pivot));
            return end;
        }
    }
}

void QsortWithoutRecursion (ElementType *_Arr, int _start, int _end) {
    int StackArr [num+1] = {0, };
    int top = -1;
    int index, start, end;

    StackArr[++top] = _start;
    StackArr[++top] = _end;

    while (top > 0) {
        /* Partition. */
        end = StackArr[top--];
        start = StackArr[top--];

        index = Partition (_Arr, start, end);

        /* Left Condition. */
        if (index > start + 1) {
            StackArr[++top] = start;
            StackArr[++top] = index; 
        }
        /* Right Condition. */
        if (index + 2 < end) {
            StackArr[++top] = index+1;
            StackArr[++top] = end;
        }
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