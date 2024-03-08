#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int Alp, int Cop, vector<vector<int>> Problems) 
{
    Problems.push_back({0, 0, 1, 0, 1});
    Problems.push_back({0, 0, 0, 1, 1});
    
    int MaxAlpReq = 0, MaxCopReq = 0;
    for(const auto& Problem : Problems)
    {
        MaxAlpReq = max(MaxAlpReq, Problem[0]);
        MaxCopReq = max(MaxCopReq, Problem[1]);
    }
    
    priority_queue<vector<int>, vector<vector<int>>, greater<>> PQ;
    PQ.push({0, Alp, Cop});
    
    vector<vector<int>> MinCosts(151, vector(151, 10001));
    MinCosts[Alp][Cop] = 0;
    
    while(!PQ.empty())
    {
        const auto Src = PQ.top();
        PQ.pop();
        
        if(MinCosts[Src[1]][Src[2]] < Src[0])
        {
            continue;
        }
        
        for(const auto& Problem : Problems)
        {
            if(Src[1] < Problem[0] || Src[2] < Problem[1])
            {
                continue;
            }
            
            int DstCost = Src[0] + Problem[4];
            int DstAlp = min(MaxAlpReq, Src[1] + Problem[2]);
            int DstCop = min(MaxCopReq, Src[2] + Problem[3]);
            
            if(MinCosts[DstAlp][DstCop] <= DstCost)
            {
                continue;
            }
            
            MinCosts[DstAlp][DstCop] = DstCost;
            PQ.push({DstCost, DstAlp, DstCop});
        }
    }
    
    return MinCosts[MaxAlpReq][MaxCopReq];
}