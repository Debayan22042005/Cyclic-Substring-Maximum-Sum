#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}

int main() 
{
    int n, i;
    scanf("%d", &n);
    long long K;
    scanf("%lld", &K);
    long long A[100005];
    long long B[100005];

    for (i = 0; i < n; i++) 
    {
        scanf("%lld", &A[i]);
    }

    for (i = 1; i < n; i++) 
    {
        if ((A[i] % K) != (A[0] % K)) 
        {
            printf("-1");
            return 0;
        }
    }

    for (i = 0; i < n; i++) 
    {
        B[i] = A[i] / K;
    }

    qsort(B, n, sizeof(long long), compare);

    long long median = B[n / 2];
    long long operations = 0;

    for (i = 0; i < n; i++) 
    {
        if (B[i] > median)
            operations += (B[i] - median);
        else
            operations += (median - B[i]);
    }

    printf("%lld", operations);

    return 0;
}