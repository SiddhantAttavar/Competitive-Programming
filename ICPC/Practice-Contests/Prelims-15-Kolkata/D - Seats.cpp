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
    setup();
    int n, q;
    input(n, q);

    vector<int> l;
    map<int, set<int>> d;
    set<int> s;
    int t = 0;
    while (q--) {
        int o;
        input(o);

        if (o == 1) {
            // for (pair<int, set<int>> p : d) {
            //     cout << p.first << ": ";
            //     arrPrint(p.second);
            // }
            if (s.empty()) {
                l.push_back(1);
                d[n - 1].insert(1);
                s.insert(1);
                print(1);
                continue;
            }

            int y = *s.begin() - 1;
            int z = n - *s.rbegin();
            int x = d.rbegin()->first;
            // print(y, x, z);

            if (y / 2 >= x / 2 and y / 2 >= z / 2) {
                l.push_back(1);
                d[y].insert(1);
                s.insert(1);
                print(1);
                continue;
            }

            if (z / 2 > x / 2 or (z / 2 == x / 2 and d[z].size() == 1)) {
                l.push_back(n);
                int i = n - z;
                d[z].erase(i);
                if (d[z].empty()) {
                    d.erase(z);
                }
                d[z - 1].insert(i);
                d[0].insert(n);
                s.insert(n);
                print(n);
                continue;
            }

            set<int> s = d[x];
            int i = *d[x].begin(), j = i + (x + 1) / 2;
            if (x % 2 == 0 and d.count(x - 1) and i > *d[x - 1].begin()) {
                i = *d[x - 1].begin();
                j = i + (x + 1) / 2;
            }
            // print(i, x, j);
            l.push_back(j);
            d[x].erase(i);
            if (d[x].empty()) {
                d.erase(x);
            }
            d[j - i - 1].insert(i);
            d[x / 2].insert(j);
            s.insert(j);
            print(j);
        }
        else if (o == 2) {
            int i;
            input(i);
            i--;

            int x = l[i];
            // arrPrint(s);
            int p = 0, q = n + 1;
            if (s.upper_bound(x) != s.end()) {
                q = *s.upper_bound(x);
            }
            d[q - x - 1].erase(x);
            if (d[q - x - 1].empty()) {
                d.erase(q - x - 1);
            }

            s.erase(x);
            if (s.empty() or *s.begin() > x) {
                continue;
            }

            p = *prev(s.lower_bound(x));
            d[x - p - 1].erase(p);
            if (d[x - p - 1].empty()) {
                d.erase(x - p - 1);
            }
            d[q - p - 1].insert(p);
        }
    }
}
