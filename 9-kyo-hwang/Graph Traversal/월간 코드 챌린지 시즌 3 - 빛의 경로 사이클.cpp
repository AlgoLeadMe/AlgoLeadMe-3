#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const vector<pair<int, int>> Offset{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

size_t N, M;
vector<vector<vector<bool>>> Visited;  // (x, y, dir)

inline void Compensation(int& Val, int MinVal, int MaxVal)
{
    if(Val < MinVal) Val = MaxVal;
    else if(Val > MaxVal) Val = 0;
}

int DFS(const vector<string>& Grid, int x, int y, int d, int CycleLength = 1)
{
    Visited[x][y][d] = true;
    
    int nd;
    switch(Grid[x][y])
    {
        case 'S':
            nd = d;
            break;
        case 'L':
            nd = d - 1;
            Compensation(nd, 0, 3);
            break;
        case 'R':
            nd = d + 1;
            Compensation(nd, 0, 3);
            break;
    }
    
    const auto& [dx, dy] = Offset[nd];
    int nx = x + dx, ny = y + dy;
    Compensation(nx, 0, N - 1), Compensation(ny, 0, M - 1);
    
    if(Visited[nx][ny][nd])
    {
        return CycleLength;
    }
    else
    {
        return DFS(Grid, nx, ny, nd, CycleLength + 1);
    }
}

vector<int> solution(vector<string> Grid) 
{
    N = Grid.size(), M = Grid[0].size();
    Visited.assign(N, vector(M, vector(4, false)));
    
    vector<int> Answer;
    for(int x = 0; x < N; ++x)
    {
        for(int y = 0; y < M; ++y)
        {
            for(int d = 0; d < 4; ++d)
            {
                if(!Visited[x][y][d])
                {
                    Answer.emplace_back(DFS(Grid, x, y, d));
                }
            }
        }
    }
    
    sort(Answer.begin(), Answer.end());
    
    return Answer;
}