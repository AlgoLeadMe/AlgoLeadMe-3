#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Comparator
{
    bool operator()(const pair<int, int>& Lhs, const pair<int, int>& Rhs) const
    {
        const auto& [LhsCard, LhsCoin] = Lhs;
        const auto& [RhsCard, RhsCoin] = Rhs;
        
        return LhsCoin == RhsCoin ? LhsCard < RhsCard : LhsCoin < RhsCoin;
    }
};

int solution(int InCoin, vector<int> InCards) 
{
    const int N = (int)InCards.size();
    const int RequiredSum = N + 1;
    reverse(InCards.begin(), InCards.end());
    
    set<pair<int, int>, Comparator> Deck;
    for(int i = 0; i < N / 3; ++i)
    {
        Deck.emplace(InCards.back(), 0); InCards.pop_back();
    }
    
    int Round;
    for(Round = 1; !InCards.empty(); ++Round)
    {
        Deck.emplace(InCards.back(), 1); InCards.pop_back();
        Deck.emplace(InCards.back(), 1); InCards.pop_back();
        
        bool FindCombination = false;
        for(const auto& [Card, Coin] : Deck)
        {
            int TargetCard = RequiredSum - Card;
            if(Card == TargetCard)
            {
                continue;
            }
            
            int TargetCoin;
            if(Deck.count({TargetCard, 0}))
            {
                TargetCoin = 0;
            }
            else if(Deck.count({TargetCard, 1}))
            {
                TargetCoin = 1;
            }
            else
            {
                continue;
            }
            
            if(Coin + TargetCoin <= InCoin)
            {
                InCoin -= (Coin + TargetCoin);
                Deck.erase({Card, Coin});
                Deck.erase({TargetCard, TargetCoin});
                FindCombination = true;
                break;
            }
        }

        if(false == FindCombination)
        {
            break;
        }
    }
    
    return Round;
}