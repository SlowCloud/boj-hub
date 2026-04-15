
#pragma GCC Optimize("O2")

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(auto i=a;i<b;i++)
#define endl '\n'

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int a,b,c;
  cin>>a>>b>>c;

  cout << min({a,b/2,c}) << endl;

  return 0;
}