
#include <iostream>
using namespace std;

int main()
{
    const int N = 10, M = 10;
    int A[N] = { 1, 2, 3, 4, 5, 6, 3, 2, 7, 9 };
    int B[M] = { 8, 4, 9, 11, 12, 23, 5, 7, 9, 1 };

    
    int* pA = new int[N];
    int m = 0; 

   
    for (int i = 0; i < N; i++) {
        bool found = false;

       
        for (int j = 0; j < M; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }

       
        if (!found) {
            bool alreadyIn = false;

            
            for (int k = 0; k < m; k++) {
                if (A[i] == pA[k]) {
                    alreadyIn = true;
                    break;
                }
            }

            
            if (!alreadyIn) {
                pA[m++] = A[i];
            }
        }
    }

    
    
    for (int i = 0; i < m; i++) {
        cout << pA[i] << " "; 
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        bool found = false;
        for (int j = 0; j < M; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            bool alreadyIn = false;
            for (int k = 0; k < m; k++) {
                if (A[i] == pA[k]) {
                    alreadyIn = true;
                    break;
                }
            }
            if (!alreadyIn) {
                pA[m++] = A[i];
            }
        }
    }

    // Додаємо унікальні елементи з масиву B, яких немає в масиві A
    for (int i = 0; i < M; i++) {
        bool found = false;
        for (int j = 0; j < N; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            bool alreadyIn = false;
            for (int k = 0; k < m; k++) {
                if (B[i] == pA[k]) {
                    alreadyIn = true;
                    break;
                }
            }
            if (!alreadyIn) {
                pA[m++] = B[i];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cout << pA[i] << " ";
    }
    cout << endl;

    delete[] pA; 
   
}


