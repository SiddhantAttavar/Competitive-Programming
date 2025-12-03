#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), ecnd(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N = 1e6 + 1;

vi primes;
vi isprime(N ,1);
void solve() {
	int n; cin >> n;
    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    vi pfs;
    for(auto it : primes){
        if(it > n){
            break;
        } else if(n%it == 0){
            pfs.push_back(it);
        }
    }
    for(auto it : pfs){
        cout << it << endl;
    }
    double bans = 1e18;
    for(auto k : pfs){
        vi sums(k, 0);
        multiset<int> ms;
        rep(i, 0, n){
            sums[(i%k)] += a[i];
        }
        for(auto it : sums){
            ms.insert(it);
        }
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // calc all primes till 1e6
    for(int i = 2; i<N; i++){
        if(isprime[i]){
            primes.push_back(i);
            for(int j = i*i; j<N; j+=i){
                isprime[j] = 0;
            }
        }
    }  
    // for(auto it : primes){
    //     cout << it << " ";
    // }cout << endl;
    
	int t = 1;
	cin >> t;
	while (t--) solve();
}
