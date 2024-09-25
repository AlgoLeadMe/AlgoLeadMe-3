#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M; cin >> N >> M;
    
    vector<int> Nums(N);
    for(int& Num : Nums)
    {
        cin >> Num;
    }
    
    auto IsValid = [&](int EstimateScore)
    {
        int Count = 1;
        int Min = Nums[0], Max = Nums[0];
        
        for(int i = 1; i < N; ++i)
        {
            Min = min(Min, Nums[i]);
            Max = max(Max, Nums[i]);
            
            if(Max - Min > EstimateScore)
            {
                Count++;
                Min = Nums[i];
                Max = Nums[i];
            }
        }
        
        return Count <= M;
    };
    
    int Min = 0, Max = *max_element(Nums.begin(), Nums.end());
    int Score = Max;
    while(Min <= Max)
    {
        int EstimateScore = (Min + Max) / 2;
        if(IsValid(EstimateScore))
        {
            Score = min(Score, EstimateScore);
            Max = EstimateScore - 1;
        }
        else
        {
            Min = EstimateScore + 1;
        }
    }
    
    cout << Score;

    return 0;
}