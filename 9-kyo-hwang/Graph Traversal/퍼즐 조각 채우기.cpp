#include <string>
#include <vector>
#include <functional>
#include <set>

using namespace std;
using FPoint = pair<int, int>;

vector<vector<FPoint>> GetBlocksFrom(vector<vector<int>>& Board, bool IsBoard = true)
{
    const vector<FPoint> Offset{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    auto OutOfBound = [&](int x, int y)
    {
        return x < 0 || x >= Board.size() || y < 0 || y >= Board.size();
    };
    
    vector<vector<FPoint>> Blocks;
    
    function<void(int, int)> DFS = [&](int x, int y)
    {
        Blocks.back().emplace_back(x, y);
        Board[x][y] = (IsBoard ? 1 : 0);

        for(const auto& [dx, dy] : Offset)
        {
            int nx = x + dx, ny = y + dy;
            if(!OutOfBound(nx, ny) && Board[nx][ny] == (IsBoard ? 0 : 1))
            {
                DFS(nx, ny);
            }
        }
    };
    
    for(int i = 0; i < Board.size(); ++i)
    {
        for(int j = 0; j < Board.size(); ++j)
        {
            if(IsBoard && Board[i][j] == 0
              || !IsBoard && Board[i][j] == 1)
            {
                Blocks.push_back({});
                DFS(i, j);
            }
        }
    }
    
    return Blocks;
}

vector<vector<int>> GetGridFrom(const vector<FPoint>& Block)
{
    auto [MinX, MinY] = Block[0];
    auto [MaxX, MaxY] = Block[0];

    for(const auto& [x, y] : Block)
    {
        if(x < MinX) MinX = x;
        else if(x > MaxX) MaxX = x;

        if(y < MinY) MinY = y;
        else if(y > MaxY) MaxY = y;
    }

    vector<vector<int>> Grid(MaxX - MinX + 1, vector<int>(MaxY - MinY + 1, 0));
    for(const auto& [x, y] : Block)
    {
        Grid[x - MinX][y - MinY] = 1;
    }
    
    return Grid;
}

int Rotate(vector<vector<int>>& Grid)
{
    vector<vector<int>> Rotated(Grid[0].size(), vector<int>(Grid.size(), 0));
    int NumCell = 0;
    
    for(int i = 0; i < Grid.size(); ++i)
    {
        for(int j = 0; j < Grid[0].size(); ++j)
        {
            if(Grid[i][j] == 1) NumCell++;
            Rotated[j][Grid.size() - 1 - i] = Grid[i][j];
        }
    }
    
    Grid = Rotated;
    return NumCell;
}

int solution(vector<vector<int>> InGameBoard, vector<vector<int>> InTable) 
{
    vector<vector<FPoint>> BoardBlocks = GetBlocksFrom(InGameBoard, true);
    vector<vector<FPoint>> TableBlocks = GetBlocksFrom(InTable, false);
    
    set<vector<FPoint>> UsedTableBlocks;
    int Answer = 0;
    
    for(const vector<FPoint>& BoardBlock : BoardBlocks)
    {
        bool IsFilled = false;
        vector<vector<int>> BoardBlockGrid = GetGridFrom(BoardBlock);
        
        for(const vector<FPoint>& TableBlock : TableBlocks)
        {
            if(IsFilled) break;
            if(UsedTableBlocks.count(TableBlock)) continue;
            
            vector<vector<int>> TableBlockGrid = GetGridFrom(TableBlock);
            for(int i = 0; i < 4; ++i)
            {
                int NumCell = Rotate(TableBlockGrid);
                if(BoardBlockGrid == TableBlockGrid)
                {
                    Answer += NumCell;
                    UsedTableBlocks.emplace(TableBlock);
                    IsFilled = true;
                    break;
                }
            }
        }
    }
    
    return Answer;
}