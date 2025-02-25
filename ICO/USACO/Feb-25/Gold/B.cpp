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
const int MOD = (int) 1e9 + 7; //998244353;

int mod_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }

        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int mod_div(int a, int b) {
    return (a * mod_pow(b, MOD - 2)) % MOD;
}

int pref(int i, vector<int> &p, vector<int> &a, bool b) {
    if (i == -1) {
        return 0;
    }
    int j = upper_bound(a.begin(), a.end(), i) - a.begin() - 1;
    return p[j] + ((b ^ j) % 2) * (i - a[j] + 1);
}

int suff(int i, vector<int> &v, vector<int> &a, bool b) {
    if (i == a.back()) {
        return 0;
    }
    int j = lower_bound(a.begin(), a.end(), i) - a.begin();
    // print(i, a[j], v[j], 'j');
    int res = v[j];
    if (((b ^ j) & 1) == 1) {
        return res;
    }
    int k = (mod_pow(2, a[j] - i) - 1 + MOD) % MOD;
    k = (k * mod_pow(2, a.back() - a[j])) % MOD;
    res = (res + k) % MOD;
    return res;
}

int32_t main() {
    setup();

    int n, m, q;
    input(n, m, q);

    if (n <= (int) 2e5) {
        vector<int> d(n + 1, 0);
        while (m--) {
            int l, r;
            input(l, r);
            d[r]--;
            d[l - 1]++;
        }

        vector<int> a(n);
        a[0] = d[0] % 2;
        rep(i, 1, n) {
            a[i] = ((a[i - 1] + d[i]) % 2 + 2) % 2;
        }

        vector<int> p(n + 1, 0);
        rep(i, 0, n) {
            p[i + 1] = p[i] + a[i];
        }

        vector<int> x(n, 0);
        x[0] = !a[0];
        rep(i, 1, n) {
            if (!a[i]) {
                x[i] = x[i - 1] + 1;
            }
        }

        vector<int> v(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            v[i] = (v[i + 1] + a[i] * mod_pow(2, n - i - 1)) % MOD;
        }

        while (q--) {
            int l, r, k;
            input(l, r, k);
            l--;
            r--;

            int y = p[r + 1] - p[l];
            if (y >= k) {
                print((mod_pow(2, k) - 1 + MOD) % MOD);
                continue;
            }

            int s = l, e = r, c = -1;
            while (s <= e) {
                int m = (s + e) / 2;
                int t = p[r + 1] - p[m];
                if ((r - m + 1 - t) + y >= k) {
                    c = m;
                    s = m + 1;
                }
                else {
                    e = m - 1;
                }
            }

            int res = mod_div((v[c] - v[r + 1] + MOD) % MOD, mod_pow(2, n - r - 1));
            int z = (mod_pow(2, k - (r - c + 1)) - 1 + MOD) % MOD;
            z = (z * mod_pow(2, r - c + 1)) % MOD;
            print((res + z) % MOD);
        }
        return 0;
    }

    map<int, int> d;
    while (m--) {
        int l, r;
        input(l, r);
        d[r]--;
        d[l - 1]++;
    }

    vector<int> a;
    bool b = false;
    if (!d.count(0)) {
        a.push_back(0);
    }
    else {
        b = abs(d[0]) % 2 != 0;
    }
    bool flag = b;
    for (pair<int, int> p : d) {
        if (abs(p.second) % 2) {
            flag = !flag;
            a.push_back(p.first);
        }
    }
    if (a.back() != n) {
        a.push_back(n);
    }

    vector<int> p(a.size(), 0);
    flag = b;
    rep(i, 0, a.size() - 1) {
        p[i + 1] = p[i];
        if (flag) {
            p[i + 1] += a[i + 1] - a[i];
        }
        flag = !flag;
    }

    vector<int> v(a.size(), 0);
    for (int i = a.size() - 2; i >= 0; i--) {
        v[i] = v[i + 1];
        if ((b ^ i) & 1) {
            int k = (mod_pow(2, a[i + 1] - a[i]) - 1 + MOD) % MOD;
            k = (k * mod_pow(2, n - a[i + 1])) % MOD;
            v[i] = (v[i] + k) % MOD;
        }
    }
    // rep(i, 0, n) {
    //     print(i, suff(i, v, a, b));
    // }

    while (q--) {
        int l, r, k;
        input(l, r, k);
        l--;
        r--;

        int y = pref(r, p, a, b) - pref(l - 1, p, a, b);
        if (y >= k) {
            print((mod_pow(2, k) - 1 + MOD) % MOD);
            continue;
        }

        int s = l, e = r, c = -1;
        while (s <= e) {
            int m = (s + e) / 2;
            int t = pref(r, p, a, b) - pref(m - 1, p, a, b);
            if ((r - m + 1 - t) + y >= k) {
                c = m;
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }

        // print(c, l, r, k);
        int res = (suff(c, v, a, b) - suff(r + 1, v, a, b) + MOD) % MOD;
        // print(suff(c, p, a, b), c);
        res = mod_div(res, mod_pow(2, n - r - 1));
        int z = (mod_pow(2, k - (r - c + 1)) - 1 + MOD) % MOD;
        z = (z * mod_pow(2, r - c + 1)) % MOD;
        print((res + z) % MOD);
    }
}
