#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}

// 나의 코드 //
void InsertionSort(vector<int> &v) {
    int temp; int sorted;

    for(int idx = 1; idx < v.size(); idx++) {

        // 위치해야할 인덱스를 찾기
        for(sorted = 0; sorted < idx; sorted++) {
            if(v[idx] < v[sorted]) {
                temp = v[idx];
                break;
            }
        }

        // 나머지 원소들은 뒤로 밀기
        for(int align = idx - 1; align >= sorted; align--) {
            v[align + 1] = v[align];
        }

        // 해당 인덱스에 넣기
        if(idx != sorted)
            v[sorted] = temp;

        printVector(v);
    }
}

// 교수님의 코드 //
void InsertionSort(vector<int> &A) {
    int i; int key;

    for(int j = 1; j < A.size(); j++) {
        key = A[j];

        i = j - 1;

        // 비교하고 뒤로 밀어버리는 과정을 합쳤음
        while(i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            
            i = i - 1;
        }

        A[i + 1] = key;

        printVector(A);
    }
}

int main(void) {
    vector<int> v = {8, 2, 4, 9, 3, 6};
    
    InsertionSort(v);

    cout << "=== Result ===" << "\n";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}
