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

#define M 4

int _T;
int ans;

int dfsFill(int R, int C, char move, int B, char g2[][M], int i, int j) {
    if (move == 'H') {
        g2[i][j] = 'H';
        for (int k = j - 1; k >= 0 && (g2[i][k] == '.' || g2[i][k] == '#'); --k) {
            if (g2[i][k] == '#') {
                return 0;
            }
            g2[i][k] = 'H';
        }
        for (int k = j + 1; k < C && (g2[i][k] == '.' || g2[i][k] == '#'); ++k) {
            if (g2[i][k] == '#') {
                return 0;
            }
            g2[i][k] = 'H';
        }
    } else if (move == 'V') {
        g2[i][j] = 'V';
        for (int k = i - 1; k >= 0 && (g2[k][j] == '.' || g2[k][j] == '#'); --k) {
            if (g2[k][j] == '#') {
                return 0;
            }
            g2[k][j] = 'V';
        }
        for (int k = i + 1; k < R && (g2[k][j] == '.' || g2[k][j] == '#'); ++k) {
            if (g2[k][j] == '#') {
                return 0;
            }
            g2[k][j] = 'V';
        }
    }
    return 1;
}

int dfs(int R, int C, char move, int B, char g[][M], int level) {
    int ok = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (g[i][j] == '.') {
                char g2[M][M];
                for (int m = 0; m < R; ++m) {
                    for (int n = 0; n < C; ++n) {
                        g2[m][n] = g[m][n];
                    }
                }
                int ok2 = dfsFill(R, C, move, B, g2, i, j);
                if (ok2) {
                    int ok3 = !dfs(R, C, 'H', !B, g2, level + 1) && !dfs(R, C, 'V', !B, g2, level + 1);
                    ok |= ok3;
                    if (level == 0 && ok3) ans++;
                }
                if (level != 0 && ok) {
                    return ok;
                }
            }
        }
    }
    return ok;
}

void solve() {
    int R, C;
    cin >> R >> C;
    ans = 0;
    char g[M][M];
    for (int i = 0; i < R; ++i) cin >> g[i];
    dfs(R, C, 'H', 1, g, 0);
    dfs(R, C, 'V', 1, g, 0);
    cout << ans << endl;
}

int main() {
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
    int T;
    cin >> T;
    for (_T = 1; _T <= T; ++_T) {
        printf("Case #%d: ", _T);
        solve();
    }

    return 0;
}