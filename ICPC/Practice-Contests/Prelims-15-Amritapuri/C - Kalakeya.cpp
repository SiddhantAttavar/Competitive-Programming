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
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, k;
        input(n, k);

        if (n < 2 * k) {
            print(-1);
            continue;
        }

        if (k == 0) {
            vector<int> res(n);
            range(i, 0, n) {
                res[i] = i + 1;
            }
            arrPrint(res);
            continue;
        }

        int x = n % (2 * k);
        vector<int> res(n);
        for (int i = 0; i + 4 * k <= n; i += 2 * k) {
            range(j, i, i + k) {
                res[j] = j + k;
            }
            range(j, i + k, i + 2 * k) {
                res[j] = j - k;
            }
        }

        int i = n - (2 * k + x);
        if (x < k) {
            range(j, i, i + k + x) {
                res[j] = j + k;
            }
            range(j, n - k, n) {
                res[j] = j - k - x;
            }
        }
        else {
            range(j, i, i + k) {
                res[j] = j + k;
            }
            range(j, i + k, i + x) {
                res[j] = j - k;
            }
            range(j, i + x, i + k + x) {
                res[j] = j + k;
            }
            range(j, i + k + x, i + 3 * k) {
                res[j] = j - 2 * k;
            }
            range(j, i + 3 * k, n) {
                res[j] = j - k;
            }
        }

        range(i, 0, n) {
            res[i]++;
        }
        arrPrint(res);

        range(i, 0, n) {
            assert(abs(res[i] - (i + 1)) >= k);
        }
        sort(res.begin(), res.end());
        range(i, 0, n) {
            assert(res[i] == i + 1);
        }
    }
}
