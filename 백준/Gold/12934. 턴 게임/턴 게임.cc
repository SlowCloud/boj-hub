
#pragma GCC Optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(auto i=a;i<b;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using ll = long long;


int main() {
  std::cin.tie(0)->sync_with_stdio(0);

  ll a, b; cin>>a>>b;

  ll c = a+b;
  c <<= 1;

  int target = -1;
  FOR(i,1ll,2'222'222) {
	auto now = i*(i+1);
	if(now > c) {
		break;
	}
	if(now == c) {
		target = i;
		break;
	}
  }
  if(target == -1) {
	  cout << -1 << endl;
	  exit(0);
  }

  ll cnt = 0;
  for(ll i=target;i>0;i--) {
	  if(i<=a) {
		  a -= i;
		  cnt++;
		  if(a == 0) break;
	  }
  }
  cout << cnt << endl;

}
