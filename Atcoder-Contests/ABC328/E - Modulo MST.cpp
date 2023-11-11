#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

void dfs(int u, vector<int> graph[], bool vis[]) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis);
		}
	}
}

int subsets[(int) 2e6][7];
int t = 0;

void combinationUtil(int arr[], int n, int r,
                     int index, int data[], int i);
  
// The main function that prints all combinations of 
// size r in arr[] of size n. This function mainly
// uses combinationUtil()
void printCombination(int arr[], int n, int r)
{
   
    // A temporary array to store all combination
    // one by one
    int data[r];
  
    // Print all combination using temporary array 'data[]'
    combinationUtil(arr, n, r, 0, data, 0);
}
  
/* arr[]  ---> Input Array
   n      ---> Size of input array
   r      ---> Size of a combination to be printed
   index  ---> Current index in data[]
   data[] ---> Temporary array to store current combination
   i      ---> index of current element in arr[]     */
void combinationUtil(int arr[], int n, int r, int index,
                     int data[], int i)
{
    // Current combination is ready, print it
    if (index == r) {
		copy(data, data + r, subsets[t]);
		t++;
        return;
    }
  
    // When no more elements are there to put in data[]
    if (i >= n)
        return;
  
    // current is included, put next at next location
    data[index] = arr[i];
    combinationUtil(arr, n, r, index + 1, data, i + 1);
  
    // current is excluded, replace it with next
    // (Note that i+1 is passed, but index is not
    // changed)
    combinationUtil(arr, n, r, index, data, i + 1);
}

int32_t main() {
	setup();

	int n, m, k;
	input(n, m, k);

	vector<pair<int, pair<int, int>>> e(m);
	range(i, 0, m) {
		int u, v, w;
		input(u, v, w);
		e[i] = {w % k, {u - 1, v - 1}};
	}

	int res = 1e18;
	int a[m];
	range(i, 0, m) {
		a[i] = i;
	}
	printCombination(a, m, n - 1);
	// print(t);
	range(i, 0, t) {
		// arrPrint(subsets[i]);
		vector<int> graph[n];
		int c = 0;
		range(j, 0, n - 1) {
			graph[e[subsets[i][j]].second.first].push_back(e[subsets[i][j]].second.second);
			graph[e[subsets[i][j]].second.second].push_back(e[subsets[i][j]].second.first);
			c = (c + e[subsets[i][j]].first) % k;
		}

		if (c >= res) {
			continue;
		}

		bool vis[n];
		fill(vis, vis + n, false);
		dfs(0, graph, vis);

		bool flag = true;
		for (bool b : vis) {
			if (!b) {
				flag = false;
				break;
			}
		}

		if (flag) {
			res = c;
		}
	}

	print(res);
}
