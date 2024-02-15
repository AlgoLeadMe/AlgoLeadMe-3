#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void CountEachComboSums(const vector<vector<int>>& Dices, const vector<int>& SelectedDices, unordered_map<int, int>& DiceComboMap, int ComboSum = 0, int DiceIndex = 0)
{
    if(DiceIndex == SelectedDices.size())
    {
        DiceComboMap[ComboSum] += 1;
        return;
    }
    
    for(const int& DicePip : Dices[SelectedDices[DiceIndex]])
    {
        CountEachComboSums(Dices, SelectedDices, DiceComboMap, ComboSum + DicePip, DiceIndex + 1);
    }
}

vector<int> solution(vector<vector<int>> Dice) 
{
    const int NumDice = Dice.size();
    vector<bool> IsADice(NumDice / 2, false);
    IsADice.insert(IsADice.end(), NumDice / 2, true);
    
    int MaxCntOfAWins = 0;
    vector<int> Answer;
    do 
    {
        vector<int> A, B;
        for(int i = 0; i < NumDice; ++i)
        {
            IsADice[i] ? A.emplace_back(i) : B.emplace_back(i);
        }
        
        unordered_map<int, int> AComboMap, BComboMap;
        CountEachComboSums(Dice, A, AComboMap);
        CountEachComboSums(Dice, B, BComboMap);
        
        vector<pair<int, int>> AComboVector(AComboMap.begin(), AComboMap.end());
        vector<pair<int, int>> BComboVector(BComboMap.begin(), BComboMap.end());
        
        sort(AComboVector.begin(), AComboVector.end());
        sort(BComboVector.begin(), BComboVector.end());
        
        int CntOfAWins = 0;
        for(const auto& [AComboSum, AComboCnt] : AComboVector)
        {
            for(const auto& [BComboSum, BComboCnt] : BComboVector)
            {
                if(BComboSum >= AComboSum)
                {
                    break;
                }
                
                CntOfAWins += AComboCnt * BComboCnt;
            }
        }
        
        if(CntOfAWins > MaxCntOfAWins)
        {
            MaxCntOfAWins = CntOfAWins;
            Answer = A;
        }
    } while(next_permutation(IsADice.begin(), IsADice.end()));
    
    transform(Answer.begin(), Answer.end(), Answer.begin(), [](int& i) { return i + 1; });
    return Answer;
}