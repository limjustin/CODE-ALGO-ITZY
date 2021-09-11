#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

void SWAP(vector<int> &A, int n1, int n2) {
    int temp = A[n1];
    A[n1] = A[n2];
    A[n2] = temp;
}

int PARTITION(vector<int> &A, int p, int r) {
    int x = A[r];  // 맨 마지막에 위치한 pivot
    int i = p - 1;  // 마지노선 인덱스

    cout << "Pivot is " << A[r] << "\n";

    for(int j = p; j <= r-1; j++) {
        if(A[j] <= x) {
            i = i + 1;
            SWAP(A, i, j);
        }
    }

    SWAP(A, i+1, r);

    printVector(A);

    return i+1;
}

void QuickSort(vector<int> &A, int p, int r) {
    if(p < r) {
        int q = PARTITION(A, p, r);
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }
}

int main(void) {
    vector<int> v = {2, 5, 8, 3, 9, 4, 1, 7, 10, 6};

    QuickSort(v, 0, v.size() - 1);

    cout << "===== Result =====" << "\n";
    printVector(v);
}
