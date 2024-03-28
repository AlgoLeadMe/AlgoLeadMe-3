#include <iostream>

using namespace std;

int Pow(int Base, int Exp, int Mod)
{
    if(Exp == 1)
    {
        return Base;
    }
    
    int64_t NxtBase = Pow(Base, Exp / 2, Mod);
    if(Exp % 2 == 0)
    {
        return (NxtBase * NxtBase) % Mod;
    }
    else
    {
        return (NxtBase * NxtBase * Base) % Mod;
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    constexpr int MOD = 1e9 + 7;
    
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        cout << (N <= 2 ? 1 : Pow(2, N - 2, MOD)) << "\n";
    }
    
    return 0;
}