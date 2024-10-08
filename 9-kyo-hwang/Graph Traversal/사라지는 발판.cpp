#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const vector<pair<int, int>> Offset{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector<vector<int>> Board;

bool OutOfBound(int r, int c)
{
    return r < 0 || r >= Board.size() || c < 0 || c >= Board[0].size();
}

int DFS(pair<int, int> ALoc, pair<int, int> BLoc)
{
    const auto& [r, c] = ALoc;
    if(Board[r][c] == 0)
    {
        return 0;
    }
    
    int Answer = 0;
    Board[r][c] = 0;
    
    for(const auto& [dr, dc] : Offset)
    {
        int nr = r + dr, nc = c + dc;
        if(OutOfBound(nr, nc) || Board[nr][nc] == 0)
        {
            continue;
        }
        
        int RetVal = DFS(BLoc, {nr, nc}) + 1;
        
        if(Answer % 2 == 0 && RetVal % 2 == 1) Answer = RetVal;
        else if(Answer % 2 == 0 && RetVal % 2 == 0) Answer = max(Answer, RetVal);
        else if(Answer % 2 == 1 && RetVal % 2 == 1) Answer = min(Answer, RetVal);
    }
    
    Board[r][c] = 1;
    return Answer;
}

int solution(vector<vector<int>> InBoard, vector<int> InALoc, vector<int> InBLoc) 
{
    Board = InBoard;
    return DFS({InALoc[0], InALoc[1]}, {InBLoc[0], InBLoc[1]});
}