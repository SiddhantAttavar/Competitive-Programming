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

#define cff {cout.flush();}

void solve() {

    int n, d, s; cin >> n >> d >> s;
    // int s1 = 1;
    int d1 = d/s;
    int n1 = n/s;
    n1 = min(n1, 2*d1);
    // cout << s1 << " " << d1 << " " << n1 << endl;
    if(n1 == 1 || d1 == 0){
        cout << s << endl;
        return;
    }
    for(int i = 2; i<=1e6; i++){
        if(n1 % i == 0){
            // cout << n1 << " " << i << endl;
            int other = n1/i;
            if((n1 - other) <= d1){
                cout << n1*s << endl;
            } else{
                cout << (n1-1)*s << endl;
            }
            return;
        }
    }
    if((n1 - 1) <= d1){
        cout << n1*s << endl;
    } else{
        cout << (n1 - 1)*s << endl;
    }
}   

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t; // comment out if reqd.
    while (t--) {solve();}
}
