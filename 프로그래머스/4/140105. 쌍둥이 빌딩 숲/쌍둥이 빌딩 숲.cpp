#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll asdf[3333][3333];
constexpr ll MOD = 1e9 + 7;

int solution(int n, int count) {
    
    asdf[1][1] = 1;
    
    for(ll i = 2; i <= n; i++) {
        for(ll j = 1; j <= count; j++) {
            asdf[i][j] = asdf[i-1][j] * (i - 1) % MOD * 2 % MOD + asdf[i-1][j-1];
            asdf[i][j] %= MOD;
        }
    }
    
    return asdf[n][count];
}
