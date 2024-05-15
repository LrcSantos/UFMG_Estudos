#include "ordenacao.h"
#include <stdbool.h>

void swap(int *A, unsigned i, unsigned j) {
    int x = A[i];
    int y = A[j];
    A[i] = y;
    A[j] = x;
}

bool sorted(int *A, int n) {

    int i;
    int t = false;
    for (i = 1; i < n; i++){
        if (A[i] >= A[i-1]){
            t = true;
        }
        else{
            t = false;
            break;
        }
        
    }
    return t;
   
}

void bubblesort(int *A, int n) {
    int i;
    
    while (sorted(A, n) != true){

        for (i = 0; i < n-1; i++){
            if (A[i] > A[i+1]){
                swap(A, i, i+1);
            }  
            else{
                continue;
            }
        }
    }
}