#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define all(v) begin(v), end(v)
#define sz(a) (int)a.size()
// #define ll long long

typedef long long ll;
typedef complex<double> C;
typedef vector<double> vs;

const int MOD = 1e9+7;

const int N = 1e8;
// int spf[N + 1];

int mod_pow(int a, int b, int m) {
    a %= m;
    b %= m - 1;
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
    return (a * mod_pow(b, m - 2, m)) % MOD;
}

int mod_log(int a, int b, int m) {
    int n = (int) sqrt(m) + 1, e = 1, f = 1, j = 1;
    unordered_map<int, int> A;
    while (j <= n && (e = f = e * a % m) != b % m) {
        A[e * b % m] = j++;
    }
    if (e == b % m) {
        return j;
    }
    if (__gcd(m, e) == __gcd(m, b)) {
        rep(i, 2, n + 2) {
            if (A.count(e = e * f % m)) {
                return n * i - A[e];
            }
        }
    }
    return -1;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int euclid(int a, int b, int &x, int &y) {
    if (!b) return x = 1, y = 0, a;
    int d = euclid(b, a % b, y, x);
    return y -= a / b * x, d;
}

const int LIM = 1e8;
bitset<LIM> isPrime;
int spf[N + 1];
vi eratosthenes() {
    const int S = (int)round(sqrt(LIM)), R = LIM / 2;
    vi pr = {2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
    vector<pii> cp;
    for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
        cp.push_back({i, i * i / 2});
        for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
    }
    for (int L = 1; L <= R; L += S) {
        array<bool, S> block{};
        for (auto &[p, idx] : cp)
            for (int i=idx; i < S+L; idx = (i+=p)) block[i-L] = 1;
        rep(i,0,min(S, R - L))
            if (!block[i]) pr.push_back((L + i) * 2 + 1);
    }
    for (int i : pr) isPrime[i] = 1;
    return pr;
}

void solve() {
    int m;
    cin >> m;

    if (m == 4 or m == 9 or m == 6 or m == 8) {
        cout << "LOST THEOREM\n";
        return;
    }

    int x, y, z, n;
    if (spf[m] != m) {
        y = m / spf[m];
        if (spf[m] == 2) {
            x = 4;
        }
        else {
            x = spf[m];
        }
        z = x + y;
        n = 3;
    }
    else {
        x = m - 1;
        y = m - 1;
        int k = 1;
        n = 0;
        while (n <= 2 or n >= m) {
            if (__gcd(k, m - 1) != 1) {
                k++;
                continue;
            }
            z = m - (1 << k);
            if (z <= 2) {
                cout << "LOST THEOREM\n";
                return;
            }
            int y;
            euclid(k, m - 1, n, y);
            n = (n % (m - 1) + m - 1) % (m - 1);
            k++;
        }
    }
    cout << "FOUND\n";
    cout << x << ' ' << y << ' ' << z << ' ' << n << '\n';
    cout.flush();
    assert((mod_pow(x, n, m) + mod_pow(y, n, m)) % m == mod_pow(z, n, m));
    assert(2 < min({x, y, z, n}));
    assert(max({x, y, z, n}) < m);
}

signed main() {
    rep(i, 0, N + 1) {
        spf[i] = i;
    }
    for (int i = 2; i <= N; i += 2) {
        spf[i] = 2;
    }
    rep(i, 3, N + 1) {
        if (spf[i] != i) {
            continue;
        }

        for (int j = i * i; j <= N; j += i) {
            if (spf[j] == j) {
                spf[j] = i;
            }
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}
