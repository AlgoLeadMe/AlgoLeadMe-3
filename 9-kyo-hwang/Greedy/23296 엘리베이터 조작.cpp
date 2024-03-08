#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N; cin >> N;
    
    vector<int> A(N + 1, 0), NumToComeHere(N + 1, 0);
    vector<bool> IsOutOfHere(N + 1, false);
    
    for(int i = 1; i <= N; ++i)
    {
        cin >> A[i];
        NumToComeHere[A[i]] += 1;
    }
  
    vector<int> BtnsToPress;
    auto Move = [&](int Floor = 1)
    {
        while(!IsOutOfHere[Floor])
        {
            IsOutOfHere[Floor] = true;
            int NextFloor = A[Floor];

            if(NumToComeHere[NextFloor] > 0)
            {
                NumToComeHere[NextFloor] -= 1;
                BtnsToPress.emplace_back(NextFloor);
                Floor = NextFloor;
            }
        }
    };

    Move();
    
    for(int Floor = 1; Floor <= N; ++Floor)
    {
        if(IsOutOfHere[Floor])
        {
            continue;
        }

        if(NumToComeHere[Floor] == 0)
        {
            BtnsToPress.emplace_back(Floor);
            Move(Floor);
        }
    }

    for(int Floor = 1; Floor <= N; ++Floor)
    {
        if(IsOutOfHere[Floor])
        {
            continue;
        }

        BtnsToPress.emplace_back(Floor);
        Move(Floor);
    }

    cout << BtnsToPress.size() << "\n";
    for(const int& Btn : BtnsToPress)
    {
        cout << Btn << " ";
    }

    return 0;
}