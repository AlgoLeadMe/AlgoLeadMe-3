#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N, K; cin >> N >> K;
    
    vector<int> Sensors(N);
    for(int& Sensor : Sensors)
    {
        cin >> Sensor;
    }
    
    sort(Sensors.begin(), Sensors.end());
    
    vector<int> DistBtwnSensors;  // N - 1개
    for(int i = 0; i < N - 1; ++i)
    {
        DistBtwnSensors.emplace_back(Sensors[i + 1] - Sensors[i]);
    }
    
    sort(DistBtwnSensors.begin(), DistBtwnSensors.end());
    
    int Answer = 0;
    for(int i = 0; i < N - K; ++i)
    {
        Answer += DistBtwnSensors[i];
    }
    cout << Answer;
    
    return 0;
}