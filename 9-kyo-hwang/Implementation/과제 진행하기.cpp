#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct FPlan
{
    string Name;
    int Start;
    int Playtime;
    
    FPlan() {}
    FPlan(const string& InName, const string& InStart, const string& InPlaytime)
    {
        Name = InName;
        Start = stoi(InStart.substr(0, 2)) * 60 + stoi(InStart.substr(3, 2));
        Playtime = stoi(InPlaytime);
    }
    
    const bool operator<(const FPlan& Rhs) const
    {
        return Start < Rhs.Start;
    }
};

vector<string> solution(vector<vector<string>> InPlans) 
{
    vector<FPlan> Plans;
    for(const vector<string>& Plan : InPlans)
    {
        Plans.push_back({Plan[0], Plan[1], Plan[2]});
    }
    
    sort(Plans.begin(), Plans.end());
    
    vector<string> Result;
    vector<int> Paused;
    
    for(int i = 0; i < Plans.size() - 1; ++i)
    {
        int TimeDifference = Plans[i + 1].Start - Plans[i].Start;
        if(Plans[i].Playtime > TimeDifference)
        {
            Plans[i].Playtime -= TimeDifference;
            Paused.emplace_back(i);
            continue;
        }
        
        TimeDifference -= Plans[i].Playtime;
        Plans[i].Playtime = 0;
        Result.emplace_back(Plans[i].Name);
        
        while(TimeDifference > 0 && !Paused.empty())
        {
            int Index = Paused.back();
            if(Plans[Index].Playtime > TimeDifference)
            {
                Plans[Index].Playtime -= TimeDifference;
                break;
            }
            
            TimeDifference -= Plans[Index].Playtime;
            Plans[Index].Playtime = 0;
            Result.emplace_back(Plans[Index].Name);
            Paused.pop_back();
        }
    }
    
    Result.emplace_back(Plans.back().Name);
    
    while(!Paused.empty())
    {
        Result.emplace_back(Plans[Paused.back()].Name);
        Paused.pop_back();
    }
    
    return Result;
}