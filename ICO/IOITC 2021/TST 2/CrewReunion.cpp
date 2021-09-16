#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef vector<int> vi;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, m, k;
map<pair<vi, int>, vi> nextStep;
map<vi, bool> memo;
vi moves;

bool solve(vi sub) {
    if (moves.size() > n * n * n) {
        return memo[sub] = false;
    }

    if (memo.find(sub) != memo.end()) {
        return memo[sub];
    }

    if (sub.size() == 1) {
        print("YES");
        cout << moves.size() << ' ';
        arrPrint(moves);
        return memo[sub] = true;
    }

    memo[sub] = false;
    range(i, 0, k) {
        moves.push_back(i + 1);
        if (solve(nextStep[{sub, i}])) {
            return memo[sub] = true;
        }
        moves.pop_back();
    }

    return memo[sub] = false;
}

int main() {
    setup(); int tc; input(tc); while (tc--) {
        input(n, m, k);

        nextStep.clear();
        memo.clear();
        moves.clear();

        int graph[n][k];
        range(i, 0, n) {
            fill(graph[i], graph[i] + k, i);
        }

        range(i, 0, m) {
            int u, v, w;
            input(u, v, w);
            graph[u - 1][w - 1] = v - 1;
        }

        range(i, 0, (1 << n)) {
            vi sub;
            range(j, 0, n) {
                if (i & (1 << j)) {
                    sub.push_back(j);
                }
            }

            range(j, 0, k) {
                set<int> res;
                for (int l : sub) {
                    res.insert(graph[l][j]);
                }
                nextStep[{sub, j}] = vi(res.begin(), res.end());
            }
        }

        vi start(n);
        range(i, 0, n) {
            start[i] = i;
        }
        if (!solve(start)) {
            print("NO");
        }
    }
}