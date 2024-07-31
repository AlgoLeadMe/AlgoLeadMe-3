#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool IsUnique(const vector<vector<string>>& Relation, const int RowSize, const int ColSize, int AttributeSet)
{
    vector<int> Columns;
    for(int Column = 0; Column < ColSize; ++Column)
    {
        if((AttributeSet >> Column) & 1)
        {
            Columns.emplace_back(Column);
        }
    }
    
    unordered_set<string> Set;
    for(int Row = 0; Row < RowSize; ++Row)
    {
        string Attributes{};
        for(int Column : Columns)
        {
            Attributes += Relation[Row][Column];
        }
        Set.emplace(Attributes);
    }
    
    return Set.size() == RowSize;
}

bool IsMinimal(const vector<int>& CandidateKeys, int AttributeSet)
{
    for(int CandidateKey : CandidateKeys)
    {
        if((AttributeSet & CandidateKey) == CandidateKey)
        {
            return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> Relation)
{
    const size_t RowSize = Relation.size(), ColSize = Relation.front().size();
    vector<int> CandidateKeys;
    
    for(int AttributeSet = 1; AttributeSet < (1 << ColSize); ++AttributeSet)
    {
        if(!IsMinimal(CandidateKeys, AttributeSet)) continue;
        if(!IsUnique(Relation, RowSize, ColSize, AttributeSet)) continue;
        
        CandidateKeys.emplace_back(AttributeSet);
    }
    
    return CandidateKeys.size();
}