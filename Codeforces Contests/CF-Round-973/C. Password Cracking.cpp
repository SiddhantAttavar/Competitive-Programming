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

bool query(string s) {
    print('?', s);
    cout.flush();
    int x;
    input(x);
    return x;
}

int32_t main() {
    int tc; input(tc); while (tc--) {
        int n;
        input(n);

        if (!query("0")) {
            print('!', string(n, '1'));
            cout.flush();
            continue;
        }

        string res = "0";
        while (res.size() < n) {
            if (query(res + '0')) {
                res += '0';
            }
            else if (query(res + '1')) {
                res += '1';
            }
            else {
                break;
            }
        }
        res = string(n - res.size(), '1') + res;

        print('!', res);
        cout.flush();
    }
}
