#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<pair<int, pair<int, int>>> &tree, string &s) {
    s += '(';
    if (tree[u].second.first != -1) {
        dfs(tree[u].second.first, tree, s);
    }
    s += ',';
    if (tree[u].second.second != -1) {
        dfs(tree[u].second.second, tree, s);
    }
    s += ')';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int k;
    cin >> k;

    set<string> res;
    for (int i = 0; i < n; i++) {
        vector<pair<int, pair<int, int>>> tree;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;

            int u = 0, p = -1;
            while (u != -1 and u < tree.size()) {
                p = u;
                if (x < tree[u].first) {
                    u = tree[u].second.first;
                }
                else {
                    u = tree[u].second.second;
                }
            }

            tree.push_back({x, {-1, -1}});
            if (p != -1) {
                if (x < tree[p].first) {
                    tree[p].second.first = tree.size() - 1;
                }
                else {
                    tree[p].second.second = tree.size() - 1;
                }
            }
        }

        string s;
        dfs(0, tree, s);
        res.insert(s);
    }

    cout << res.size() << endl;
}
