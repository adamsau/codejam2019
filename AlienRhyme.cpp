#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef vector<int> VI;
typedef unordered_map<string, VI> UMSVI;
typedef vector<string> VS;

int vis[1001];
VS vs;
UMSVI umsvi;

void solve() {
    memset(vis, 0, sizeof(vis));
    umsvi.clear();
    vs.clear();

    int N;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); ++j) {
            umsvi[string(s, j, s.size() - j)].emplace_back(i);
        }
        vs.emplace_back(s);
    }

    int ans = 0;
    for(int i = 50; i >= 1; --i) {
        for(int j = 0; j < N ; ++j) {
            if(vis[j] || i > vs[j].size()) continue;

            VI& vi = umsvi[string(vs[j], vs[j].size() - i, i)];
            int ok = 0;
            for(auto it = vi.begin(); it != vi.end(); ++it) {
                int k = *it;
                if(k != j && !vis[k]) {
                    vis[k] = vis[j] = 1;
                    ok = 1;
                    ans += 2;
                    break;
                }
            }
            if(ok) {
                vi.clear();
            }
        }
    }
    cout << ans << endl;
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