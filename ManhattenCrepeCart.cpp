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

int yy[100001];
int xx[100001];

void solve() {
    memset(yy, 0, sizeof(yy));
    memset(xx, 0, sizeof(xx));

    int P, Q;
    cin >> P >> Q;
    for (int i = 0; i < P; ++i) {
        int x, y;
        char d;
        cin >> x >> y >> d;
        if (d == 'N') {
            for (int j = y + 1; j <= Q; ++j) {
                yy[j] += 1;
            }
        } else if (d == 'S') {
            for (int j = y - 1; j >= 0; --j) {
                yy[j] += 1;
            }
        } else if (d == 'E') {
            for (int j = x + 1; j <= Q; ++j) {
                xx[j] += 1;
            }
        } else if (d == 'W') {
            for (int j = x - 1; j >= 0; --j) {
                xx[j] += 1;
            }
        }
    }

    int ansx = 0, ansy = 0;
    int maxx = 0, maxy = 0;
    for(int i = 0; i <= Q; ++i) {
        if(yy[i] > maxy) {
            ansy = i;
            maxy = yy[i];
        }
        if(xx[i] > maxx) {
            ansx = i;
            maxx = xx[i];
        }
    }
    cout << ansx << " " << ansy << endl;
}

int main() {
    //freopen("../in", "r", stdin);
    //freopen("../out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}