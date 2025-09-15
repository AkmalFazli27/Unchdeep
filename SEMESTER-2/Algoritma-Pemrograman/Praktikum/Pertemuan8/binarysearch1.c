#include <stdio.h>

int binary_search01(int arr[], int N, int left, int right) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > left && arr[i] <= right) {
            count++;
        }
    }
    return count;
}

int main() {
    int N; 
    scanf("%d", &N);
    int A[N]; 

    
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int Q; 
    scanf("%d", &Q);
    int X[Q]; 
    int Y[Q]; 

    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &X[i], &Y[i]);
    }

    for (int i = 0; i < Q; i++) {
        int left = X[i];
        int right = Y[i];
        int result = binary_search01(A, N, left, right);
        printf("%d\n", result);
    }
 
    return 0;
}
