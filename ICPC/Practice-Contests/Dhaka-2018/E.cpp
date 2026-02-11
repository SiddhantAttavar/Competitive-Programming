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

bool check(array<int, 3> &a, array<int, 3> &b, array<int, 3> c, array<int, 3> d, int x) {
    a = max(a, c);
    if (a > d) {
        return false;
    }
    if (b[2] < a[2]) {
        b[2] += 60;
        b[1]--;
    }
    if (b[1] < a[1]) {
        b[1] += 60;
        b[0]--;
    }
    if (b[0] < a[0] + x) {
        return false;
    }
    return true;
}

void solve(int n) {
    int x = 0;
    while (n--) {
        string s;
        cin >> s;

        vector<string> l = {""};
        for (char c : s) {
            if (c == ':') {
                l.push_back("");
            }
            else {
                l.back() += c;
            }
        }
        char c = l[0][0];
        array<int, 3> a = {stoll(l[1]), stoll(l[2]), stoll(l[3])};
        array<int, 3> b = {stoll(l[4]), stoll(l[5]), stoll(l[6])};

        x += ((c == 'D' and !check(a, b, {8, 30, 0}, {9, 30, 0}, 8)) or
            (c == 'E' and !check(a, b, {8, 30, 0}, {12, 30, 0}, 9)));
    }
    if (x == 0) {
        cout << "All OK" << endl;
    }
    else if (x > 3) {
        cout << "Issue Show Cause Letter" << endl;
    }
    else {
        cout << x << " Point(s) Deducted" << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while (true) {
        int n;
        cin >> n;

        if (!n) {
            break;
        }

        solve(n);
    }
}
