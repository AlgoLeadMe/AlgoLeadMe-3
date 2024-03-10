#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> Map, DP;
vector<vector<bool>> Visited;

const vector<pair<int, int>> Offset = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool OutOfBound(int X, int Y)
{
    return X < 0 || X >= N || Y < 0 || Y >= M;
}

int DFS(int X = 0, int Y = 0)
{
    if(X == N - 1 && Y == M - 1)
    {
        return 1;
    }
    else if(DP[X][Y] != -1)
    {
        return DP[X][Y];
    }
    else
    {
        int Answer = 0;
        for(const auto& [Dx, Dy] : Offset)
        {
            int Nx = X + Dx, Ny = Y + Dy;
            
            if(OutOfBound(Nx, Ny) || Map[Nx][Ny] >= Map[X][Y])
            {
                continue;
            }
            
            Answer += DFS(Nx, Ny);
        }
        
        return DP[X][Y] = Answer;
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N >> M;
    Map.assign(N, vector(M, 0));
    for(auto& Row : Map)
    {
        for(auto& Col : Row)
        {
            cin >> Col;
        }
    }
    
    DP.assign(N, vector(M, -1));
    
    cout << DFS();

    return 0;
}