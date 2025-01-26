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

const int N = 1e9;
struct Node {
	int x, y;
	Node *l, *r;
	Node(int _x, int _y) : x(_x), y(_y), l(nullptr), r(nullptr) {}
	Node(Node* _l, Node* _r) : l(_l), r(_r) {
		x = 0, y = 0;
		if(l) x += l->x, y += l->y;
		if(r) x += r->x, y += r->y;
	}
	Node(Node *v) : x(v->x), y(v->y), l(v->l), r(v->r) {}
};
Node* root;
Node* update(Node* node, int l, int r, int pos, pair<int, int> val) {
	if(l == r) return new Node(val.first, val.second);
	int m = (l + r)/2;
	if(pos <= m) return new Node(update(node->l, l, m, pos, val), node->r);
	return new Node(node->l, update(node->r, m + 1, r, pos, val));
}
pair<int, int> cmb(pair<int, int> a, pair<int, int> b) {
    return {a.first + a.second, b.first + b.second};
}
pair<int, int> query(Node* node, int l, int r, int ql, int qr) {
    if (node == nullptr) return {0, 0};
	if(qr < l || ql > r) return {0, 0};
	if(ql <= l && qr >= r) return {node->x, node->y};
	int m = (l + r)/2;
	return cmb(query(node->l, l, m, ql, qr), query(node->r, m + 1, r, ql, qr));
}

int dfs(int u, int p, vector<vector<int>> &graph, vector<int> &l) {
    pair<int, int> x = query(root, 1, N, 0, l[u]);
    int res = x.second * l[u] - x.first;
    update(root, 1, N, l[u], cmb(query(root, 1, N, l[u], l[u]), make_pair(l[u], 1)));
    for (int v : graph[u]) {
        if (v == p) {
            continue;
        }

        res += dfs(v, u, graph, l);
    }
    update(root, 1, N, l[u], cmb(query(root, 1, N, l[u], l[u]), make_pair(-l[u], -1)));
    return res;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        root = (Node*) malloc(sizeof(Node));
        root->x = 0;
        root->y = 0;
        root->l = nullptr;
        root->r = nullptr;

        int n;
        input(n);

        vector<int> l(n), r(n);
        range(i, 0, n) {
            input(l[i], r[i]);
        }

        vector<vector<int>> graph(n);
        range(i, 0, n - 1) {
            int u, v;
            input(u, v);

            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }

        print(dfs(0, -1, graph, l));
    }
}
