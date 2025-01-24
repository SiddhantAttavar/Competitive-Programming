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
    int n, k;
    input(n, k);

    int a, b, c;
    print("or", 1, 2);
    cout.flush();
    input(a);
    print("or", 2, 3);
    cout.flush();
    input(b);
    print("or", 3, 1);
    cout.flush();
    input(c);

    int x, y, z;
    print("and", 1, 2);
    cout.flush();
    input(x);
    print("and", 2, 3);
    cout.flush();
    input(y);
    print("and", 3, 1);
    cout.flush();
    input(z);

    vector<int> d(n, 0);
    for (int j = 29; j >= 0; j--) {
        if (((1 << j) & (a ^ x)) == 0) {
            d[0] |= (1 << j) & a;
            d[1] |= (1 << j) & a;
            d[2] |= (1 << j) & (a ^ c ^ z);
        }
        else if (((1 << j) & (b ^ y)) == 0) {
            d[1] |= (1 << j) & b;
            d[2] |= (1 << j) & b;
            d[0] |= (1 << j) & (b ^ a ^ x);
        }
        else {
            d[2] |= (1 << j) & c;
            d[0] |= (1 << j) & c;
            d[1] |= (1 << j) & (c ^ b ^ y);
        }
    }

    range(i, 3, n) {
        int u, v;
        print("or", 1, i + 1);
        cout.flush();
        input(u);
        print("and", 1, i + 1);
        cout.flush();
        input(v);
        d[i] = d[0] ^ u ^ v;
    }
    sort(d.begin(), d.end());
    print("finish", d[k - 1]);
}
