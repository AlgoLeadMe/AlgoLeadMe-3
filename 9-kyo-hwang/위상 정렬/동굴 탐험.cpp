#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> getDirectedGraph(const int n, const vector<vector<int>> &undirectedGraph) {
    vector<vector<int>> directedGraph(n);
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.emplace(0);
    visited[0] = true;
    while(!q.empty()) {
        int from = q.front();
        q.pop();
        
        for(const int to : undirectedGraph[from]) {
            if(visited[to]) continue;
            
            visited[to] = true;
            directedGraph[from].emplace_back(to);
            q.emplace(to);
        }
    }
    
    return directedGraph;
}

bool canExplore(const int n, vector<vector<int>> &directedGraph, vector<vector<int>> &order) {
    vector<int> indegree(n, 0);
    for(const auto &from : directedGraph) {
        for(const auto &to : from) {
            indegree[to]++;
        }
    }
    
    for(const auto &o : order) {
        int A = o[0], B = o[1];
        directedGraph[A].emplace_back(B);
        indegree[B]++;
    }
    
    queue<int> q;
    for(const int in : indegree) {
        if(in == 0)
            q.emplace(in);
    }
    
    for(int i = 0; i < n; i++) {
        if(q.empty())
            return false;
        
        int from = q.front();
        q.pop();
        
        for(const int to : directedGraph[from]) {
            indegree[to]--;
            if(indegree[to] == 0) {
                q.emplace(to);
            }
        }
    }
    
    return true;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    vector<vector<int>> undirectedGraph(n);
    for(const auto &p : path) {
        undirectedGraph[p[0]].emplace_back(p[1]);
        undirectedGraph[p[1]].emplace_back(p[0]);
    }
    
    auto directedGraph = getDirectedGraph(n, undirectedGraph);
    return canExplore(n, directedGraph, order);
}