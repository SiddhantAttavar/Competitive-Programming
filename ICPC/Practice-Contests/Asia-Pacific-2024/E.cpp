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

void solve() {
	int n; cin >> n;
    vector<vi> g(n, vi(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> g[i][j];
        }
    }
    set<int> sa, sb;
    vi a, b;
    rep(i, 0, n){
        set<int> st;
        rep(j, 0, n){
            st.insert(g[i][j]);
        }
        if(st.size() == n){
            a.push_back(i);
            sa.insert(i);
        }
    }
    rep(j, 0, n){
        set<int> st;
        rep(i, 0, n){
            st.insert(g[i][j]);
        }
        if(st.size() == n){
            b.push_back(j);
            sb.insert(j);
        }
    }
    // rep(i, 0, a.size()){
    //     cout << a[i] << " ";
    // }cout << endl;
    // rep(i, 0, b.size()){
    //     cout << b[i] << " ";
    // }cout << endl;
    // return;
    
    rep(i, 0, n){
        if(a.size() < b.size()){
            if(sa.find(i) == sa.end()){
                a.push_back(i);
                sa.insert(i);
            }
        }
    }
    rep(j, 0, n){
        if(b.size() < a.size()){
            if(sb.find(j) == sb.end()){
                b.push_back(j);
                sb.insert(j);
            }
        }
    }
    sort(all(a));
    sort(all(b));
    // rep(i, 0, a.size()){
    //     cout << a[i] << " ";
    // }cout << endl;
    // rep(i, 0, b.size()){
    //     cout << b[i] << " ";
    // }cout << endl;
    // return;

    cout << a.size() << endl;
    rep(i, 0, a.size()){
        rep(x, 1, 4) {
            vector<int> fr(n + 1, 0), fc(n + 1, 0);
            g[a[i]][b[i]] = x;
            rep(j, 0, n) {
                fr[g[a[i]][j]]++;
                fc[g[j][b[i]]]++;
            }
            if (*max_element(fr.begin(), fr.end()) > 1 and *max_element(fc.begin(), fc.end()) > 1) {
                cout << a[i] + 1 << ' ' << b[i] + 1 << ' ' << x << endl;
                break;
            }
        }
    }
    // rep(i, 0, n){
    //     rep(j, 0, n){
    //         cout << g[i][j] << " ";
    //     }cout << endl;
    // }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
