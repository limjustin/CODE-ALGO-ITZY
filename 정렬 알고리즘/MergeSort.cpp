#include <iostream>
#include <vector>
#define INF 99999
using namespace std;

void printVector(vector<int> &v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

// 나의 코드
void MERGE(vector<int> &A, int p, int q, int r) {
    cout << "MERGE(A, " << p << ", " << q << ", " << r << ") \n";
    int ls = p;
    int rs = q + 1;

    // 1. 결과 배열 초기화
    int len = (r - p) + 1;
    vector<int> res;

    // 2. 비교해서 집어넣기
    while(ls <= q && rs <= r) {
        if(A[ls] < A[rs]) {
            res.push_back(A[ls]);
            ls = ls + 1;
        } else {
            res.push_back(A[rs]);
            rs = rs + 1;
        }
    }

    // 3. 남은 부분 집어넣기
    if(ls > q) {
        for(int l = rs; l <= r; l++)
            res.push_back(A[l]);
    } else if(rs > r) {
        for(int l = ls; l <= q; l++)
            res.push_back(A[l]);
    }

    // 4. 결과 배열을 원본 배열에 복사
    for(int i = 0; i < len; i++)
        A[p + i] = res[i];

    printVector(A);
}

// 교수님의 코드
void MERGE(vector<int> &A, int p, int q, int r) {
    cout << "MERGE(A, " << p << ", " << q << ", " << r << ") \n";

    int n1 = q - p + 1;  // 왼쪽 배열 길이 (p ~ q)
    int n2 = r - q;  // 오른쪽 배열 길이 (q+1 ~ r)

    vector<int> L; vector<int> R;

    for(int i = 0; i < n1; i++)
        L.push_back(A[p + i]);
    for(int j = 0; j < n2; j++)
        R.push_back(A[(q + 1) + j]);

    L.push_back(INF); R.push_back(INF);

    int i = 0; int j = 0;
    for(int k = p; k <= r; k++) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }
    }

    printVector(A);
}

void MergeSort(vector<int> &A, int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        MERGE(A, p, q, r);
    }
}

int main(void) {
    vector<int> v = {14, 31, 25, 4, 74, 32, 66, 7};

    MergeSort(v, 0, v.size()-1);

    cout << "====== Result ======" << "\n";
    printVector(v);
}
