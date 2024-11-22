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
    int n, u;
    input(n, u);

    vector<map<int, vector<int>>> v(n + 1);
    range(i, 0, u) {
        int a, b;
        input(a, b);
        b--;
        v[a][b % a].push_back(b);
    }

    vector<int> res(n + 1, 0);
    range(a, 1, n + 1) {
        for (pair<int, vector<int>> p : v[a]) {
            sort(p.second.begin(), p.second.end());
            p.second.push_back(n);
            int j = p.first, x = 0;
            for (int b : p.second) {
                while ((j + a) <= b) {
                    j += a;
                    res[j] += x;
                }
                x++;
                res[b]++;
            }
        }
    }

    res.pop_back();
    arrPrint(res);
}
