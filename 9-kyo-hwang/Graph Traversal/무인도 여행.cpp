#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Merge(vector<string>& Maps, int x, int y)
{
    if(x < 0 || x >= Maps.size() || y < 0 || y >= Maps[0].size() || Maps[x][y] == 'X') 
    {
        return 0;
    }
    
    int Day = Maps[x][y] - '0';
    Maps[x][y] = 'X';
    
    return Day 
        + Merge(Maps, x - 1, y) 
        + Merge(Maps, x, y + 1) 
        + Merge(Maps, x + 1, y) 
        + Merge(Maps, x, y - 1);
}

vector<int> solution(vector<string> Maps) 
{
    vector<int> DaysofStay;
    for(int i = 0; i < Maps.size(); ++i)
    {
        for(int j = 0; j < Maps[0].size(); ++j)
        {
            if(Maps[i][j] != 'X')
            {
                DaysofStay.emplace_back(Merge(Maps, i, j));
            }
        }
    }
    
    if(DaysofStay.empty()) 
    {
        return {-1};
    }
    
    sort(DaysofStay.begin(), DaysofStay.end());
    return DaysofStay;
}