#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int n;
vector<int> a;
vector<int> segmentTree;

//Build Array
int build(int l, int r, int x) {
    if ((r - l) <= 1) {
        //We have reached a leaf
        segmentTree[x] = a[l];
        return segmentTree[x];
    }

    //Divide into 2 halves and recursively build the segment tree
    int m = (l + r) / 2;
    segmentTree[x] = build(l, m, 2 * x) + build(m, r, 2 * x + 1);
    return segmentTree[x];
}

//Range query from segment tree
int query(int s, int e, int l, int r, int x) {
    if (r <= s || l >= e) {
        //Range is outside target range
        return 0;
    }
    if (l >= s && r <= e) {
        //Range is completely inside target range
        return segmentTree[x];
    }
    
    //Range has an intersection with target range
    int m = (l + r) / 2;
    return query(s, e, l, m, 2 * x) + query(s, e, m, r, 2 * x + 1);
}

//Point update of segment tree
int update(int i, int v, int l, int r, int x) {
    if (i < l || i >= r) {
        //Target position not in range
        return segmentTree[x];
    }
    if ((r - l) == 1) {
        //Position is found
        segmentTree[x] = v;
        a[i] = v;
        return segmentTree[x];
    }

    //Split subtree into 2 halves and recursively search for value
    int m = (l + r) / 2;
    segmentTree[x] = update(i, v, l, m, 2 * x) + update(i, v, m, r, 2 * x + 1);
    return segmentTree[x];
}

int main() {
    //Take input
    input(int, n);
    a = vector<int>(n);
    segmentTree = vector<int>(4 * n);
    range(i, 0, n) {
        cin >> a[i];
    }

    //Building the segment tree
    println("Building Segment Tree: ");
    build(0, n, 1);

    int level = 2;
    range(x, 1, 4 * n) {
        if (x == level) {
            level *= 2;
            println("");
        }
        printf("%d ", segmentTree[x]);
    }
    println("");

    //Range queries on the segment tree
    println("Range Queries: ");
    input(int, q);
    range(i, 0, q) {
        input(int, l);
        input(int, r);
        print(query(l - 1, r, 0, n, 1));
    }

    //Point updates on the segment tree
    println("Point Updates: ");
    input(int, u);
    range(i, 0, u) {
        input(int, j);
        input(int, v);
        update(j - 1, v, 0, n, 1);
    }

    //Print the segment tree
    level = 2;
    range(x, 1, 4 * n) {
        if (x == level) {
            level *= 2;
            println("");
        }
        printf("%d ", segmentTree[x]);
    }
    println("");
}