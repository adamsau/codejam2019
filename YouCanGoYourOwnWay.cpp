#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

char ans[500001];
void solve() {
    string s;
    int n;
    cin >> n >> s;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == 'E') ans[i] = 'S';
        else ans[i] = 'E';
    }
    ans[s.length()] = 0;
    cout << ans << endl;
}

int main() {
    //freopen("../in", "r", stdin);
    //freopen("../out", "w", stdout);
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}