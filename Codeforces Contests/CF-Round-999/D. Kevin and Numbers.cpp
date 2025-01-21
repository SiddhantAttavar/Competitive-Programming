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
        int n, m;
        input(n, m);

        vector<int> a(n);
        arrput(a);

        vector<int> b(m);
        arrput(b);

        map<int, int> s;
        for (int i : a) {
            s[i]++;
        }
        map<int, int> t;
        for (int i : b) {
            t[i]++;
        }
        bool flag = true;
        while (!t.empty()) {
            int x, f;
            tie(x, f) = *t.begin();
            while (s.count(x) and f and s[x]) {
                s[x]--;
                f--;
            }
            if (s.count(x) and !s[x]) {
                s.erase(x);
            }
            if (f) {
                if (x == 1) {
                    flag = false;
                    break;
                }
                int y = x / 2, z = x - x / 2;
                t[y] += f;
                t[z] += f;
            }
            t.erase(x);
        }


        if (flag and s.empty()) {
            print("Yes");
        }
        else {
            print("No");
        }
    }
}
