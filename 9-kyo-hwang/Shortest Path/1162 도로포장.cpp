#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

constexpr int64_t INF = 50000000000;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, M, K; cin >> N >> M >> K;
    vector<vector<pair<int, int>>> Graph(N + 1);
    
    while(M--)
    {
        int A, B, C; cin >> A >> B >> C;
        Graph[A].emplace_back(B, C);
        Graph[B].emplace_back(A, C);
    }
    
    priority_queue<tuple<int64_t, int, int>, vector<tuple<int64_t, int, int>>, greater<>> Heap;
    vector<vector<int64_t>> Distances(N + 1, vector(K + 1, INF));
    
    Heap.emplace(0, 0, 1);
    Distances[1][0] = 0;

    while(!Heap.empty())
    {
        const auto [du, cnt, u] = Heap.top();
        Heap.pop();
        
        if(Distances[u][cnt] < du)
        {
            continue;
        }
        
        for(const auto& [v, dv] : Graph[u])
        {
            if(du + dv < Distances[v][cnt])  // non-pavement
            {
                Distances[v][cnt] = du + dv;
                Heap.emplace(Distances[v][cnt], cnt, v);
            }
            
            if(cnt < K && du < Distances[v][cnt + 1])  // pavement
            {
                Distances[v][cnt + 1] = du;
                Heap.emplace(Distances[v][cnt + 1], cnt + 1, v);
            }
        }
    }
    
    cout << *min_element(Distances[N].begin(), Distances[N].end());
    
    return 0;
}