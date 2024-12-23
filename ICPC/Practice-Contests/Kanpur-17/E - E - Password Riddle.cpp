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

map<string, int> m = {
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9}
};

const int N = 600000;
const int H = 20;
bool dp[N + 1][H][H];

bool match(vector<string> &a, pair<int, int> p) {
    if (a.back() == "odd" and p.first % 2 == 0) {
        return false;
    }
    else if (a.back() == "even" and p.first % 2 == 1) {
        return false;
    }
    else if (m.count(a.back()) and p.first != m[a.back()]) {
        return false;
    }
    a.pop_back();

    int z = 1, o = 0, e = 0;
    for (string s : a) {
        if (s == "odd") {
            o++;
        }
        else if (s == "even") {
            e++;
        }
        else {
            z *= m[s];
        }
    }

    if (z == 0) {
        return p.second == 0;
    }

    if (p.second % z) {
        return false;
    }
    p.second /= z;

    if (p.second == 0) {
        return e > 0;
    }

    if (p.second == 1) {
        return e == 0;
    }

    if (e >= H) {
        return false;
    }
    return dp[p.second][min(o, H - 1)][e];
}

int32_t main() {
    vector<int> v = {3, 5, 7, 9}, w = {2, 4, 6, 8};
    dp[1][0][0] = true;
    range(o, 0, H) {
        range(e, 0, H) {
            range(i, 1, N + 1) {
                if (!dp[i][o][e]) {
                    continue;
                }

                if (o < H - 1) {
                    dp[i][o + 1][e] = true;
                    for (int j : v) {
                        if (i * j <= N) {
                            dp[i * j][o + 1][e] = true;
                        }
                    }
                }
                if (e < H - 1) {
                    for (int j : w) {
                        if (i * j <= N) {
                            dp[i * j][o][e + 1] = true;
                        }
                    }
                }
            }
        }
    }

    setup(); int tc; input(tc); range(t, 1, tc + 1) {
        cout << "Case " << t << ": ";
        vector<vector<string>> a = {{}};
        while (true) {
            string s;
            input(s);

            string t = s;
            if (t.back() == ',' or t.back() == '.') {
                t.pop_back();
            }
            a.back().push_back(t);

            if (s.back() == ',') {
                a.push_back({});
            }

            if (s.back() == '.') {
                break;
            }
        }

        int n;
        input(n);

        string s;
        input(s);

        vector<pair<int, int>> v = {{s[0] - '0', 1}};
        range(i, 1, n) {
            if (s[i] == s[i - 1]) {
                v.back().second++;
            }
            else {
                v.push_back({s[i] - '0', 1});
            }
        }

        int l = 0;
        bool res = true;
        for (pair<int, int> p : v) {
            while (l < a.size() and !match(a[l], p)) {
                l++;
            }
            if (l == a.size()) {
                res = false;
                break;
            }
            l++;
        }

        if (res) {
            print("MAY BE");
        }
        else {
            print("NO");
        }
    }
}
