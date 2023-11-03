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

bool check(vector<int> b, int a[], int n) {
	range(i, 0, n - 1) {
		if ((b[i + 1] ^ b[i]) != a[i]) {
			return false;
		}
	}

	set<int> c(b.begin(), b.end());
	return (int) c.size() == n and c.lower_bound(n) == c.end();
}

// Assumed int size
#define INT_SIZE 32
 
// A Trie Node
struct TrieNode
{
    int value;  // Only used in leaf nodes
    TrieNode *arr[2];
};
 
// Utility function to create a Trie node
TrieNode *newNode()
{
    TrieNode *temp = new TrieNode;
    temp->value = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}
 
// Inserts pre_xor to trie with given root
void insert(TrieNode *root, int pre_xor)
{
    TrieNode *temp = root;
 
    // Start from the msb, insert all bits of
    // pre_xor into Trie
    for (int i=INT_SIZE-1; i>=0; i--)
    {
        // Find current bit in given prefix
        bool val = pre_xor & (1<<i);
 
        // Create a new node if needed
        if (temp->arr[val] == NULL)
            temp->arr[val] = newNode();
 
        temp = temp->arr[val];
    }
 
    // Store value at leaf node
    temp->value = pre_xor;
}
 
// Finds the maximum XOR ending with last number in
// prefix XOR 'pre_xor' and returns the XOR of this maximum
// with pre_xor which is maximum XOR ending with last element
// of pre_xor.
int query(TrieNode *root, int pre_xor)
{
    TrieNode *temp = root;
    for (int i=INT_SIZE-1; i>=0; i--)
    {
        // Find current bit in given prefix
        bool val = pre_xor & (1<<i);
 
        // Traverse Trie, first look for a
        // prefix that has opposite bit
        if (temp->arr[1-val]!=NULL)
            temp = temp->arr[1-val];
 
        // If there is no prefix with opposite
        // bit, then look for same bit.
        else if (temp->arr[val] != NULL)
            temp = temp->arr[val];
    }
    return pre_xor^(temp->value);
}
 
// Returns maximum XOR value of a subarray in arr[0..n-1]
int maxSubarrayXOR(int arr[], int n)
{
    // Create a Trie and insert 0 into it
    TrieNode *root = newNode();
    insert(root, 0);
 
    // Initialize answer and xor of current prefix
    int pre_xor = 0;
 
	vector<bool> res(n + 1, true);
    // Traverse all input array element
    for (int i = 0; i < n; i++) {
        // update current prefix xor and insert it into Trie
        pre_xor = pre_xor^arr[i];
        insert(root, pre_xor);

        // Query for current prefix xor in Trie and update
        // result if required
		if (query(root, pre_xor) > n) {
			res[i + 1] = false;
		}
    }

    // Traverse all input array element
	pre_xor = 0;
	TrieNode *root2 = newNode();
	insert(root2, 0);
    for (int i = n - 1; i >= 0; i--) {
        // update current prefix xor and insert it into Trie
        pre_xor = pre_xor^arr[i];
        insert(root2, pre_xor);
 
        // Query for current prefix xor in Trie and update
        // result if required
		if (query(root2, pre_xor) > n) {
			res[i] = false;
		}
    }

	range(i, 0, n + 1) {
		if (res[i]) {
			return i;
		}
	}

	map<int, int> m;
	m[0] = 0;
	pre_xor = 0;
	int l = 0, r = n;
	range(i, 0, n) {
		pre_xor ^= arr[i];
		if (m.count(pre_xor)) {
			l = max(l, m[pre_xor] + 1);
			r = min(r, (int) i);
		}
		m[pre_xor] = i + 1;
	}

	range(i, l, r + 1) {
		if (res[i]) {
			return i;
		}
	}

    return -1;
}

int32_t main() {
	setup();

	int n;
	input(n);

	int a[n - 1];
	arrPut(a);

	int u = maxSubarrayXOR(a, n - 1);
	if (u == -1) {
		return 0;
	}
	vector<int> res(n);
	res[u] = 0;
	range(i, u + 1, n) {
		res[i] = res[i - 1] ^ a[i - 1];
	}
	for (int i = u - 1; i >= 0; i--) {
		res[i] = res[i + 1] ^ a[i];
	}
	// print(u);
	assert(check(res, a, n));
	arrPrint(res);
}
