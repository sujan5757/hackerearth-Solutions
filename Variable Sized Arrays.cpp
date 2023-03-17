#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a;
    int n, q, i, j, k;
    scanf("%d %d", &n, &q);
    a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        a[i] = (int *)malloc(k * sizeof(int));
        for (j = 0; j < k; j++)
            scanf("%d", &a[i][j]);
    }
    for (i = 0; i < q; i++)
    {
        scanf("%d %d", &k, &j);
        printf("%d\n", a[k][j]);
    }
    return 0;
}
