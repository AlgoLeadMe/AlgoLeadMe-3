#include <iostream>
#include <vector>

using namespace std;

const vector<pair<int, int>> Offset{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

enum EHouse
{
    AirPurifier = -1,
    Empty = 0
};

int R, C, T;
vector<vector<int>> A;
vector<vector<int>> Modifier;
vector<int> AirPurifierPos;

inline bool OutOfBound(int r, int c)
{
    return r < 0 || r >= R || c < 0 || c >= C;
}

void Diffusion(int r, int c)
{
    int AmountofDiffusion = A[r][c] / 5;
    int NumofDirDiffusion = 0;
    
    for(const auto& [dr, dc] : Offset)
    {
        int nr = r + dr, nc = c + dc;
        if(!OutOfBound(nr, nc) && A[nr][nc] != EHouse::AirPurifier)
        {
            Modifier[nr][nc] += AmountofDiffusion;
            NumofDirDiffusion++;
        }
    }
    
    Modifier[r][c] -= AmountofDiffusion * NumofDirDiffusion;
}

void DiffusionParticulateMatter()
{
    for(int r = 0; r < R; ++r)
    {
        for(int c = 0; c < C; ++c)
        {
            if(A[r][c] != EHouse::AirPurifier && A[r][c] != EHouse::Empty)
            {
                Diffusion(r, c);
            }
        }
    }
    
    for(int r = 0; r < R; ++r)
    {
        for(int c = 0; c < C; ++c)
        {
            A[r][c] += Modifier[r][c];
            Modifier[r][c] = 0;
        }
    }
}

void WorkAirPurifier()
{
    {
        int r = AirPurifierPos[0];
        for(int i = r - 1; i > 0; --i) A[i][0] = A[i - 1][0];       // to N
        for(int j = 0; j < C - 1; ++j) A[0][j] = A[0][j + 1];       // to E
        for(int i = 0; i < r; ++i) A[i][C - 1] = A[i + 1][C - 1];   // to S
        for(int j = C - 1; j > 1; --j) A[r][j] = A[r][j - 1];       // to W
        A[r][1] = 0;
    }
    {
        int r = AirPurifierPos[1];
        for(int i = r + 1; i < R - 1; ++i) A[i][0] = A[i + 1][0];       // to S
        for(int j = 0; j < C - 1; ++j) A[R - 1][j] = A[R - 1][j + 1];   // to E
        for(int i = R - 1; i > r; --i) A[i][C - 1] = A[i - 1][C - 1];   // to N
        for(int j = C - 1; j > 1; --j) A[r][j] = A[r][j - 1];           // to W
        A[r][1] = 0;
    }
}


int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> R >> C >> T;
    A.assign(R, vector(C, 0));
    Modifier.assign(R, vector(C, 0));
    
    for(int r = 0; r < R; ++r)
    {
        for(int c = 0; c < C; ++c)
        {
            cin >> A[r][c];
            if(A[r][c] == EHouse::AirPurifier)
            {
                AirPurifierPos.emplace_back(r);
            }
        }
    }
    
    while(T--)
    {
        DiffusionParticulateMatter();
        WorkAirPurifier();
    }
    
    int Answer = 0;
    for(int r = 0; r < R; ++r)
    {
        for(int c = 0; c < C; ++c)
        {
            if(A[r][c] > 0)
            {
                Answer += A[r][c];
            }
        }
    }
    
    cout << Answer;

    return 0;
}