#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


constexpr int SIZE = 4'000'004;
constexpr int sq = 2002;
constexpr int BUCKET_SIZE = SIZE / sq + 1;

int m[SIZE];
int bucket[BUCKET_SIZE];

void increase(int n) {
	bucket[n / sq]++; m[n]++;
}

void decrease(int n) {
	bucket[n / sq]--; m[n]--;
}

int lower_bound(int n) {
	for (int now = n / sq; now < BUCKET_SIZE; now++) {
		if (bucket[now]) {
			for (int i = max(now * sq, n); i < min(now * sq + sq, SIZE); i++) {
				if (m[i]) {
					return i;
				}
			}
		}
	}
	return -1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K; cin >> N >> M >> K;

	FOR(i, 0, M) {
		int n; cin >> n;
		increase(n);
	}

	FOR(i, 0, K) {
		int n; cin >> n;
		int now = lower_bound(n + 1);
		decrease(now);
		cout << now << ' ';
	}

}
