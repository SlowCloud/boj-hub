#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define endl '\n'
#define FOR_(type,i,a,b) for(type i=a;i<b;i++)
#define FOR(i,a,b) FOR_(int,i,a,b)
#define FORLL(i,a,b) FOR_(ll,i,a,b)

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using pii = pair<int, int>;
using pll = pair<ll, ll>;


int in_deg[111'111];

int main() {
  ios::sync_with_stdio(0);

  // 선이거나, 원형을 그리면 으악그래프.
  // in_deg가 모두 2이거나,
  // in_deg가 1인 경우가 2개 있고 나머지가 2인 경우가 으악그래프.
  // 일단 간선 개수로도 얼추 걸러낼 수 있을듯?
  // 일단 간선 개수가 N-1이어야 함. 트리랑 같네
  // 엥 간선 N+1 미만이면 으악그래프네

  int N, M; cin >>N>>M;
  if(M < N+1) {
      cout << "Yes";
  }
  else {
      cout << "No";
  }
  cout << endl;

}
