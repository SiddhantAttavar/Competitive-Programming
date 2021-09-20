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

vector<vector<int>> graph;
vector<int> a;
vector<int> inverse;
int n, q;

int modPow(ll a, int b) {
	ll res = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
}

void dfs(int u, int p, int d, ll prob) {
	a[u] = (a[u] + prob) % MOD;
	
	prob = (prob * inverse[graph[u].size() - (p != -1)]) % MOD;
	if (d > 0) {
		for (int v : graph[u]) {
			if (v != p) {
				dfs(v, u, d - 1, prob);
			}
		}
	}
}

void subTask1() {
	graph.resize(n);
	a = vector<int>(n, 0);
	inverse = vector<int>(n);
	inverse[0] = 0;
	range(i, 1, n) {
		inverse[i] = modPow(i, MOD - 2);
	}
	
	range(i, 0, n - 1) {
		int u, v;
		input(u);
		input(v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	int last = 0;
	while (q--) {
		int op; input(op);
		int u; input(u);
		u = (last + u) % n;
		if (op == 1) {
			int d; input(d);
			dfs(u, -1, (last + d) % n + 1, 1);
		}
		else {
			print((last = a[u]));
		}
	}
}

// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree. The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree. 
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse all ancestors and add 'val' 
    while (index <= n) 
    { 
        // Add 'val' to current node of BI Tree 
        BITree[index] += val; 
  
        // Update index to that of parent in update View 
        index += index & (-index); 
    } 
} 
  
// Constructs and returns a Binary Indexed Tree for given 
// array of size n. 
int *constructBITree(int arr[], int n) 
{ 
    // Create and initialize BITree[] as 0 
    int *BITree = new int[n+1]; 
    for (int i=1; i<=n; i++) 
        BITree[i] = 0; 
  
    // Store the actual values in BITree[] using update() 
    for (int i=0; i<n; i++) 
        updateBIT(BITree, n, i, arr[i]); 
  
    // Uncomment below lines to see contents of BITree[] 
    //for (int i=1; i<=n; i++) 
    //      cout << BITree[i] << " "; 
  
    return BITree; 
} 
  
// SERVES THE PURPOSE OF getElement() 
// Returns sum of arr[0..index]. This function assumes 
// that the array is preprocessed and partial sums of 
// array elements are stored in BITree[] 
int getSum(int BITree[], int index) 
{ 
    int sum = 0; // Iniialize result 
  
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse ancestors of BITree[index] 
    while (index>0) 
    { 
        // Add current element of BITree to sum 
        sum += BITree[index]; 
  
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
// Updates such that getElement() gets an increased 
// value when queried from l to r. 
void update(int BITree[], int l, int r, int n, int val) 
{ 
    // Increase value at 'l' by 'val' 
    updateBIT(BITree, n, l, val); 
  
    // Decrease value at 'r+1' by 'val' 
    updateBIT(BITree, n, r+1, -val); 
}

void subTask2() {
	ll k = modPow(2, MOD - 2);
	vector<int> graph[n];
	range(i, 0, n - 1) {
		int u, v;
		input(u);
		input(v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	int a[n] = {0};
	int *bit = constructBITree(a, n);

	int prev = -1, curr;
	range(i, 0, n) {
		if (graph[i].size() == 1) {
			//This is an end
			curr = i;
			break;
		}
	}

	int ind[n];
	range(i, 0, n) {
		ind[curr] = i;
		for (int j : graph[curr]) {
			if (j != prev) {
				prev = curr;
				curr = j;
				break;
			}
		}
	}

	int last = 0;
	while (q--) {
		int op; input(op);
		int a; input(a);
		int u = (last + a) % n;
		u = ind[u];
		if (op == 1) {
			int b; input(b);
			int d = (last + b) % n + 1;
			if ((u == 0) || (u == n - 1)) {
				update(bit, max(0, u - d), min(n - 1, u + d), n, 2);
			}
			else {
				update(bit, max(0, u - d), min(n - 1, u + d), n, 1);
				update(bit, u, u, n, 1);
			}
		}
		else {
			last = (getSum(bit, u) * k) % MOD;
			print(last);
		}
	}
}

int main() {
	setup();
	input(n);
	input(q);

	if (n <= 5e4) {
		subTask1();
	}
	else {
		subTask2();
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

vector<vector<int>> graph;
vector<int> a;
vector<int> inverse;
int n, q;

int modPow(ll a, int b) {
	ll res = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
}

void dfs(int u, int p, int d, ll prob) {
	a[u] = (a[u] + prob) % MOD;
	
	prob = (prob * inverse[graph[u].size() - (p != -1)]) % MOD;
	if (d > 0) {
		for (int v : graph[u]) {
			if (v != p) {
				dfs(v, u, d - 1, prob);
			}
		}
	}
}

void subTask1() {
	graph.resize(n);
	a = vector<int>(n, 0);
	inverse = vector<int>(n);
	inverse[0] = 0;
	range(i, 1, n) {
		inverse[i] = modPow(i, MOD - 2);
	}
	
	range(i, 0, n - 1) {
		int u, v;
		input(u);
		input(v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	int last = 0;
	while (q--) {
		int op; input(op);
		int u; input(u);
		u = (last + u) % n;
		if (op == 1) {
			int d; input(d);
			dfs(u, -1, (last + d) % n + 1, 1);
		}
		else {
			print((last = a[u]));
		}
	}
}

// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree. The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree. 
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse all ancestors and add 'val' 
    while (index <= n) 
    { 
        // Add 'val' to current node of BI Tree 
        BITree[index] += val; 
  
        // Update index to that of parent in update View 
        index += index & (-index); 
    } 
} 
  
// Constructs and returns a Binary Indexed Tree for given 
// array of size n. 
int *constructBITree(int arr[], int n) 
{ 
    // Create and initialize BITree[] as 0 
    int *BITree = new int[n+1]; 
    for (int i=1; i<=n; i++) 
        BITree[i] = 0; 
  
    // Store the actual values in BITree[] using update() 
    for (int i=0; i<n; i++) 
        updateBIT(BITree, n, i, arr[i]); 
  
    // Uncomment below lines to see contents of BITree[] 
    //for (int i=1; i<=n; i++) 
    //      cout << BITree[i] << " "; 
  
    return BITree; 
} 
  
// SERVES THE PURPOSE OF getElement() 
// Returns sum of arr[0..index]. This function assumes 
// that the array is preprocessed and partial sums of 
// array elements are stored in BITree[] 
int getSum(int BITree[], int index) 
{ 
    int sum = 0; // Iniialize result 
  
    // index in BITree[] is 1 more than the index in arr[] 
    index = index + 1; 
  
    // Traverse ancestors of BITree[index] 
    while (index>0) 
    { 
        // Add current element of BITree to sum 
        sum += BITree[index]; 
  
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
// Updates such that getElement() gets an increased 
// value when queried from l to r. 
void update(int BITree[], int l, int r, int n, int val) 
{ 
    // Increase value at 'l' by 'val' 
    updateBIT(BITree, n, l, val); 
  
    // Decrease value at 'r+1' by 'val' 
    updateBIT(BITree, n, r+1, -val); 
}

void subTask2() {
	ll k = modPow(2, MOD - 2);
	vector<int> graph[n];
	range(i, 0, n - 1) {
		int u, v;
		input(u);
		input(v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	int a[n] = {0};
	int *bit = constructBITree(a, n);

	int prev = -1, curr;
	range(i, 0, n) {
		if (graph[i].size() == 1) {
			//This is an end
			curr = i;
			break;
		}
	}

	int ind[n];
	range(i, 0, n) {
		ind[curr] = i;
		for (int j : graph[curr]) {
			if (j != prev) {
				prev = curr;
				curr = j;
				break;
			}
		}
	}

	int last = 0;
	while (q--) {
		int op; input(op);
		int a; input(a);
		int u = (last + a) % n;
		u = ind[u];
		if (op == 1) {
			int b; input(b);
			int d = (last + b) % n + 1;
			if ((u == 0) || (u == n - 1)) {
				update(bit, max(0, u - d), min(n - 1, u + d), n, 2);
			}
			else {
				update(bit, max(0, u - d), min(n - 1, u + d), n, 1);
				update(bit, u, u, n, 1);
			}
		}
		else {
			last = (getSum(bit, u) * k) % MOD;
			print(last);
		}
	}
}

int main() {
	setup();
	input(n);
	input(q);

	if (n <= 5e4) {
		subTask1();
	}
	else {
		subTask2();
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}