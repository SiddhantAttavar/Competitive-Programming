#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

inline int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

const int N = 2e5, H = 20;
int pa[N][H], pb[N][H];
int sa[N][H], sb[N][H];
int prefa[N + 1], prefb[N + 1];
int suffa[N + 1], suffb[N + 1];
int a[N], b[N];

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        range(i, 0, n) {
            cin >> a[i];
        }
        range(i, 0, n) {
            cin >> b[i];
        }

        // 0.2
        range(i, 0, n) {
            pa[i][0] = a[i];
            pb[i][0] = b[i];
            sa[i][0] = a[i];
            sb[i][0] = b[i];
        }

        range(j, 1, H) {
            int k = n - (1 << (j - 1));
            for (int i = n - (1 << j); i >= 0; i--) {
                pa[i][j] = gcd(pa[i][j - 1], pa[k][j - 1]);
                pb[i][j] = gcd(pb[i][j - 1], pb[k][j - 1]);
                k--;
            }
        }

        range(j, 1, H) {
            int k = 0;
            range(i, (1 << j) - 1, n) {
                sa[i][j] = pa[k][j];
                sb[i][j] = pb[k][j];
                k++;
            }
        }

        vector<int> w;
        // 0.07
        int u = n - 1;
        int k = 0;
        while (u >= 0) {
            w.push_back(u);
            k = gcd(k, a[u]);
            for (int j = 31 - __builtin_clz(u + 1); j >= 0 and u >= 0; j--) {
                if (u - (1 << j) >= -1) {
                    u -= !(sa[u][j] % k) << j;
                }
            }
        }

        u = n - 1;
        k = 0;
        while (u >= 0) {
            w.push_back(u);
            k = gcd(k, b[u]);
            for (int j = 31 - __builtin_clz(u + 1); j >= 0 and u >= 0; j--) {
                if (u - (1 << j) >= -1) {
                    u -= !(sb[u][j] % k) << j;
                }
            }
        }

        sort(w.begin(), w.end());
        vector<int> nw = {w[0]};

        range(i, 1, w.size()) {
            if (nw.back() != w[i]) {
                nw.push_back(w[i]);
            }
        }
        w = nw;

        // 0.01
        suffa[n] = 0;
        suffb[n] = 0;
        prefa[0] = 0;
        prefb[0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffa[i] = gcd(suffa[i + 1], a[i]);
            suffb[i] = gcd(suffb[i + 1], b[i]);
        }
        range(i, 0, n) {
            prefa[i + 1] = gcd(prefa[i], a[i]);
            prefb[i + 1] = gcd(prefb[i], b[i]);
        }

        int res = 0;
        long long z = 0;
        int p = 0, q = 0;
        range(l, 0, n) {
            vector<int> v(lower_bound(w.begin(), w.end(), l), w.end());
            int k = 0;
            int u = l;
            while (u < n) {
                v.push_back(u);
                k = gcd(a[u], k);
                int o = n;
                while (u < o) {
                    int j = 31 - __builtin_clz(o - u);
                    if (pa[u][j] % k) {
                        o = u + (1 << j) - 1;
                    }
                    else {
                        u += 1 << j;
                    }
                }
            }

            k = 0;
            u = l;
            while (u < n) {
                v.push_back(u);
                k = gcd(b[u], k);
                int o = n;
                while (u < o) {
                    int j = 31 - __builtin_clz(o - u);
                    if (pb[u][j] % k) {
                        o = u + (1 << j) - 1;
                    }
                    else {
                        u += 1 << j;
                    }
                }
            }

            sort(v.begin(), v.end());
            v.push_back(n);
            // 0.05
            for (int i = v.size() - 2; i >= 0; i--) {
                int r = v[i], nr = v[i + 1];
                if (r == nr) {
                    continue;
                }
                int e = q, f = p;
                e = gcd(e, suffb[r + 1]);
                f = gcd(f, suffa[r + 1]);
                if (e and f and e + f < res) {
                    break;
                }

                int k = 31 - __builtin_clz(r - l + 1);
                e = gcd(e, gcd(pa[l][k], sa[r][k]));
                f = gcd(f, gcd(pb[l][k], sb[r][k]));

                if (e + f > res) {
                    res = e + f;
                    z = nr - r;
                }
                else if (e + f == res) {
                    z += nr - r;
                }
            }

            p = gcd(p, a[l]);
            q = gcd(q, b[l]);

            if (p + q < res) {
                break;
            }
        }

        print(res, z);
    }
}
