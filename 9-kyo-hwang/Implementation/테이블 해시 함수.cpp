#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> Data, int Col, int RowBegin, int RowEnd) 
{
    sort(Data.begin(), Data.end(), [&](const auto& Lhs, const auto& Rhs)
         {
             return Lhs[Col - 1] == Rhs[Col - 1] ? Lhs[0] > Rhs[0] : Lhs[Col - 1] < Rhs[Col - 1];
         });
    
    int HashVal = 0;
    for(int i = RowBegin; i <= RowEnd; ++i)
    {
        int S_i = 0;
        for(const int Val : Data[i - 1])
        {
            S_i += Val % i;
        }
        HashVal ^= S_i;
    }
    
    return HashVal;
}