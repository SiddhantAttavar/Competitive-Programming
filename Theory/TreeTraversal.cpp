#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

//Tree stored as an adjacency list
vector<vector<int>> tree;
vector<int> levels;
vector<int> subTreeSize;

//DFS Traversal
int dfs(int p, int u) {
    printf("%d ", u + 1);

    //Calculating level from root
    if (p == -1) {
        levels[u] = 1;
    }
    else {
        levels[u] = levels[p] + 1;
    }

    //Initializing Subtree Size
    subTreeSize[u] = 1;

    //Iterate through neighbours
    for (int v: tree[u]) {
        if (v != p) {
            //Perform DFS recursively
            subTreeSize[u] += dfs(u, v);
        }
    }

    return subTreeSize[u];
}

int main() {
    //Input
    input(int, n);

    //Initializing Arrays
    tree = vector<vector<int>>(n);
    levels = vector<int>(n);
    subTreeSize = vector<int>(n);
    
    range(i, 0, n - 1) {
        input(int, u);
        input(int, v);

        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    printf("DFS: ");
    dfs(-1, 0);
    println("");
    
    printf("Levels: ");
    for (int i: levels) {
        printf("%d ", i);
    }
    println("");

    printf("Subtree Size: ");
    for (int i: subTreeSize) {
        printf("%d ", i);
    }
    println("");
}