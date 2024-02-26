#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

string N; int K;
unordered_set<int> Visited[11];

int DFS(string Num = N, int Depth = 0)
{
    if(Visited[Depth].find(stoi(Num)) != Visited[Depth].end())
    {
        return -1;
    }
    else if(Depth == K)
    {
        return stoi(Num);
    }
    else
    {
        Visited[Depth].emplace(stoi(Num));
        int MaxNum = -1;
        for(int i = 0; i < N.size() - 1; ++i)
        {
            for(int j = i + 1; j < N.size(); ++j)
            {
                if(i == 0 && Num[j] == '0')
                {
                    continue;
                }
                string TmpNum = Num;
                swap(TmpNum[i], TmpNum[j]);
                
                MaxNum = max(MaxNum, DFS(TmpNum, Depth + 1));
            }
        }
        return MaxNum;
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> K;
    cout << DFS();
    return 0;
}