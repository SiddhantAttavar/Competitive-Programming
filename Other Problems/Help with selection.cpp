#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod_pow(int a, int b, int m) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int mod_div(int a, int b, int m) {
    return a * mod_pow(b, m - 2, m) % m;
}

signed main() {
    int t; cin >> t; while (t--) {
        int n, k, p;
        cin >> n >> k >> p;
        
        vector<int> fact(p, 1);
        for (int i = 2; i < p; i++) {
            fact[i] = i * fact[i - 1] % p;
        }
        
        vector<int> a, b;
        while (n) {
            a.push_back(n % p);
            b.push_back(k % p);
            n /= p;
            k /= p;
        }
        
        int res = 1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] < b[i]) {
                res = 0;
                break;
            }
            res = (res * mod_div(fact[a[i]], fact[a[i] - b[i]] * fact[b[i]] % p, p)) % p;
        }
        cout << res << endl;
    }
}
