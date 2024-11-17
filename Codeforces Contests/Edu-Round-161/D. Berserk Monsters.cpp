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
        int n;
        input(n);

        vector<int> a(n), d(n);
        arrPut(a);
        arrPut(d);

        a.insert(a.begin(), 0);
        d.insert(d.begin(), 1e18);
        a.push_back(0);
        d.push_back(1e18);

        vector<int> l(n + 2), r(n + 2);
        range(i, 0, n + 2) {
            l[i] = i - 1;
            r[i] = i + 1;
        }

        vector<int> s;
        range(i, 1, n + 1) {
            if (d[i] < a[l[i]] + a[r[i]]) {
                s.push_back(i);
            }
        }

        range(i, 0, n) {
            cout << s.size() << ' ';

            set<int> t;
            for (int i : s) {
                t.insert(l[i]);
                t.insert(r[i]);
                r[l[i]] = r[i];
                l[r[i]] = l[i];
            }

            for (int i : s) {
                t.erase(i);
            }

            if (t.count(0)) {
                t.erase(0);
            }
            if (t.count(n + 1)) {
                t.erase(n + 1);
            }

            vector<int> v;
            for (int i : t) {
                if (d[i] < a[l[i]] + a[r[i]]) {
                    v.push_back(i);
                }
            }
            s = v;
        }
        cout << endl;
    }
}
