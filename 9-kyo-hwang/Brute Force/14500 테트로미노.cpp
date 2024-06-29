#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<pair<int, int>> Offset{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int N, M;
vector<vector<int>> Paper;
vector<vector<bool>> Visited;

bool OutOfBound(int x, int y)
{
    return x < 0 || x >= N || y < 0 || y >= M;
}

int Backtracking(int x, int y, int FigureCount = 1, int Sum = 0)
{
    if(OutOfBound(x, y) || Visited[x][y])
    {
        return 0;
    }
    else if(FigureCount > 4)
    {
        return Sum;
    }
    else
    {
        Visited[x][y] = true;
        Sum += Paper[x][y];
        int Answer = 0;
        
        for(const auto& [dx, dy] : Offset)
        {
            Answer = max(Answer, Backtracking(x + dx, y + dy, FigureCount + 1, Sum));
        }
        
        Visited[x][y] = false;
        Sum -= Paper[x][y];
        return Answer;
    }
}

int CalculateShapeT(int x, int y)
{
    int Sum = Paper[x][y];
    int MinCell = 1001;
    int SelectCnt = 1;
    for(const auto& [dx, dy] : Offset)
    {
        int nx = x + dx, ny = y + dy;
        if(OutOfBound(nx, ny))
        {
            continue;
        }
        
        MinCell = min(MinCell, Paper[nx][ny]);
        Sum += Paper[nx][ny];
        SelectCnt++;
    }
    
    if(SelectCnt < 4)  // is not Shape T
    {
        return 0;
    }
    
    if(SelectCnt == 5)  // Shape + -> Shape T
    {
        Sum -= MinCell;
    }
    
    return Sum;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N >> M;
    Paper.assign(N, vector(M, 0));
    Visited.assign(N, vector(M, false));
    
    for(auto& Row : Paper)
    {
        for(auto& Col : Row)
        {
            cin >> Col;
        }
    }
    
    int Answer = 0;
    for(int x = 0; x < N; ++x)
    {
        for(int y = 0; y < M; ++y)
        {
            Answer = max(Answer, Backtracking(x, y));  // except Shape T
            Answer = max(Answer, CalculateShapeT(x, y));  // Shape T
        }
    }
    
    cout << Answer;
    
    return 0;
}