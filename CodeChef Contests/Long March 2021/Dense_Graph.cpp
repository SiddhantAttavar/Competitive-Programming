<<<<<<< HEAD
#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;

		if (x == y) {
			print(0);
			continue;
		}

		pair<int, int> a[m], b[m];
		range(i, 0, m) {
			input(a[i].first);
			input(a[i].second);
			
			input(b[i].first);
			input(b[i].second);
		}

		int dist[m];
		fill(dist, dist + m, -1);
		queue<int> q;
		range(i, 0, m) {
			if (a[i].first <= x && x <= a[i].second) {
				dist[i] = 1;
				q.push(i);
			}
		}

		int res = -1;
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			if (b[u].first <= y && y <= b[u].second) {
				res = dist[u];
				break;
			}

			range(v, 0, m) {
				if (dist[v] == -1 && b[u].first <= a[v].second && b[u].second >= a[v].first) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}

		print(res);
	}
=======
#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;

		if (x == y) {
			print(0);
			continue;
		}

		pair<int, int> a[m], b[m];
		range(i, 0, m) {
			input(a[i].first);
			input(a[i].second);
			
			input(b[i].first);
			input(b[i].second);
		}

		int dist[m];
		fill(dist, dist + m, -1);
		queue<int> q;
		range(i, 0, m) {
			if (a[i].first <= x && x <= a[i].second) {
				dist[i] = 1;
				q.push(i);
			}
		}

		int res = -1;
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			if (b[u].first <= y && y <= b[u].second) {
				res = dist[u];
				break;
			}

			range(v, 0, m) {
				if (dist[v] == -1 && b[u].first <= a[v].second && b[u].second >= a[v].first) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}

		print(res);
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}