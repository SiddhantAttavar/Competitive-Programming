 
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, w; cin >> n >> w;
    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    sort(all(a));
    int ans = 1;
    if(n == 1){
        if(a[0] <= w){
            ans = 1;
        } else {
            ans = -1;
        }
    } else {
        if(a[n-1] > w || (a[0] + a[1]) > w){
            ans = -1;
        } else {
            int x = 0, y = 0;
            for(int i = 0; i<n; i++){
                if(a[0] + a[i] > w){
                    y++;
                } else {
                    x++;
                }
            }
            ans = (4*y) + (2*(x-2)) + 1;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
// g++ A.cpp && ./a.out < input.txt > output.txt
