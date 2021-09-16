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

vector<vi> origGraph;
vector<set<int>> graph;
vector<vector<pair<int, int>>> q;
vector<vector<bool>> out;

bool dfs(int u, int w, int d) {
    if (q[w][u].first != -1 and (d < q[w][u].first or q[w][u].second < d)) {
        return false;
    }

    for (int v : origGraph[u]) {
        if (!dfs(v, w, d + (graph[u].find(v) != graph[u].end()))) {
            return false;
        }
    }

    return true;
}

int main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, m;
        input(n, m);

        origGraph.clear();
        origGraph.resize(n);

        vector<pair<int, int>> edges;
        range(i, 1, n) {
            int p; input(p);
            edges.push_back({p - 1, i});
            origGraph[p - 1].push_back(i);
        }

        q.clear();
        q.resize(n, vector<pair<int, int>>(n, {-1, -1}));
        range(i, 0, m) {
            int u, v, l, r;
            input(u, v, l, r);
            if (q[u - 1][v - 1].first == -1) {
                q[u - 1][v - 1] = {l, r};
            }
            else {
                q[u - 1][v - 1].first = max(q[u - 1][v - 1].first, l);
                q[u - 1][v - 1].second = min(q[u - 1][v - 1].second, r);
            }
        }

        bool res = false;
        range(i, 0, (1 << int(edges.size()))) {
            //graph = vector<set<int>>(n);
            graph.clear();
            graph.resize(n);

            range(j, 0, int(edges.size())) {
                if (i & (1 << j)) {
                    graph[edges[j].first].insert(edges[j].second);
                }
            }

            bool flag = true;
            range(i, 0, n) {
                if (!dfs(i, i, 0)) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                res = true;
                vector<int> fin;
                range(i, 0, n) {
                    for (int j : graph[i]) {
                        fin.push_back(j + 1);
                    }
                }
                print(fin.size());
                arrPrint(fin);
                break;
            }
        }

        if (!res) {
            print(-1);
        }
    }
}