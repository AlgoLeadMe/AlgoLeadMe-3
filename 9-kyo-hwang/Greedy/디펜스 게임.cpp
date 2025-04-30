#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, int K, vector<int> InEnemies) 
{
    priority_queue<int> NumofEnemiesBlocked;
    int Round = 0;
    
    for(int Enemy : InEnemies)
    {
        N -= Enemy;
        NumofEnemiesBlocked.emplace(Enemy);
        
        if(N < 0)
        {
            if(K == 0)
            {
                break;
            }
            
            N += NumofEnemiesBlocked.top();
            NumofEnemiesBlocked.pop();
            K--;
        }
        
        Round++;
    }
    
    return Round;
}
