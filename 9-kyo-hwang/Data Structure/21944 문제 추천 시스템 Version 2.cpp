#include <iostream>
#include <set>

using namespace std;

class Database
{
public:
    int Recommend1(int G, int x)
    {
        if(x == 1)
        {
            return Recommend1P(G);
        }
        else if(x == -1)
        {
            return Recommend1N(G);
        }
    }
    
    int Recommend2(int x)
    {
        if(x == 1)
        {
            return Recommend2P();
        }
        else if(x == -1)
        {
            return Recommend2N();
        }
    }
    
    int Recommend3(int x, int L)
    {
        if(x == 1)
        {
            return Recommend3P(L);
        }
        else if(x == -1)
        {
            return Recommend3N(L);
        }
    }

    void Add(int P, int L, int G)
    {
        ProblemByLevel[L].emplace(P);
        ProblemByLevelAndGroup[L][G].emplace(P);
        Problems[P] = {L, G};
    }
    
    void Solved(int P)
    {
        ProblemByLevel[Problems[P].first].erase(P);
        ProblemByLevelAndGroup[Problems[P].first][Problems[P].second].erase(P);
    }
    
private:
    set<int> ProblemByLevel[101];
    set<int> ProblemByLevelAndGroup[101][101];
    pair<int, int> Problems[100001];
    
    int Recommend1P(int G)
    {
        for(int L = 100; L >= 1; --L)
        {
            if(!ProblemByLevelAndGroup[L][G].empty())
            {
                return *(--ProblemByLevelAndGroup[L][G].end());
            }
        }
    }
    
    int Recommend1N(int G)
    {
        for(int L = 1; L <= 100; ++L)
        {
            if(!ProblemByLevelAndGroup[L][G].empty())
            {
                return *ProblemByLevelAndGroup[L][G].begin();
            }
        }
    }
    
    int Recommend2P()
    {
        for(int L = 100; L >= 1; --L)
        {
            if(!ProblemByLevel[L].empty())
            {
                return *(--ProblemByLevel[L].end());
            }
        }
    }
    
    int Recommend2N()
    {
        for(int L = 1; L <= 100; ++L)
        {
            if(!ProblemByLevel[L].empty())
            {
                return *ProblemByLevel[L].begin();
            }
        }
    }
    
    int Recommend3P(int L)
    {
        for(; L <= 100; ++L)
        {
            if(!ProblemByLevel[L].empty())
            {
                return *ProblemByLevel[L].begin();
            }
        }
        return -1;
    }
    
    int Recommend3N(int L)
    {
        for(L -= 1; L >= 1; --L)
        {
            if(!ProblemByLevel[L].empty())
            {
                return *(--ProblemByLevel[L].end());
            }
        }
        return -1;
    }
};

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    Database* DB = new Database();
    
    int N; cin >> N;
    while(N--)
    {
        int P, L, G; cin >> P >> L >> G;
        DB->Add(P, L, G);
    }
    
    int M; cin >> M;
    while(M--)
    {
        string Command; cin >> Command;
        if(Command == "recommend")  // find Max/Min in Category G
        {
            int G, x; cin >> G >> x;
            cout << DB->Recommend1(G, x) << "\n";
        }
        else if(Command == "recommend2")  // find Max/Min any Category
        {
            int x; cin >> x;
            cout << DB->Recommend2(x) << "\n";
        }
        else if(Command == "recommend3")  // find lower bound
        {
            int x, L; cin >> x >> L;
            cout << DB->Recommend3(x, L) << "\n";
        }
        else if(Command == "add")
        {
            int P, L, G; cin >> P >> L >> G;
            DB->Add(P, L, G);
        }
        else if(Command == "solved")
        {
            int P; cin >> P;
            DB->Solved(P);
        }
    }
    
    delete DB;
    
    return 0;
}