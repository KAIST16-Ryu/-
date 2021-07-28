// LibQsort.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

typedef int ElementType;

void Input (ElementType **_ElementArr);
void Output (const ElementType *_ElementArr);
int compare (const void *_a, const void *_b);

int num;

int main (void) {
    ElementType *ElementArr = NULL;

    Input(&ElementArr);
    qsort(ElementArr, num, sizeof(int), compare);
    Output(ElementArr);

    return 0;
}

int compare (const void *_a, const void *_b) {
    if (*(int *)(_a) > *(int *)(_b)) return 1;
    else if (*(int *)(_a) == *(int *)(_b)) return 0;
    else return -1;
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

void Output (const ElementType *_ElementArr) {
    cout << "Result Comes as ..." << endl;
    for (int i = 0; i < num; i++) {
        cout << _ElementArr[i] << " ";
    }
    cout << endl;


    delete [] _ElementArr ;
    return;
}