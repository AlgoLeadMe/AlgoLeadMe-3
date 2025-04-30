#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Tree;
pair<int, int> DFS(const vector<int>& InLosses, const int Head)
{
    const int LossIfHeadParticipation = InLosses[Head - 1];
    
    if(Tree[Head].empty())
    {
        return {0, LossIfHeadParticipation};
    }

    int TotalLosses = 0, MinLossDifference = 1e9;
    bool bMemberParticipation = false;
    
    for(const int Member : Tree[Head])
    {
        const auto& [LossIfNotParticipation, LossIfParticipation] = DFS(InLosses, Member);
        TotalLosses += min(LossIfNotParticipation, LossIfParticipation);

        if(LossIfNotParticipation >= LossIfParticipation)
        {
            bMemberParticipation = true;
        }

        MinLossDifference = min(MinLossDifference, LossIfParticipation - LossIfNotParticipation);
    }

    if(bMemberParticipation)
    {
        return {TotalLosses, LossIfHeadParticipation + TotalLosses};
    }
    else
    {
        return {TotalLosses + MinLossDifference, LossIfHeadParticipation + TotalLosses};
    }
}

int solution(vector<int> InSales, vector<vector<int>> InLinks) 
{
    Tree.resize(InSales.size() + 1);
    for(const vector<int>& Link : InLinks)
    {
        int a = Link[0], b = Link[1];
        Tree[a].emplace_back(b);
    }

    const auto& [LossIfNotParticipation, LossIfParticipation] = DFS(InSales, 1);
    return min(LossIfNotParticipation, LossIfParticipation);
}