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


string C[256];
int vis[256];
char ans[501];

void solve() {
    int A;
    cin >> A;
    memset(ans, 0, sizeof(ans));
    memset(C, 0, sizeof(C));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < A; ++i) {
        string s;
        cin >> s;
        C[i] = s;
    }
    for (int i = 0; i < A; ++i) {
        int R = 0, S = 0, P = 0;
        for (int j = 0; j < A; ++j) {
            if (vis[j]) continue;
            char c = C[j][i % C[j].size()];
            if (c == 'R') R++;
            else if (c == 'P') P++;
            else if (c == 'S') S++;
        }
        //check
        if (R != 0 && P != 0 && S != 0) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        else if (R == 0 && P == 0 && S == 0) {
            cout << ans << endl;
            return;
        }

        char ac = ans[i % 500];

        if (R == 0 && P == 0) {
            ans[i] = 'R';
            cout << ans << endl;
            return;
        } else if (R == 0 && S == 0) {
            ans[i] = 'S';
            cout << ans << endl;
            return;
        } else if (S == 0 && P == 0) {
            ans[i] = 'P';
            cout << ans << endl;
            return;
        } else if (S == 0) {
            ans[i] = 'P';
            for (int j = 0; j < A; ++j) {
                if (vis[j]) continue;
                char c = C[j][i % C[j].size()];
                if (c == 'R') {
                    vis[j] = 1;
                }
            }
        } else if (P == 0) {
            ans[i] = 'R';
            for (int j = 0; j < A; ++j) {
                if (vis[j]) continue;
                char c = C[j][i % C[j].size()];
                if (c == 'S') {
                    vis[j] = 1;
                }
            }
        } else if (R == 0) {
            ans[i] = 'S';
            for (int j = 0; j < A; ++j) {
                if (vis[j]) continue;
                char c = C[j][i % C[j].size()];
                if (c == 'P') {
                    vis[j] = 1;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return;
}

int main() {
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}