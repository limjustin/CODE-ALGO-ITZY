#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> result;

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

void MaxHeapify(vector<int> &A, int idx, int heap_size) {
    int left = 2 * idx;
    int right = 2 * idx + 1;
    int largest; int temp;

    if(left <= heap_size && A[left] > A[idx])
        largest = left;
    else
        largest = idx;
    
    if(right <= heap_size && A[right] > A[largest])
        largest = right;

    if(largest != idx) {
        SWAP(A, idx, largest);
        MaxHeapify(A, largest, heap_size);
    }
}

void BUILD_MAX_HEAP(vector<int> &A) {
    int heap_size = A.size() - 1;

    for(int i = floor(heap_size / 2); i >= 1; i--) {
        MaxHeapify(A, i, heap_size);
        printVector(A);
    }
}

void HeapSort(vector<int> &A) {
    BUILD_MAX_HEAP(A);
    int heap_size = A.size() - 1;
    cout << ">> BUILD_MAX_HEAP is done. \n";

    for(int idx = heap_size; idx >= 2; idx--) {
        SWAP(A, 1, idx);
        result.push_back(A[idx]);
        heap_size = heap_size - 1;
        MaxHeapify(A, 1, heap_size);

        printVector(A);

        if(idx == 2)
            result.push_back(A[1]);
    }
}

int main(void) {
    vector<int> v = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    HeapSort(v);

    reverse(result.begin(), result.end());
    cout << "======= Result =======" << "\n";
    printVector(result);
}
