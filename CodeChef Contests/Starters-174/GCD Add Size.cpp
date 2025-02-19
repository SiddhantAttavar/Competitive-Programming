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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

const int N = 1e6;

int32_t main() {
    vector<int> spf(N + 1);
    range(i, 0, N + 1) {
        spf[i] = i;
    }
    range(i, 2, N + 1) {
        if (spf[i] != i) {
            continue;
        }

        for (int j = i; j <= N; j += i) {
            if (spf[j] == j) {
                spf[j] = i;
            }
        }
    }

    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> a(n);
        arrput(a);

        int r = *max_element(a.begin(), a.end());
        if (r > 1e6) {
            map<int, int> m;
            for (int i : a) {
                m[i]++;
            }
            int res = 0;
            for (pair<int, int> p : m) {
                res = max(res, p.first + p.second);
            }
            print(res);
            continue;
        }
        int l = max(1ll, r - n);
        vector<int> v(r - l + 1, 0);
        for (int i : a) {
            map<int, int> m;
            while (i > 1) {
                m[spf[i]]++;
                i /= spf[i];
            }
            set<int> s = {1};
            for (pair<int, int> p : m) {
                int z = 1;
                set<int> t(s.begin(), s.end());
                range(i, 0, p.second) {
                    z *= p.first;
                    for (int j : s) {
                        t.insert(j * z);
                    }
                }
                s = t;
            }
            for (int i : s) {
                if (i >= l and i <= r) {
                    v[i - l]++;
                }
            }
        }

        int res = 0;
        range(i, l, r + 1) {
            if (v[i - l] > 0) {
                res = max(res, i + v[i - l]);
            }
        }
        print(res);
    }
}
