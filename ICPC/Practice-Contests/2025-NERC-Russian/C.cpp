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
    vi a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    sort(all(a));
    int i = 0;
    vi v;
    while(i<(n-1)){
        if(a[i] == a[i+1]){
            v.push_back(a[i]);
            i+=2;
        } else{
            i++;
        }
    }
    if(v.size() < 4){
        cout << "NO\n";
    } else{
        cout << "YES\n";
        int x1 = v[0];
        int y1 = v[1];
        int x2 = v[v.size()-2];
        int y2 = v[v.size()-1];
        cout << x1 << " " << y1 << " " << x1 << " " << y2 << " " << x2 << " " << y1 << " " << x2 << " " << y2 << "\n";
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
