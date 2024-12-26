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

int query(int i, int j) {
    print('?', i + 1, j + 1);
    cout.flush();
    int x;
    input(x);
    assert(x != -1);
    return x;
}

int32_t main() {
    int tc; input(tc); while (tc--) {
        int n;
        input(n);
        assert(n != -1);

        int res = n - 1;
        for (int i = 0; i + 2 <= n; i += 2) {
            if (i + 5 == n) {
                int a = query(i, i + 1), b = query(i + 1, i + 2), c = query(i + 2, i);
                if (a ^ b ^ c == 0) {
                    int d = query(i, i + 2), e = query(i + 1, i);
                    if (a == e) {
                        res = i + 2;
                    }
                    else if (b == d) {
                        res = i + !a;
                    }
                    else {
                        res = i + a;
                    }
                }
                else {
                    if (query(i, i + 3) == query(i + 3, i)) {
                        res = i + 4;
                    }
                    else {
                        res = i + 3;
                    }
                }
                break;
            }

            int a = query(i, i + 1), b = query(i + 1, i);
            if (i + 4 == n) {
                int c = query(i + 1, i + 2), d = query(i + 2, i + 1);
                if (a == b and c == d) {
                    break;
                }
                if (a == b) {
                    res = i + 2;
                    break;
                }
                if (c == d) {
                    res = i;
                    break;
                }
                res = i + 1;
                break;
            }

            if (a == b) {
                continue;
            }

            int k = (i + 2) % n;
            res = i + (a ^ ((query(i, k) == query(i + 1, k))));
            break;
        }
        print('!', res + 1);
        cout.flush();
    }
}
