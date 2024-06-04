#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int T, W; cin >> T >> W;
    vector<int> Poses(T + 1, 0);
    for(int t = 1; t <= T; ++t)
    {
        cin >> Poses[t];
        Poses[t] -= 1;
    }
    
    vector<vector<vector<int>>> DP(T + 1, vector(W + 1, vector(2, 0)));
    
    for(int Walk = 0; Walk <= W; ++Walk)
    {
        for(int Time = 1; Time <= T; ++Time)
        {
            if(Time == 1)
            {
                DP[Time][Walk][0] = DP[Time - 1][Walk][0] + (Poses[Time] == 0);
                if(Walk > 0)
                {
                    DP[Time][Walk][1] = DP[Time - 1][Walk - 1][0] + (Poses[Time] == 1);
                }
                continue;
            }
            
            if(Walk == 0)
            {
                DP[Time][Walk][0] = DP[Time - 1][Walk][0] + (Poses[Time] == 0);
                DP[Time][Walk][1] = DP[Time - 1][Walk][1] + (Poses[Time] == 1);
                continue;
            }
            
            DP[Time][Walk][0] = max(DP[Time - 1][Walk][0], DP[Time - 1][Walk - 1][1]) + (Poses[Time] == 0);
            DP[Time][Walk][1] = max(DP[Time - 1][Walk - 1][0], DP[Time - 1][Walk][1]) + (Poses[Time] == 1);
        }
    }
    
    int Ans = 0;
    for(int Walk = 0; Walk <= W; ++Walk)
    {
        Ans = max({Ans, DP[T][Walk][0], DP[T][Walk][1]});
    }
    cout << Ans;
    
    return 0;
}