#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N; cin >> N;
    multiset<pair<int, int>> DB;
    unordered_map<int, int> LevelMap;
    
    for(int i = 0; i < N; ++i)
    {
        int P, L; cin >> P >> L;
        DB.emplace(L, P);
        LevelMap.emplace(P, L);
    }
    
    int M; cin >> M;
    while(M--)
    {
        string Command; cin >> Command;
        if(Command == "recommend")
        {
            int x; cin >> x;
            if(x == 1)
            {
                const auto& [L, P] = *(--DB.end());
                cout << P << "\n";
            }
            else if(x == -1)
            {
                const auto& [L, P] = *DB.begin();
                cout << P << "\n";
            }
        }
        else if(Command == "add")
        {
            int P, L; cin >> P >> L;
            DB.emplace(L, P);
            LevelMap.emplace(P, L);
        }
        else if(Command == "solved")
        {
            int P; cin >> P;
            int L = LevelMap[P];
            
            DB.erase(DB.find({L, P}));
            LevelMap.erase(P);
        }
    }
    
    return 0;
}