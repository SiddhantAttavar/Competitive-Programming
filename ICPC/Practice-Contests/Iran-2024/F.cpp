#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((ll)((x).size()))

typedef pair<int, int> pii;
typedef vector<int> vi;

#define meh { cout << "MISS ME!" << endl; return; }

void solve() {

    vector<string> ph;
    string line;

    while(getline(cin, line)) {
        while(sz(line) > 0 && (line.back() == '\n' || line.back() == '\r')) {
            line.pop_back();
        }

        if(line == "#") {
            break;
        }

        string num;
        for(char c : line) {
            if(c >= '0' && c <= '9') {
                num += c;
            } else if (c == ',') {
                if(sz(num) == 10) { num = "0" + num; }

                if(sz(num) == 11) { ph.push_back(num); }

                num = "";

            } else {
                // skip it and do nothing
            }
        }

        if(sz(num) == 10) { num = "0" + num; }

        if(sz(num) == 11) { ph.push_back(num); }
    }

    string C;
    for (auto& s : ph) C += s;
    ll n = sz(ph), len = sz(C);
    ll cur = 0;
    string S;
    string instr;

    while (cin >> instr) {
        if (instr == "go") {
            ll x; cin >> x;
            if (x < 0 || x >= n) { meh; }
            cur = x * 11;
        } else if (instr == "forward") {
            ll x; cin >> x;
            if (cur + x > len) { meh; }
            cur += x;
        } else if (instr == "backward") {
            ll x; cin >> x;
            if (x > cur) { meh; }
            cur -= x;
        } else if (instr == "next") {
            ll x; cin >> x;
            if (cur + x > len) { meh; }
            S += C.substr(cur, x);
        } else if (instr == "pick") {

            ll a, b; cin >> a >> b;
            if (cur >= len || a < 0 || a > 10 || b < 0 || b > 10) { meh; }

            ll base = cur / 11 * 11;

            if (a <= b) {
                for (ll k = a; k <= b; k++) { S += C[base + k]; }
            } else {
                for (ll k = a; k >= b; k--) { S += C[base + k]; }
            }

        } else if (instr == "delete") {
            ll x; cin >> x;
            if (x > sz(S)) { meh; }
            S.resize(sz(S) - x);
        }
    }

 

    if (sz(S) > 10000) { S.resize(10000); }

    cout << S << endl;

}

 

signed main() {

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve();




}
