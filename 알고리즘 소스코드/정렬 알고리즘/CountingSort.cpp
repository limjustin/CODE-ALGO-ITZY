#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v) {
    for(int i = 1; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

void CountingSort(vector<int> &A, int k) {
    // 1. count 배열 초기화 (인덱스 0 ~ k(상한선))
    vector<int> C(k + 1, 0);

    // 2. 개수 세기
    for(int j = 0; j < A.size(); j++)
        C[A[j]] = C[A[j]] + 1;

    // 3. 개수 누적합하기
    for(int i = 1; i < C.size(); i++)
        C[i] = C[i] + C[i - 1];

    // 4. 배정하기
    vector<int> B(A.size() + 1, 0);
    
    for(int n = A.size() - 1; n >= 0; n--) {
        B[C[A[n]]] = A[n];
        C[A[n]] = C[A[n]] - 1;
    }

    printVector(B);
}

int main(void) {
    vector<int> v = {2, 5, 3, 0, 2, 3, 0, 3};

    CountingSort(v, 5);  // k는 배열값의 상한선
}
