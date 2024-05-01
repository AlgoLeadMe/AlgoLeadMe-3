#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <algorithm>

using namespace std;
using FIsland = tuple<int, int, int>;
using FEdge = tuple<int, int, int>;
const vector<pair<int, int>> Offset{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

enum class EMap
{
    SEA = 0,
    LAND = 1,
};

inline int SEA()
{
    return static_cast<int>(EMap::SEA);
}

inline int LAND()
{
    return static_cast<int>(EMap::LAND);
}

int N, M;
vector<vector<int>> Graph;
vector<vector<bool>> Visited;

bool OutOfBound(int x, int y)
{
    return x < 0 || x >= N || y < 0 || y >= M;
}

void DFS(const int NodeNumber, vector<FIsland>& Islands, int x, int y)
{
    Visited[x][y] = true;
    Graph[x][y] = NodeNumber;
    Islands.emplace_back(x, y, NodeNumber);
    
    for(const auto& [dx, dy] : Offset)
    {
        int nx = x + dx, ny = y + dy;
        if(!OutOfBound(nx, ny) && !Visited[nx][ny])
        {
            DFS(NodeNumber, Islands, nx, ny);
        }
    }
}

vector<FEdge> Edges;
void MakeEdges(const vector<FIsland>& Islands)
{
    for(const auto& [x, y, SrcNode] : Islands)
    {
        for(const auto& [dx, dy] : Offset)
        {
            int nx = x + dx, ny = y + dy, d = 0;
            
            while(true)
            {
                if(OutOfBound(nx, ny))
                {
                    break;
                }
                
                int DstNode = Graph[nx][ny];
                if(SrcNode == DstNode)
                {
                    break;
                }
                
                if(DstNode == SEA())  // Not SEA
                {
                    nx += dx;
                    ny += dy;
                    d += 1;
                    continue;
                }
                
                if(d < 2)
                {
                    break;
                }
                
                Edges.emplace_back(d, SrcNode, DstNode);
                break;
            }
        }
    }
}

vector<int> Parents;
int Find(int x)
{
    while(x != Parents[x])
    {
        Parents[x] = Parents[Parents[x]];
        x = Parents[x];
    }
    return Parents[x];
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    
    if(x == y)
    {
        return false;
    }
    
    if(x < y)
    {
        Parents[y] = x;
    }
    else
    {
        Parents[x] = y;
    }
    
    return true;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N >> M;
    Graph.assign(N, vector(M, 0));
    Visited.assign(N, vector(M, false));
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            cin >> Graph[i][j];
            if(Graph[i][j] == SEA())
            {
                Visited[i][j] = true;
            }
        }
    }

    int NodeNumber = 1;
    vector<FIsland> Islands;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(Visited[i][j])
            {
                continue;
            }
            
            DFS(NodeNumber, Islands, i, j);
            ++NodeNumber;
        }
    }
    
    MakeEdges(Islands);
    sort(Edges.begin(), Edges.end());
    
    Parents.assign(NodeNumber + 1, 0);
    iota(Parents.begin(), Parents.end(), 0);
    
    int Answer = 0, Count = 0;
    for(const auto& [Distance, SrcNode, DstNode] : Edges)
    {
        if(Union(SrcNode, DstNode))
        {
            Answer += Distance;
            Count += 1;
        }
    }
    
    if(Count == NodeNumber - 2)  // 1 ~ N
    {
        cout << Answer;
    }
    else
    {
        cout << -1;
    }
    
    return 0;
}