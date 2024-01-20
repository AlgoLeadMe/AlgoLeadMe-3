#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

enum class EColor {
    WHITE,
    GRAY,
    BLACK
};

unordered_map<int, vector<int>> graph;
unordered_map<int, int> indegrees, outdegrees;

int dfs(unordered_map<int, int> &color, int v) {
    color[v] = static_cast<int>(EColor::GRAY);
    
    if(graph[v].size() == 2) {
        return 3;
    }
    
    for(const auto &w : graph[v]) {
        if(color[w] == static_cast<int>(EColor::GRAY)) {
            return 1;
        } else if(color[w] == static_cast<int>(EColor::WHITE)) {
            return dfs(color, w);
        }
    }
    
    color[v] = static_cast<int>(EColor::BLACK);
    return 2;
}

int determine_graph_shape(int start_node) {
    unordered_map<int, int> color;
    return dfs(color, start_node);
}

vector<int> solution(vector<vector<int>> edges) {
    for(const auto &edge : edges) {
        int a = edge[0], b = edge[1];
        graph[a].emplace_back(b);
        
        if(indegrees.find(a) == indegrees.end()) {
            indegrees.emplace(a, 0);
        }
        indegrees[b] += 1;
        
        if(outdegrees.find(b) == outdegrees.end()) {
            outdegrees.emplace(b, 0);
        }
        outdegrees[a] += 1;
    }
    
    vector<int> answer = {0, 0, 0, 0};
    for(const auto &[node, indegree] : indegrees) {
        if(indegree == 0 && outdegrees[node] >= 2) {
            answer[0] = node;
            break;
        }
    }
    
    for(const auto &subgraph_begin_node : graph[answer[0]]) {
        answer[determine_graph_shape(subgraph_begin_node)] += 1;
    }
    
    return answer;
}