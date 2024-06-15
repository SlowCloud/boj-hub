#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

#define all(v) v.begin(), v.end()
#define For(i,a,b) for(int i=a;i<b;i++)
#define nx(x,i) "11020022"[i] - '1' + x
#define ny(y,i) "02110202"[i] - '1' + y
#define outside(x,y,R,C) min(x,y) < 0 || R <= x || C <= y

vector<int> G[201];

int vst[222];
int p[222];

bool dfs(int now) {
	if (vst[now]) return false;
	vst[now] = 1;
	for (int next : G[now]) {
		if (p[next] == 0 || dfs(p[next])) {
			p[next] = now; return true;
		}
	}
	return false;
}

int N, M;

int check() {
	int res = 0;
	For(i, 1, N + 1) {
		memset(vst, 0, sizeof(vst));
		res += dfs(i);
	}
	return res;
}

int main() {

	cin >> N >> M;

	vector<int> v(N), w(M);
	for (int& i : v) cin >> i;
	for (int& i : w) cin >> i;

	For(i, 0, N) For(j, 0, M) {
		int& a = v[i], &b = w[j];
		if ((a / 2 + (a&1) <= b && b <= a * 3 / 4) || (a <= b && b <= a * 5 / 4)) {
			G[i + 1].push_back(j + 1);
		}
	}

	cout << check() << endl;

}