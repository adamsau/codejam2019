#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <utility>

using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<string> VS;

VPII valid;
VPII ans;
int vis[21][21];

void solve() {
    int R, C;
    cin >> R >> C;

    for(int m = 0; m < 100; ++m) {
        int cr = 0, cc = 0;

        ans.clear();
        memset(vis, 0, sizeof(vis));
        while(true) {
            valid.clear();
            for(int i = 1; i <= R; ++i) {
                for(int j = 1; j <= C; ++j) {
                    if(vis[i][j]) continue;
                    if(cr != 0 && cc != 0 && (cr == i || cc == j || (cr - cc == i - j) || (cr + cc == i + j))) continue;

                    valid.emplace_back(make_pair(i, j));
                }
            }
            if(valid.size() == 0) {
                break;
            }
            int pos = rand() % valid.size();
            PII pii = valid[pos];
            ans.emplace_back(pii);
            cr = pii.first, cc = pii.second;
            vis[cr][cc] = 1;
            if(ans.size() == R * C) {
                cout << "POSSIBLE" << endl;
                for(auto pii2: ans) cout << pii2.first << " " << pii2.second << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}