#include <vector>
#include <string>
#include <tuple>

using namespace std;

const vector<tuple<int, int, char>> Offset = {{1, 0, 'd'}, {0, -1, 'l'}, {0, 1, 'r'}, {-1, 0, 'u'}};
vector<vector<vector<bool>>> Visited;

bool OutOfBound(const int n, const int m, int InX, int InY)
{
    return InX < 1 || InX > n || InY < 1 || InY > m;
}

string Answer = "";
void DFS(const int n, const int m, const int r, const int c, int InX, int InY, int Remain, string Path = "")
{
    if(Remain == 0)
    {
        if(InX == r && InY == c)
        {
            Answer = Path;
        }
        return;
    }
    
    Visited[Remain][InX][InY] = true;
    for(const auto& [Dx, Dy, Dp] : Offset)
    {
        int Nx = InX + Dx, Ny = InY + Dy;
        string NextPath = Path + Dp;
        int NextRemain = Remain - 1;
        
        if(!OutOfBound(n, m, Nx, Ny) && !Visited[NextRemain][Nx][Ny])
        {
            DFS(n, m, r, c, Nx, Ny, NextRemain, NextPath);
        }
        
        if(!Answer.empty())
        {
            break;
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k)
{
    Visited.assign(k + 1, vector(n + 1, vector(m + 1, false)));
    DFS(n, m, r, c, x, y, k);
    return Answer.empty() ? "impossible" : Answer;
}