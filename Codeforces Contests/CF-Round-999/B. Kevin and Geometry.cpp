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

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> a(n);
        arrput(a);

        map<int, int> m;
        for (int i : a) {
            m[i]++;
        }
        m[-1e9] = 1;
        m[1e9] = 1;

        vector<int> v;
        for (pair<int, int> p : m) {
            if (p.second >= 2) {
                v.push_back(p.first);
            }
        }

        if (v.size() == 2) {
            print(v[0], v[0], v[1], v[1]);
            continue;
        }
        if (v.size() == 0) {
            print(-1);
            continue;
        }

        int u = v[0];
        int l = 0;
        while (a[l] != u) {
            l++;
        }
        a.erase(a.begin() + l);
        while (a[l] != u) {
            l++;
        }
        a.erase(a.begin() + l);

        sort(a.begin(), a.end());
        bool flag = false;
        range(i, 1, n - 2) {
            if (a[i] - a[i - 1] < 2 * u) {
                print(u, u, a[i - 1], a[i]);
                flag = true;
                break;
            }
        }
        if (!flag) {
            print(-1);
        }
    }
}
