#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, R, Q; cin >> N >> R >> Q;
    vector<vector<int>> Tree(N + 1);
    for(int i = 0; i < N - 1; ++i)
    {
        int U, V; cin >> U >> V;
        Tree[U].emplace_back(V);
        Tree[V].emplace_back(U);
    }
    
    vector<int> Size(N + 1, 1);
    vector<bool> Visited(N + 1, false);
    
    function<int(int)> DFS = [&](int Parent)
    {
        if(Visited[Parent])
        {
            return Size[Parent];
        }
        
        Visited[Parent] = true;
        for(const int Child : Tree[Parent])
        {
            if(!Visited[Child])
            {
                Size[Parent] += DFS(Child);
            }
        }
        
        return Size[Parent];
    }; DFS(R);

    while(Q--)
    {
        int U; cin >> U;
        cout << Size[U] << "\n";
    }

    return 0;
}