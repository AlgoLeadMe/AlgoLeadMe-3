#include <cstdio>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int Memory[101], Cost[101], DP[10001];

int main()
{
    int N, M; scanf(" %d %d", &N, &M);
    for(int i = 0; i < N; ++i)
    {
        scanf(" %d", &Memory[i]);
    }
    
    int TotalCost = 0;
    for(int i = 0; i < N; ++i)
    {
        scanf(" %d", &Cost[i]);
        TotalCost += Cost[i];
    }
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = TotalCost; j >= Cost[i]; --j)
        {
            DP[j] = MAX(DP[j], DP[j - Cost[i]] + Memory[i]);
        }
    }
    
    int Answer = 0;
    while(Answer < TotalCost && DP[Answer] < M)
    {
        Answer += 1;
    }
    printf("%d", Answer);

    return 0;
}