#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define endl "\n"

int get(string t) {
    if (t.empty()) {
        return 0;
    }
    if (t.size() >= 19 or (t.size() == 18 and t.back() != '1')) {
        return 2e18;
    }
    reverse(t.begin(), t.end());
    return stoll(t);
}

void solve() {
    string x;
    int b;
    cin >> x >> b;

    int n = x.size();
    if (x == string(n, '0')) {
        cout << 0 << endl;
        return;
    }

    reverse(x.begin(), x.end());
    int i = 0, res = 0;
    while (i < n) {
        string s;
        s += x[i];
        int j = i;
        while (j < n - 1 and get(s) <= b) {
            j++;
            s += x[j];
        }
        if (get(s) > b) {
            s.pop_back();
            j--;
        }
        if (get(s) == 0) {
            res = -1;
            break;
        }
        b = get(s);
        while (s.back() == '0') {
            s.pop_back();
            j--;
        }
        res++;
        i = j + 1;
    }
    
    if (res == -1) {
        cout << "NO WAY\n";
    }
    else {
        cout << res - 1 << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1; while (t--) {
		solve();
	}
}
