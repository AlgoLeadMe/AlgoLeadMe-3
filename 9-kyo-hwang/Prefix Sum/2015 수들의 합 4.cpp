#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, K; cin >> N >> K;
    vector<int> PrefixSum(N + 1, 0);
    
    unordered_map<int, int64_t> Cnt;
    
    int64_t Answer = 0;
    for(int i = 1; i <= N; ++i)
    {
        int Ai; cin >> Ai;
        PrefixSum[i] = PrefixSum[i - 1] + Ai;
        
        if(PrefixSum[i] == K)
        {
            Answer += 1;
        }
    }
    
    for(int i = 1; i <= N; ++i)
    {
        Answer += Cnt[PrefixSum[i] - K];
        Cnt[PrefixSum[i]] += 1;
    }
    
    cout << Answer;
    
    return 0;
}