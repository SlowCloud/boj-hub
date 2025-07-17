#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int board[22][22];
int N, M, fuel;

int vst[22][22];
bool out(int x, int y) {
	return min(x, y) <= 0 || N < max(x, y);
}
int dist(pii s, pii e) {
	memset(vst, 0, sizeof vst);
	vst[s.first][s.second] = 1;
	queue<pii> q; q.push(s);

	int cnt = 0;
	while (q.size()) {
		for (int t = q.size(); t--;) {
			auto [x, y] = q.front(); q.pop();
			if (x == e.first && y == e.second)
				return cnt;
			FOR(i, 0, 4) {
				int nx = x + "1102"[i] - '1';
				int ny = y + "0211"[i] - '1';
				if (out(nx, ny)) continue;
				if (board[nx][ny]) continue; // wall
				if (vst[nx][ny]) continue;
				vst[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
		cnt++;
	}
	return 1e9;
}

struct Customer {
	pii s, e;
	bool vst = false;
};

vector<Customer> customers;

int get_closest_customer(const pii now) {
	int d = 1e9;
	int idx = -1;
	FOR(i, 0, customers.size()) {
		const auto& c = customers[i];
		if (c.vst) continue;
		if (d > dist(now, c.s)) {
			d = dist(now, c.s);
			idx = i;
		}
		else if (d == dist(now, c.s)) {
			if (customers[idx].s > c.s) {
				idx = i;
			}
		}
	}
	return idx;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> fuel;

	FOR(i, 1, N + 1) {
		FOR(j, 1, N + 1) {
			cin >> board[i][j];
		}
	}

	pii now;
	cin >> now.first >> now.second;

	FOR(i, 0, M) {
		Customer c;
		cin >> c.s.first >> c.s.second >> c.e.first >> c.e.second;
		customers.push_back(c);
		if (max(dist(now, c.s), dist(now, c.e)) == 1e9) {
			cout << -1; exit(0);
		}
	}

	FOR(i, 0, M) {
		int customer_idx = get_closest_customer(now);
		Customer& c = customers[customer_idx];
		c.vst = true;

		int a = dist(now, c.s);
		int b = dist(c.s, c.e);
		int moves = a + b;
		fuel -= moves;
		if (fuel < 0) {
			cout << -1; exit(0);
		}
		fuel += b * 2;

		now = c.e;
	}

	cout << fuel;

}
