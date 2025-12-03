#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool check(string s) {
    vector<string> a, b;
    string x;
    bool flag = false;
    for (char c : s) {
        if (c == '=') {
            a.push_back(x);
            x = "";
            swap(a, b);
        }
        else if (c == '+') {
            a.push_back(x);
            x = "";
        }
        else if (c == '-') {
            a.push_back(x);
            x = "-";
        }
        else if (flag) {
            x += c;
        }
        else {
            x += c;
        }
    }
    a.push_back(x);
    if (a.empty() or b.empty()) {
        return false;
    }
    if ((!a[0].empty() and a[0][0] == '-') or (!b[0].empty() and b[0][0] == '-')) {
        return false;
    }
    int p = 0, q = 0;
    for (string s : a) {
        int l = sz(s) - (!s.empty() and s[0] == '-');
        if (l == 0 or l > 10 or (s[s[0] == '-'] == '0' and l != 1)) {
            return false;
        }
        p += stoll(s);
    }
    for (string s : b) {
        int l = sz(s) - (!s.empty() and s[0] == '-');
        if (l == 0 or l > 10 or (s[s[0] == '-'] == '0' and l != 1)) {
            return false;
        }
        q += stoll(s);
    }
    return p == q;
}

void solve() {
	string s;
    cin >> s;

    if (check(s)) {
        cout << "Correct\n";
        return;
    }

    rep(i, 0, sz(s)) {
        if (s[i] < '0' or s[i] > '9') {
            continue;
        }
        char c = s[i];
        string t = s;
        t.erase(t.begin() + i);
        rep(j, 0, sz(t) + 1) {
            string u = t;
            u.insert(u.begin() + j, c);
            if (check(u)) {
                cout << u << endl;
                return;
            }
        }
    }
    cout << "Impossible\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
