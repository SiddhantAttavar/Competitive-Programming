#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

map<int, vector<int>> fact;
vector<int> primes;
const int N = 1e6;
int spf[N + 1];

vector<int> factor(int n) {
    if (fact.count(n)) {
        return fact[n];
    }
    int o = n;

    if (n <= N) {
        map<int, int> m;
        while (n > 1) {
            m[spf[n]]++;
            n /= spf[n];
        }

        vector<int> v = {1};
        for (pair<int, int> p : m) {
            vector<int> nv(v.begin(), v.end());
            int z = 1;
            rep(i, 0, p.second) {
                z *= p.first;
                for (int j : v) {
                    nv.push_back(j * z);
                }
            }
            v = nv;
        }
        return fact[o] = v;
    }

    map<int, int> m;
    for (int i : primes) {
        if (i > n) {
            break;
        }

        while (n % i == 0) {
            m[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        m[n]++;
    }

    vector<int> v = {1};
    for (pair<int, int> p : m) {
        vector<int> nv(v.begin(), v.end());
        int z = 1;
        rep(i, 0, p.second) {
            z *= p.first;
            for (int j : v) {
                nv.push_back(j * z);
            }
        }
        v = nv;
    }
    return fact[o] = v;
}

int solve(vector<int> &a) {
    map<int, int> m;
    for (int i : a) {
        m[i]++;
    }

    map<int, int> dp;
    for (pair<int, int> p : m) {
        for (int i : factor(p.first)) {
            dp[i] += p.second;
        }
    }

    int res = -1;
    for (pair<int, int> p : dp) {
        if (2 * p.second >= a.size()) {
            res = p.first;
        }
    }
    return res;
}

bool check(vector<int> &a, int x) {
    if (x == -1) {
        return false;
    }
    int c = 0;
    for (int i : a) {
        c += i % x == 0;
    }
    return 2 * c >= a.size();
}

int32_t main() {
    setup();

    rep(i, 0, N + 1) {
        spf[i] = i;
    }

    rep(i, 2, N + 1) {
        if (spf[i] != i) {
            continue;
        }

        primes.push_back(i);
        for (int j = i; j <= N; j += i) {
            if (spf[j] == j) {
                spf[j] = i;
            }
        }
    }

    int n;
    input(n);

    vector<int> a(n);
    arrput(a);

    int k = 100, l = 10000;
    if (a.size() <= k) {
        print(solve(a));
        return 0;
    }

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int x = -1, y = 10;
    int res = 0;
    while(y > 0) {
        vector<int> b(k), c(l);
        rep(i, 0, k) {
            b[i] = a[rng() % n];
        }
        rep(i, 0, l) {
            c[i] = a[rng() % n];
        }
        x = solve(b);
        if (check(c, x)) {
            res = max(res, x);
            y--;
        }
    }
    print(res);

}
