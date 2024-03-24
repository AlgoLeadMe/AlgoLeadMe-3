#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    using FEdge = pair<int, int>;
    constexpr int INF = 2e9;
    
    int N, M; cin >> N >> M;
    vector<vector<FEdge>> Graph(N + 1);
    vector<vector<int>> InverseGraph(N + 1);
    
    while(M--)
    {
        int U, V, W;
        cin >> U >> V >> W;
        
        Graph[U].emplace_back(V, -W);
        InverseGraph[V].emplace_back(U);
    }
    
    vector<bool> Visited(N + 1, false);
    auto BFS = [&](int Start)
    {
        deque<int> Q;

        Q.emplace_back(Start);
        Visited[Start] = true;
        
        while(!Q.empty())
        {
            const int SrcNode = Q.front();
            Q.pop_front();
            
            if(SrcNode == 1)
            {
                return true;
            }
            
            for(const auto& DstNode : InverseGraph[SrcNode])
            {
                if(!Visited[DstNode])
                {
                    Visited[DstNode] = true;
                    Q.emplace_back(DstNode);
                }
            }
        }
        
        return false;
    };
    
    vector<int> Distances(N + 1, INF);
    vector<int> Parents(N + 1, 0);
    auto UpdateDistances = [&]()
    {
        for(int SrcNode = 1; SrcNode <= N; ++SrcNode)
        {
            for(const auto& [DstNode, Weight] : Graph[SrcNode])
            {
                if(Distances[SrcNode] == INF)
                {
                    continue;
                }
                
                if(Distances[SrcNode] + Weight < Distances[DstNode])
                {
                    Distances[DstNode] = Distances[SrcNode] + Weight;
                    Parents[DstNode] = SrcNode;
                }
            }
        }
    };
    
    auto BellmanFord = [&](int Start = 1)
    {
        Distances[Start] = 0;
        for(int Repeat = 1; Repeat <= N - 1; ++Repeat)
        {
            UpdateDistances();
        }
    };
    
    auto HasCycle = [&]()
    {
        for(int SrcNode = 1; SrcNode <= N; ++SrcNode)
        {
            for(const auto& [DstNode, Weight] : Graph[SrcNode])
            {
                if(Distances[SrcNode] == INF)
                {
                    continue;
                }
                
                if(Distances[SrcNode] + Weight < Distances[DstNode] && Visited[DstNode])
                {
                    return true;
                }
            }
        }
        
        return false;
    };
    
    function<void(int)> DFS = [&](int Node)
    {
        if(Node == 0)
        {
            return;
        }
        
        DFS(Parents[Node]);
        cout << Node << " ";
    };
    
    BFS(N);
    BellmanFord();
    if(HasCycle())
    {
        cout << -1;
    }
    else
    {
        DFS(N);
    }
    
    return 0;
}