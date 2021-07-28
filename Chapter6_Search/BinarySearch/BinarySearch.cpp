// BinarySearch.cpp

#include "Score.h"
#include <iostream>
#include <cstring>

using namespace std;
typedef double ElementType;

void Input (void);
void swap(Score *_a, Score *_b);
int Partition (int _start, int _end);
void ScoreQuickSort (int _start, int _end);
int BinarySearch (int _start, int _end);

extern Score DataSet [];
int num;
double TargetScore;

int main (void) {
    int result;
    num = sizeof (DataSet) / (sizeof(Score));
    Input();
    ScoreQuickSort (0, num);

    // for ( int i = 0; i < num; i++ ) cout << "DataSet[i].score : " << DataSet[i].score << endl;
    // cout << "TargetScore: " << TargetScore << endl;
    
    result = BinarySearch (0, num);
    cout << "result is (" << result << ", " << TargetScore << ")." << endl;

    return 0;
}

void Input (void) {
    cout << "Give me a score.: ";
    cin >> TargetScore;

    return;
}

void swap (Score *_a, Score *_b) {
    Score temp;

    temp.number = _a->number;
    temp.score = _a->score;
    _a->number = _b->number;
    _a->score = _b->score;
    _b->number = temp.number;
    _b->score = temp.score;

    return;
}

int Partition (int _start, int _end) {
    int pivot = _start;
    int start = _start;
    int end = _end;

    while (start < end) {
        while ((++start < _end) && (DataSet[start].score <= DataSet[pivot].score));
        while ((--end < _end) && (DataSet[end].score > DataSet[pivot].score));

        if (start < end) swap ((DataSet+start), (DataSet+end));

        else {
            swap ((DataSet+end), (DataSet+pivot));
            return end;
        }
    }
}

void ScoreQuickSort (int _start, int _end) {
    int *StackArr = new int [num+1] {0, };
    int top = -1;
    int index, start, end;

    StackArr[++top] = _start;
    StackArr[++top] = _end;

    while (top > 0) {
        /* Partition. */
        end = StackArr[top--];
        start = StackArr[top--];

        index = Partition (start, end);

        /* Left Condition. */
        if (index > start +1) {
            StackArr[++top] = start;
            StackArr[++top] = index;
        }

        /* Right Condition. */
        if (index + 2 < end) {
            StackArr[++top] = index+1;
            StackArr[++top] = end;
        }
    }

    delete [] StackArr;
    return;
}

int BinarySearch (int _start, int _end) {
    int start = _start;
    int end = _end;
    int target;

    while (true) {
        target = (end+start)/2;

        if (DataSet[target].score == TargetScore) {
            return DataSet[target].number;
        }
        else {
            if (start+1 >= end) {
                cout << "TargetScore is not in the list." << endl;
                return 0;
            }
            else {
                if (DataSet[target].score < TargetScore){
                    start = target+1;
                }
                else {
                    end = target;
                }
            }
        }
    }
}