#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int vst[555][555][2];
// A와 B의 위치가 같게 되더라도, Da와 Db가 다르므로 다음 이동에서 A==B가 될 수 있음.
// 그러니 3차원 배열로 처리해줘야 함.

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, A, B; cin >> N >> A >> B;

	int Da, Db; cin >> Da >> Db;

	queue<tuple<int,int,int>> q; q.push({ A-1,B-1,1 });
	vst[A - 1][B - 1][1] = 1;


	// A==B면 바로 끝내도 되나?

	while (q.size()) {
		const auto [a, b, w] = q.front(); q.pop();
		if (a == b) {
			cout << vst[a][b][w] - 1; exit(0);
		}
		vector<pii> v;
		if (w) {
			const int la = (a - Da + N) % N;
			const int ra = (a + Da) % N;
			v.push_back({ la,b });
			v.push_back({ ra,b });
		}
		else {
			const int lb = (b - Db + N) % N;
			const int rb = (b + Db) % N;
			v.push_back({ a,lb });
			v.push_back({ a,rb });
		}
		for (const auto [na, nb] : v) {
			if (vst[na][nb][w ^ 1]) continue;
			vst[na][nb][w ^ 1] = vst[a][b][w] + 1;
			q.push({ na,nb,w ^ 1 });
		}
	}

	cout << "Evil Galazy";

}
