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

int query(int i) {
    print('?', i + 1);
    cout.flush();
    int x;
    input(x);
    return x - 1;
}

int32_t main() {
    int tc; input(tc); while (tc--) {
        int n;
        input(n);

        vector<int> res(n, -1);
        range(i, 0, n) {
            if (res[i] != -1) {
                continue;
            }

            int x = query(i);
            vector<int> v = {query(i)};
            while (x != v.back()) {
                v.push_back(query(i));
            }

            range(j, 0, v.size()) {
                res[v[j]] = v[(j + 1) % v.size()] + 1;
            }
        }

        cout << "! ";
        arrprint(res);
        cout.flush();
    }
}
