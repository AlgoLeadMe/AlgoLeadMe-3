#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
    int N, C, M; cin >> N >> C >> M;
    vector<tuple<int, int, int>> Boxes(M);
    for(auto& [Dst, Src, Box] : Boxes)
    {
        cin >> Src >> Dst >> Box;
    }
    sort(Boxes.begin(), Boxes.end());
    
    vector<int> RemainSpaces(N + 1, C);
    
    int Answer = 0;
    for(const auto& [Dst, Src, Box] : Boxes)
    {
        int MinRemainSpace = C;
        for(int i = Src; i < Dst; ++i)
        {
            MinRemainSpace = min(MinRemainSpace, RemainSpaces[i]);
        }
        int LoadableBox = min(Box, MinRemainSpace);
        
        Answer += LoadableBox;
        for(int i = Src; i < Dst; ++i)
        {
            RemainSpaces[i] -= LoadableBox;
        }
    }
    cout << Answer;
    return 0;
}