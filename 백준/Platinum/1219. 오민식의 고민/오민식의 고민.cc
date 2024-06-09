#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <random>

using namespace std;

#define FAST ios::sync_with_stdio(0);
#define NOTIE cin.tie(0); cout.tie(0);
constexpr int INF = 21e8;
constexpr long long LLINF = 9e18;

#define endl '\n'
typedef long long ll;
typedef pair<int, int> ii;
#define all(v) v.begin(), v.end()

vector<int> G[51];
ll d[51];
int earn[51];
int N, M;
vector<pair<ii, int>> edges;

stack<int> st;
bool dfs(int end) {
	set<int> visited;
	while (st.size()) {
		int now = st.top(); st.pop();
		for (auto& next : G[now]) {
			if (visited.count(next)) continue;
			visited.insert(next);
			st.push(next);
		}
	}
	return visited.find(end) != visited.end();
}

bool bellman(int begin) {
	fill(d, d + 51, INF);
	d[begin] = -earn[begin];

	bool cycle = false;

	// 노드 개수만큼 반복
	for (int i = 1; i <= N; i++) {
		for (auto& edge : edges) {
			int& start = edge.first.first;
			int& next = edge.first.second;
			ll w = edge.second;

			if (d[start] < INF && d[next] > d[start] + w) {
				d[next] = d[start] + w;
				if (i == N) {
					// N번째에서도 갱신이 되면 음수루프
					// dfs 통해 음수루프->end 가는지 확인 위해 노드 기록
					st.push(start);

					// 음수루프가 여러 개인 경우를 염두에 두어야 하므로
					// 빠져나가지는 않음.
					cycle = true;
				}
			}
		}
	}
	return cycle;
}

int main() {
	FAST; NOTIE;

	int begin, end;
	cin >> N >> begin >> end >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		edges.push_back({ {a,b}, c });
		G[a].push_back(b);
	}

	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		earn[i] = n;
		for (auto& edge : edges) {
			if (edge.first.second == i) edge.second -= n;
		}
	}

	bool check = bellman(begin);

	if (d[end] >= INF) {
		cout << "gg"; return 0;
	}

	// 음수루프 존재하더라도, 음수루프에서 end로 가지 못하는 경우도 존재한다.
	// start -> 음수루프, start -> end 같은 경우.
	// 음수루프하는 노드를 스택에 넣어서 end에 도착하는지 확인해야 한다.
	if (check && dfs(end)) {
		cout << "Gee"; return 0;
	}

	cout << -d[end];

} // main
