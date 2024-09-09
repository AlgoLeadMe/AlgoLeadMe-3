#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    unordered_set<string> Storage;
    unordered_map<string, int> NicknameMap;
    
    int N; cin >> N;
    while(N--)
    {
        string Nickname; cin >> Nickname;
        NicknameMap[Nickname]++;
        
        bool bEmplaced = false;
        string Prefix{};
        for(const char& ch : Nickname)
        {
            Prefix += ch;
            if(Storage.count(Prefix) == 0 && !bEmplaced)
            {
                cout << Prefix << "\n";
                bEmplaced = true;
            }
            Storage.emplace(Prefix);
        }
        
        if(!bEmplaced)
        {
            string Prefix = Nickname;
            if(NicknameMap[Nickname] > 1)
            {
                Prefix += to_string(NicknameMap[Nickname]);
            }
            Storage.emplace(Prefix);
            cout << Prefix << "\n";
        }
    }

    return 0;
}