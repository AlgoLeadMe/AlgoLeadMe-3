#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<pair<int, int>> TeamMatches
{
    {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, 
    {1, 2}, {1, 3}, {1, 4}, {1, 5},
    {2, 3}, {2, 4}, {2, 5},
    {3, 4}, {3, 5},
    {4, 5},
};

const vector<pair<int, int>> MatchResultIndices
{// 1 win,   tie,   2 win
    {0, 2}, {1, 1}, {2, 0}
};

vector<vector<int>> MatchScore;

bool Backtracking(int Match = 0)
{
    if(Match == TeamMatches.size())
    {
        for(const auto& Team : MatchScore)
        {
            if(count(Team.begin(), Team.end(), 0) != 3)
            {
                return false;
            }
        }
        
        return true;
    }
    
    const auto& [Team1, Team2] = TeamMatches[Match];
    for(const auto& [i, j] : MatchResultIndices)
    {
        if(MatchScore[Team1][i] <= 0 || MatchScore[Team2][j] <= 0)
        {
            continue;
        }
        
        --MatchScore[Team1][i];
        --MatchScore[Team2][j];
        
        if(Backtracking(Match + 1))
        {
            return true;
        }
        
        ++MatchScore[Team1][i];
        ++MatchScore[Team2][j];
    }
    
    return false;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    for(int T = 1; T <= 4; ++T)
    {
        MatchScore.assign(6, vector(3, 0));
        for(auto& Team : MatchScore)
        {
            for(auto& Score : Team)
            {
                cin >> Score;
            }
        }
        cout << Backtracking() << " ";
    }

    return 0;
}