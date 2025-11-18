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

bool check(int k, vi a){
    int n = a.size();
    for(int t = 0; t<34; t++){
        for(int i = 0; i<n; i++){
            if(a[i] <= k){
                continue;
            }
            int del = a[i] - k;
            a[i] -= ((del + 1)/2)*2;
            a[(i+1)%n] += ((del + 1)/2);
        }
    }
    // rep(i, 0, n){
    //     cout << a[i] << " ";
    // }cout << endl;
    // cout << "the k value : ";
    // cout << k << endl;
    // rep(i, 0, n){
    //     cout << a[i] << " ";
    // }cout << endl;
    for(int i = 0; i<n; i++){
        if(a[i] != k){
            return false;
        }
    }
    return true;
}
void solve() {
    // cout << "no" << endl;
	int n; cin >> n;
    vi a(n);
    int ts = 0;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        ts += a[i];
    }
    // for(int i = 0; i<n; i++){
    //     cout << a[i] << " ";
    // }cout << endl;
    int bk = -1;


    int low = 0 , high = 1e9 + 1;
    // high = 2;
    while(low <= high){
        int mid = (low + high)/2;
        if(check(mid, a)){
            bk = mid;
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    // cout << bk << endl;
    if(bk == -1){
        cout << bk << endl;
    } else{
        cout << ts - (bk * n) << endl;
    }
}

signed main() {
    // cout << "no" << endl;
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
