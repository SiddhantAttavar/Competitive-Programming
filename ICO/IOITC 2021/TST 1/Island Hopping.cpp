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

int main() {
    setup(); int tc; input(tc); while (tc--) {
        vector<vector<int>> res, dist;
        vector<vector<bool>> grid;
        int n, xa, ya;

        input(n);

        grid.resize(n, vector<bool>(n));
        range(i, 0, n) {
            string s; input(s);
            range(j, 0, n) {
                grid[i][j] = s[j] == '1';
            }
        }

        input(xa, ya);

        res.resize(n, vector<int>(n, 0));
        dist.resize(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        q.push({xa - 1, ya - 1});
        dist[xa - 1][ya - 1] = 0;
        int k = 0;
        while (!q.empty()) {
            k++;
            int x, y;
            tie(x, y) = q.front();
            q.pop();

            if (x > 0) {
                if (dist[x][y] < dist[x - 1][y]) {
                    res[x - 1][y] = max(res[x - 1][y], res[x][y] + grid[x - 1][y]);
                }
                if (dist[x - 1][y] == INT_MAX) {
                    dist[x - 1][y] = dist[x][y] + 1;
                    q.push({x - 1, y});
                }
            }
            if (x < n - 1) {
                if (dist[x][y] < dist[x + 1][y]) {
                    res[x + 1][y] = max(res[x + 1][y], res[x][y] + grid[x + 1][y]);
                }
                if (dist[x + 1][y] == INT_MAX) {
                    dist[x + 1][y] = dist[x][y] + 1;
                    q.push({x + 1, y});
                }
            }
            if (y > 0) {
                if (dist[x][y] < dist[x][y - 1]) {
                    res[x][y - 1] = max(res[x][y - 1], res[x][y] + grid[x][y - 1]);
                }
                if (dist[x][y - 1] == INT_MAX) {
                    dist[x][y - 1] = dist[x][y] + 1;
                    q.push({x, y - 1});
                }
            }
            if (y < n - 1) {
                if (dist[x][y] < dist[x][y + 1]) {
                    res[x][y + 1] = max(res[x][y + 1], res[x][y] + grid[x][y + 1]);
                }
                if (dist[x][y + 1] == INT_MAX) {
                    dist[x][y + 1] = dist[x][y] + 1;
                    q.push({x, y + 1});
                }
            }
        }

        range(i, 0, n) {
            range(j, 0, n) {
                res[i][j] *= grid[i][j];
            }
        }

        range(i, 0, n) {
            arrPrint(res[i]);
        }
    }
}