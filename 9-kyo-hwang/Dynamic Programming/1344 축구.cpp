#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    double ScoringRateA, ScoringRateB;
    cin >> ScoringRateA >> ScoringRateB;
    ScoringRateA /= 100.0; ScoringRateB /= 100.0;
    
    int TotalRound = 90 / 5;
    vector<bool> IsPrimeNumber(TotalRound + 1, true);
    IsPrimeNumber[0] = IsPrimeNumber[1] = false;
    for(int i = 2; i * i <= TotalRound; ++i)
    {
        if(IsPrimeNumber[i])
        {
            for(int j = i * i; j <= TotalRound; j += i)
            {
                IsPrimeNumber[j] = false;
            }
        }
    }
    
    vector<vector<vector<double>>> ScoringRateForEachRound(TotalRound + 1, vector(TotalRound + 1, vector(TotalRound + 1, 0.0)));
    ScoringRateForEachRound[1][0][0] = (1.0 - ScoringRateA) * (1.0 - ScoringRateB);
    ScoringRateForEachRound[1][1][0] = ScoringRateA * (1.0 - ScoringRateB);
    ScoringRateForEachRound[1][0][1] = (1.0 - ScoringRateA) * ScoringRateB;
    ScoringRateForEachRound[1][1][1] = ScoringRateA * ScoringRateB;
    
    for(int Round = 2; Round <= TotalRound; ++Round)
    {
        for(int ScoreA = 0; ScoreA <= TotalRound; ++ScoreA)
        {
            for(int ScoreB = 0; ScoreB <= TotalRound; ++ScoreB)
            {
                ScoringRateForEachRound[Round][ScoreA][ScoreB] 
                += ScoringRateForEachRound[Round - 1][ScoreA][ScoreB] 
                * (1.0 - ScoringRateA) * (1.0 - ScoringRateB);
                if(ScoreA > 0)
                {
                    ScoringRateForEachRound[Round][ScoreA][ScoreB] 
                    += ScoringRateForEachRound[Round - 1][ScoreA - 1][ScoreB] 
                    * ScoringRateA * (1.0 - ScoringRateB);
                }
                if(ScoreB > 0)
                {
                    ScoringRateForEachRound[Round][ScoreA][ScoreB] 
                    += ScoringRateForEachRound[Round - 1][ScoreA][ScoreB - 1] 
                    * (1.0 - ScoringRateA) * ScoringRateB;
                }
                if(ScoreA > 0 && ScoreB > 0)
                {
                    ScoringRateForEachRound[Round][ScoreA][ScoreB] 
                    += ScoringRateForEachRound[Round - 1][ScoreA - 1][ScoreB - 1] 
                    * ScoringRateA * ScoringRateB;
                }
            }
        }
    }
    
    double Answer = 0.0;
    for(int ScoreA = 0; ScoreA <= TotalRound; ++ScoreA)
    {
        for(int ScoreB = 0; ScoreB <= TotalRound; ++ScoreB)
        {
            if(IsPrimeNumber[ScoreA] || IsPrimeNumber[ScoreB])
            {
                Answer += ScoringRateForEachRound[TotalRound][ScoreA][ScoreB];
            }
        }
    }
    cout << Answer;
    
    return 0;
}