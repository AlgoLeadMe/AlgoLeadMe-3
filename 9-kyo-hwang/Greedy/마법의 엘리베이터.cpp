#include <vector>
#include <string>

using namespace std;

int solution(int Storey) 
{
    int Answer = 0;
    
    while(Storey)
    {
        int Remainder = Storey % 10;
        int Quotient = Storey / 10;
        
        if(Remainder < 5)  // 예: 54
        {
            Answer += Remainder;  // 54 -> 50
        }
        else if(Remainder > 5)  // 예: 16
        {
            ++Quotient;
            Answer += 10 - Remainder;  // 16 -> 20
        }
        else
        {
            if(Quotient % 10 >= 5)  // 예: 55 -> 60 / 25 -> 20
            {
                ++Quotient;  
            }
            
            Answer += Remainder;
        }
        
        Storey = Quotient;
    }
    
    return Answer;
}