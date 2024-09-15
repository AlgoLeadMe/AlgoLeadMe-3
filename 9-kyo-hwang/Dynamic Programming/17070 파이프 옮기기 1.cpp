#include <iostream>
#include <vector>

using namespace std;

enum EDirection {Horizontal, Vertical, Diagonal};
enum EHouse {Empty, Wall};

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N; cin >> N;
    vector<vector<int>> House(N + 1, vector(N + 1, 0));
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= N; ++j)
        {
            cin >> House[i][j];
        }
    }
    
    vector<vector<vector<int>>> DP(N + 1, vector(N + 1, vector(3, 0)));
    DP[1][2][EDirection::Horizontal] = 1;
    
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 3; j <= N; ++j)
        {
            if(House[i][j] == EHouse::Wall) continue;
            
            DP[i][j][EDirection::Horizontal] 
            = DP[i][j - 1][EDirection::Horizontal] 
            + DP[i][j - 1][EDirection::Diagonal];
            
            DP[i][j][EDirection::Vertical]
            = DP[i - 1][j][EDirection::Vertical] 
            + DP[i - 1][j][EDirection::Diagonal];
            
            if(House[i - 1][j] == EHouse::Wall || House[i][j - 1] == EHouse::Wall) continue;
            
            DP[i][j][EDirection::Diagonal]
            = DP[i - 1][j - 1][Horizontal]
            + DP[i - 1][j - 1][Vertical]
            + DP[i - 1][j - 1][Diagonal];
        }
    }
    
    cout << DP[N][N][EDirection::Horizontal] + DP[N][N][EDirection::Vertical] + DP[N][N][EDirection::Diagonal];

    return 0;
}