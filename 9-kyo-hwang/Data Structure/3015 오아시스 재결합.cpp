#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N; cin >> N;
    vector<pair<int, int64_t>> Stack;
    
    int64_t NumPair = 0;
    while(N--)
    {
        int Height; cin >> Height;
        int64_t NumSame = 1;
        
        while(!Stack.empty() && Stack.back().first <= Height)
        {
            NumPair += Stack.back().second;
            if(Stack.back().first == Height)
            {
                NumSame = Stack.back().second + 1;
            }
            Stack.pop_back();
        }
        
        if(!Stack.empty())
        {
            NumPair += 1;
        }
        Stack.emplace_back(Height, NumSame);
    }
    
    cout << NumPair;
    
    return 0;
}