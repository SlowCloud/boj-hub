#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0);
#define NOTIE cin.tie(0); cout.tie(0);

#define endl '\n'
typedef long long ll;
typedef pair<int, int> ii;

#define INF 2'000'000'000

ll m[500][500];

int main() {
    FAST; NOTIE;

    ll N, M, B; cin >> N >> M >> B;


    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> m[i][j];
    }

    ll fastest = INF, fastest_height = -1;
    for (int height = 256; height >= 0; height--) {
        ll inventory = B, times = 0;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            if (height < m[i][j]) {
                times += (m[i][j] - height) * 2;
            }
            if (height > m[i][j]) {
                times += height - m[i][j];
            }
            inventory -= height - m[i][j];
        }
        if (inventory < 0) times = INF;
        if (fastest > times) {
            fastest = times; fastest_height = height;
        }
    }
    
    cout << fastest << ' ' << fastest_height << endl;

} // main