#include <iostream>
#include <string>
#include <map>

using namespace std;

struct FNode
{
    map<string, FNode*> Node;
};

FNode* Root;

void Print(FNode* InNode = Root, const string& Prefix="")
{
    if(InNode == nullptr)
    {
        return;
    }
    
    for(const auto& [Data, Next] : InNode->Node)
    {
        cout << Prefix << Data << "\n";
        Print(Next, Prefix + "--");
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    Root = new FNode();
    
    int N; cin >> N;
    for(int n = 0; n < N; ++n)
    {
        FNode* Ptr = Root;
        
        int K; cin >> K;
        for(int k = 0; k < K; ++k)
        {
            string Info; cin >> Info;
            if(Ptr->Node.count(Info) == 0)
            {
                Ptr->Node[Info] = new FNode();
            }
            
            Ptr = Ptr->Node[Info];
        }
    }
    
    Print();
    
    return 0;
}