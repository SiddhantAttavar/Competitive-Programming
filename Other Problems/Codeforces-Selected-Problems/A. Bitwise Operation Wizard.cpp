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

char query(int a, int b, int c, int d) {
    print('?', a, b, c, d);
    cout.flush();
    char x;
    input(x);
    return x;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n;
        input(n);

        int u = 0;
        range(i, 1, n) {
            if (query(i, i, u, u) == '>') {
                u = i;
            }
        }

        vector<int> v = {0};
        range(i, 1, n) {
            char c = query(u, i, u, v.back());
            if (c == '>') {
                v = {i};
            }
            else if (c == '=') {
                v.push_back(i);
            }
        }

        int w = v[0];
        range(i, 1, v.size()) {
            if (query(w, w, v[i], v[i]) == '>') {
                w = v[i];
            }
        }

        print('!', u, w);
        cout.flush();
    }
}
