#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int InDistance, vector<int> InRocks, int NumRemove) 
{
    InRocks.emplace_back(InDistance);
    sort(InRocks.begin(), InRocks.end());
    
    int LowerDistance = 1, UpperDistance = InDistance;
    int Answer = 0;
    
    auto IsValid = [&](int EstimateDistance)
    {
        int Count = 0, CurrentPos = 0;
        for(int RockPos : InRocks)
        {
            int Distance = RockPos - CurrentPos;
            if(Distance >= EstimateDistance)
            {
                CurrentPos = RockPos;
            }
            else
            {
                Count++;
            }
        }
        
        return Count <= NumRemove;
    };

    while(LowerDistance <= UpperDistance)
    {
        int EstimateDistance = (LowerDistance + UpperDistance) / 2;
        if(IsValid(EstimateDistance))
        {
            Answer = EstimateDistance;
            LowerDistance = EstimateDistance + 1;
        }
        else
        {
            UpperDistance = EstimateDistance - 1;
        }
    }
    
    return Answer;
}