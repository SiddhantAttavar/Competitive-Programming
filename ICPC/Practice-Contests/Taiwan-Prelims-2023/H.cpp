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

int left(int p, int n, int z){
    if (2 * p > z) {
        return p;
    }
    return left(2 * p, n, z);
}

int right(int p, int n, int z){
    if (2 * p + 1 > z) {
        return min(n, p);
    }
    return right(2 * p + 1, n, z);
}

int fn(int k, int n, int z) {
    return max(0ll, right(k, n, z) - left(k, n, z) + 1);
}

int brute(int p, int n) {
    if (p > n) {
        return 0;
    }
    return brute(2 * p, n) + brute(2 * p + 1, n) + 1;
}

void solve() {
    rep(i, 0, 100) {
        int n = max(1, rand() % 100);
        int k = rand() % n + 1;
        // cout << n << ' ' << k << endl;
        // cout.flush();
        int logn = 63 - __builtin_clzll(n);
        int z = (1ll << (logn + 1)) - 1;
        int logmid = 63 - __builtin_clzll(k);
        int x = (1ll << (logn - logmid)) - 1;
        // cout << brute(k, n) << ' ' << x + fn(k, n, z) << ' ' << x << endl;
        // cout.flush();
        assert(brute(k, n) == x + fn(k, n, z));
    }
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int lb = min(n, (1ll<<k) - 1ll);
    int low = 1, high = n;
    int logn = 63 - __builtin_clzll(n);
    int z = (1ll << (logn + 1)) - 1;
    while(low <= high){
        int mid = (low + high)/2;
        int logmid = 63 - __builtin_clzll(mid);
        int x = (1ll << (logn - logmid)) - 1;
        if(x + fn(mid, n, z) <= (n-k+1)){
            lb = mid;
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    int ub = min(n, (1ll<<k) - 1ll);
    cout << max(0ll, ub - lb + 1) << endl;
    return;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1; while (t--) {
		solve();
	}
}
