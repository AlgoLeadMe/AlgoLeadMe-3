#include <string>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

class Table {
public:
    Table() {
        parents.resize(R * C);
        iota(parents.begin(), parents.end(), 0);
        
        data.assign(R * C, "EMPTY");
    }
    ~Table() = default;
    
    void update(int r, int c, const string& value) {
        data[find(convert(r, c))] = value;
    }
    
    void update(const string& value1, const string& value2) {
        for(string &content : data) {
            if(content == value1) {
                content = value2;
            }
        }
    }
    
    void merge(int r1, int c1, int r2, int c2) {
        unite(convert(r1, c1), convert(r2, c2));
    }
    
    void unmerge(int r, int c) {
        int parent = find(convert(r, c));
        string content = data[parent];
        
        for(int i = 0; i < R * C; ++i) {
            if(parents[i] == parent) {
                parents[i] = i;
                data[i] = "EMPTY";
            }
        }
        
        data[convert(r, c)] = content;
    }
    
    string print(int r, int c) {
        return data[find(convert(r, c))];
    }
    
private:
    static const int R = 51, C = 51;
    vector<string> data;
    vector<int> parents;

    inline int convert(int r, int c) {
        return r * C + c;
    }
    
    inline int find(int x) {
        while(x != parents[x]) {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }
        return parents[x];
    }
    
    inline void unite(int x, int y) {
        x = find(x);
        y = find(y);
        
        if(x == y) {
            return;
        }
        
        if(data[x] == "EMPTY") {
            for(int& parent : parents) {
                if(parent == x) {
                    parent = y;
                }
            }
        } else {
            for(int& parent : parents) {
                if(parent == y) {
                    parent = x;
                }
            }
        }
    }
};

vector<string> parser(const string& command) {
    istringstream ss(command);
    string buffer;
    vector<string> v;
    
    while(ss >> buffer) {
        v.emplace_back(buffer);
    }
    
    return v;
}

vector<string> solution(vector<string> commands) {
    Table table;
    vector<string> answer;
    
    for(const string& command : commands) {
        vector<string> v = parser(command);
        
        if(v[0] == "UPDATE") {
            if(v.size() == 4) {
                table.update(stoi(v[1]), stoi(v[2]), v[3]);
            } else if(v.size() == 3) {
                table.update(v[1], v[2]);
            }
        } else if(v[0] == "MERGE") {
            table.merge(stoi(v[1]), stoi(v[2]), stoi(v[3]), stoi(v[4]));
        } else if(v[0] == "UNMERGE") {
            table.unmerge(stoi(v[1]), stoi(v[2]));
        } else if(v[0] == "PRINT") {
            answer.emplace_back(table.print(stoi(v[1]), stoi(v[2])));
        }
    }
    
    return answer;
}