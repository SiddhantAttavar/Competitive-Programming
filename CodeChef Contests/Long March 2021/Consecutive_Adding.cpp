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

int r, c, x;
vector<vector<ll>> a, b, p, q;

void solve(vector<ll> &a, vector<ll> &b) {
	int n = a.size();

	ll prefSum[n + 1] = {0};
	range(i, 0, n) {
		//The last min(i, x) numbers have to be added
		ll sum = prefSum[i] - prefSum[max(0, i - x + 1)];
		a[i] += sum;

		//The difference to be added is b[i] - a[i]
		prefSum[i + 1] = prefSum[i] + b[i] - a[i];
	}
}

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		//Input
		input(r);
		input(c);
		input(x);

		//Matrix Input
		a = vector<vector<ll>>(r, vector<ll>(c));
		b = vector<vector<ll>>(r, vector<ll>(c));

		range(j, 0, r) {
			arrPut(a[j]);
		}
		range(j, 0, r) {
			arrPut(b[j]);
		}

		//We have to call solve on all the rows
		p = vector<vector<ll>>(x - 1, vector<ll>(r));
		q = vector<vector<ll>>(x - 1, vector<ll>(r));
		range(i, 0, r) {
			solve(a[i], b[i]);
			//The last x - 1 columns haven't been fixed
			//Add them to the fin seperate array
			range(j, 0, x - 1) {
				p[j][i] = a[i][c - x + j + 1];
				q[j][i] = b[i][c - x + j + 1];
			}
		}

		bool flag = true;
		range(i, 0, x - 1) {
			solve(p[i], q[i]);
			//Check the last x - 1 numbers of the column
			range(j, 0, x - 1) {
				if (p[i][r - x + j + 1] != q[i][r - x + j + 1]) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				break;
			}
		}

		print((flag ? "Yes" : "No"));
	}
}