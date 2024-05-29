#include <iostream>
#include <vector>

using namespace std;

const vector<pair<int, int>> Offset{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int N, M;
vector<vector<int>> Room;
int r, c, d;

bool OutOfBound(int InR, int InC)
{
    return InR < 0 || InR >= N || InC < 0 || InC >= M;
}

bool IsThereABlankSpace()
{
    for(const auto& [dr, dc] : Offset)
    {
        int nr = r + dr, nc = c + dc;
        if(!OutOfBound(nr, nc) && Room[nr][nc] == 0)
        {
            return true;
        }
    }
    return false;
}

int Simulation()
{
    int Cnt = 0;
    while(true)
    {
        if(Room[r][c] == 0)  // Logic 1
        {
            Room[r][c] = 2;
            Cnt++;
        }
        
        if(!IsThereABlankSpace())  // Logic 2
        {
            const auto& [dr, dc] = Offset[(d + 2) % 4];
            int nr = r + dr, nc = c + dc;
            
            if(!OutOfBound(nr, nc) && Room[nr][nc] != 1)
            {
                r = nr, c = nc;
            }
            else
            {
                break;
            }
        }
        else  // Logic 3
        {
            d -= 1;
            if(d < 0)
            {
                d = 3;
            }
            
            const auto& [dr, dc] = Offset[d];
            int nr = r + dr, nc = c + dc;
            
            if(!OutOfBound(nr, nc) && Room[nr][nc] == 0)
            {
                r = nr, c = nc;
            }
        }
    }
    
    return Cnt;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N >> M;
    Room.assign(N, vector<int>(M, 0));
    cin >> r >> c >> d;
    for(auto& Row : Room)
    {
        for(auto& Col : Row)
        {
            cin >> Col;
        }
    }
    
    cout << Simulation();
    
    return 0;
}