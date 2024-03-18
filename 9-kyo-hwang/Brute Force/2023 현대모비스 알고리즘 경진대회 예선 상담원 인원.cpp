#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;

vector<vector<int>> MentoAssignmentCombos;
vector<int> MentoNums;
vector<vector<pair<int, int>>> ConsultationInfo;

void GetMentoAssignmentCombos(vector<int> MentoCombo, int RemainCategory, int RemainMentoNum)
{
    if(RemainCategory == 0)
    {
        if(RemainMentoNum == 0)
        {
            MentoAssignmentCombos.emplace_back(MentoCombo);
        }
        return;
    }
    
    for(const int NumMento : MentoNums)
    {
        MentoCombo.emplace_back(NumMento);
        GetMentoAssignmentCombos(MentoCombo, RemainCategory - 1, RemainMentoNum - NumMento);
        MentoCombo.pop_back();
    }
}

int GetConsultationWaiting(const int Category, const int NumMento)
{
    priority_queue<int, vector<int>, greater<>> PQ;
    for(int i = 0; i < NumMento; ++i)
    {
        PQ.emplace(0);
    }
    
    int WaitingTime = 0;
    for(const auto& [Tick, Consultation] : ConsultationInfo[Category])
    {
        const int FastestMentoTick = PQ.top();
        PQ.pop();
        
        if(FastestMentoTick > Tick)
        {
            WaitingTime += FastestMentoTick - Tick;
            PQ.emplace(FastestMentoTick + Consultation);
        }
        else if(FastestMentoTick < Tick)
        {
            PQ.emplace(Tick + Consultation);
        }
        else
        {
            PQ.emplace(FastestMentoTick + Consultation);
        }
    }
    
    return WaitingTime;
}

int solution(int k, int n, vector<vector<int>> Reqs) 
{
    MentoNums.assign(n, 0);
    iota(MentoNums.begin(), MentoNums.end(), 1);
    GetMentoAssignmentCombos({}, k, n);
    
    ConsultationInfo.assign(k, {});
    for(const auto& Req : Reqs)
    {
        ConsultationInfo[Req[2] - 1].emplace_back(Req[0], Req[1]);
    }
    
    int Answer = 1e9;
    for(const auto& MentoAssignmentCombo : MentoAssignmentCombos)
    {
        int WaitingCurCombo = 0;
        for(int i = 0; i < k; ++i)
        {
            WaitingCurCombo += GetConsultationWaiting(i, MentoAssignmentCombo[i]);
        }
        Answer = min(Answer, WaitingCurCombo);
    }
    return Answer;
}