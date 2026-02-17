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
 
constexpr ll inf = 1E18;
 
void solve() {

    ll k; cin >> k;
    string line;
    getline(cin, line); // -> is this necessary for a possible endline after k?

    vector<string> chunks(k);
    for(ll i = 0; i < k; i++) {
        getline(cin, chunks[i]);
        if(sz(chunks[i]) > 0 && chunks[i].back() == '\r') {
            chunks[i].pop_back();
        }
    }

    vector<ll> t(k); for(ll i = 0; i < k; i++) { cin >> t[i]; }

    ll typed = 0; ll ans = -inf;

    auto ready_char = [&](ll tm) -> void {
        ans = max(ans, tm - typed);
        typed++;  
    };

    ll style = 0;
    bool in_code = false, in_emoji = false;
    bool is_escape = false;

    for(ll i = 0; i < k; i++) {

        ll tm = t[i];

        for(char c : chunks[i]) {

            if(in_code == true) {
                if(c == '`') { in_code = false; }
                else { ready_char(tm); }
 
                continue;
            }

            if(is_escape == true) {
                ready_char(tm);
                is_escape = false;
                continue;
            }

            if(in_emoji == true) {
                if(c == ':') {
                    ready_char(tm);
                    in_emoji = false;
                }

                continue;
            }

           

            // activators
            if (c == '\\') { is_escape = true; continue; }
            if (c == '`')  { in_code = true; continue; }
            if (c == ':')  { in_emoji = true; continue; }

            if (style == 0 && c == '(') { style = 1; continue; }
            if (style == 0 && c == '[') { style = 2; continue; }
            
            if (style == 1 && c == ')') { style = 0; continue; }
            if (style == 2 && c == ']') { style = 0; continue; }
 
            // plain visible char
            ready_char(tm);
        }
    }

    cout << ans << endl;
}
 

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t; // comment out if reqd.
    while (t--) {solve();}
}

