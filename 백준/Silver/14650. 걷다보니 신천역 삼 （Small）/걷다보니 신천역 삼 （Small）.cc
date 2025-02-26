#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int dfs(int now, int top, int sum) {
	if (now == top) return sum % 3 == 0;
	int res = 0;
	FOR(i, 0, 3) res += dfs(now + 1, top, sum + i);
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// 3의 배수는, 각 자리의 숫자의 합이 3의 배수가 되면 3의 배수이삼.
	// 그러니 가능한 모든 조합을 구하면 알 수 있삼.
	// 브루트포스를 하면 최대 3^9=약 2만개로, 충분히 구할 수 있삼.

	int N; cin >> N;

	cout << dfs(1, N, 1) + dfs(1, N, 2);

}
