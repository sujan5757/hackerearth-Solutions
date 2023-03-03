#include<stdio.h>
 
struct Pair {
    int first;
    int second;
};
 
void minOrder(int arr[], int N, int K, int one, int zero) {
    if (one == 0 || zero == 0) {
        printf("0\n");
        for (int i = 0; i < K-1; i++) {
            printf("%d %d\n", i+1, i+1);
        }
        printf("%d %d\n", K, N);
    }
    else {
        one = 0, zero = 0;
        for (int i = K-1; i < N; i++) {
            if (arr[i] == 1) one++;
            else zero++;
        }
        if (one == 0 || zero == 0) {
            printf("0\n");
            for (int i = 1; i < K; i++) {
                printf("%d %d\n", i, i);
            }
            printf("%d %d\n", K, N);
        }
        else {
            int index = N-1;
            struct Pair v[K];
            int m = 0, i, prev = arr[N-1];
            for (i = N-1; i >= 0 && m < K-1;) {
                for (int j = i; N-(N-j-1) >= K-m; j--) {
                    if (arr[j] != prev) {
                        break;
                    }
                    i--;
                }
                prev = arr[i];
                v[m].first = i+2;
                v[m].second = index+1;
                m++;
                index = i;
            }
            v[K-1].first = 1;
            v[K-1].second = index+1;
            m++;
            one = 0;
            zero = 0;
            for (int i = index; i >= 0; i--) {
                if (arr[i] == 1) one++;
                else zero++;
            }
            if (one == 0 || zero == 0) {
                printf("0\n");
                for (int i = K-1; i >= 0; i--) {
                    printf("%d %d\n", v[i].first, v[i].second);
                }
            }
            else {
                printf("1\n");
                for (int i = 1; i < K; i++) {
                    printf("%d %d\n", i, i);
                }
                printf("%d %d\n", K, N);
            }
        }
    }
}
 
int main() {
    int N, K, one = 0, zero = 0;
    scanf("%d %d", &N, &K);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 1) one++;
        else zero++;
    }
    minOrder(arr, N, K, one, zero);
    return 0;
}
