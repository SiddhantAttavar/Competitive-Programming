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

bool util(vi v){
    if(v[0] == v[1] && v[1] == v[2]){
        return false;
    } else {
        if(v[0] != v[1]){
            int d = abs(v[0] - v[1]);
            v[0] = d;
            v[1] = d;
        }
        else if(v[0] != v[2]){
            int d = abs(v[0] - v[2]);
            v[0] = d;
            v[2] = d;
        } else {
            int d = abs(v[1] - v[2]);
            v[1] = d;
            v[2] = d;
        }
        return !util(v);
    }
}

bool solvexy(int x, int y) {
    if (y == 0) {
        return true;
    }
    if (x == 0) {
        return false;
    }
    if (x < y) {
        return !solvexy(y, y - x);
    }

    int k = x / (2 * y);
    x %= 2 * y;
    if (x >= y) {
        return !solvexy(y, x - y) ^ (k % 2);
    }
    return solvexy(x, y) ^ (k % 2);
}

void solve() {
	int x, y, z;
    cin >> x >> y >> z;

    if (!solvexy(z, abs(x - y)) or !solvexy(x, abs(y - z)) or !solvexy(y, abs(x - z))) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}

signed main() {
    // for(int x = 1; x<=50; x++){
    //     for(int y = 1; y<=50; y++){
    //         vi v = {x, y, y};
    //         assert(util(v) == solvexy(x, y));
    //         // cout << x << " " << y << " " << y << " : " << (util(v)? "Y" : "N") << endl;
    //     }
    // }

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
