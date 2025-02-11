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

int query(int i, int j) {
    print('?', i + 1, j + 1);
    cout.flush();
    int x;
    input(x);
    return x;
}

int32_t main() {
    int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> x(n);
        arrput(x);

        vector<int> a(n, false);
        for (int i : x) {
            a[i - 1] = true;
        }

        bool flag = false;
        range(i, 0, n) {
            if (a[i]) {
                continue;
            }

            flag = true;
            if (query(i, i == 0 ? 1 : 0) == 0) {
                print("! A");
            }
            else {
                print("! B");
            }
            cout.flush();
            break;
        }

        if (flag) {
            continue;
        }

        int l = min_element(x.begin(), x.end()) - x.begin();
        int r = max_element(x.begin(), x.end()) - x.begin();

        if (query(l, r) + query(r, l) >= 2 * (n - 1)) {
            print("! B");
        }
        else {
            print("! A");
        }
        cout.flush();
    }
}
