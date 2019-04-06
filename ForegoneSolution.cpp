#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

char a[105];
char b[105];

void solve() {
    string s;
    cin >> s;
    int bind = -1;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == '4') {
            a[i] = '1';
            b[i] = '3';
            if(bind == -1) bind = i;
        }
        else {
            a[i] = s[i];
            b[i] = '0';
        }
    }
    a[s.length()] = b[s.length()] = 0;
    cout << a << " " << (bind != -1 ? b + bind : 0) << endl;
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