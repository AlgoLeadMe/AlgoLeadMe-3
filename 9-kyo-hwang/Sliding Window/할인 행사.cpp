#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> InWants, vector<int> InNumbers, vector<string> InDiscounts) 
{
    unordered_map<string, int> NumberbyWants;
    for(int i = 0; i < 9; ++i)
    {
        NumberbyWants[InDiscounts[i]]++;
    }
    
    int Answer = 0;
    for(int i = 9; i < InDiscounts.size(); ++i)
    {
        NumberbyWants[InDiscounts[i]]++;
        bool Flag = true;
        
        for(int j = 0; j < InWants.size(); ++j)
        {
            if(NumberbyWants[InWants[j]] != InNumbers[j])
            {
                Flag = false;
                break;
            }
        }
        
        Answer += Flag;
        NumberbyWants[InDiscounts[i - 9]]--;
    }
    
    return Answer;
}