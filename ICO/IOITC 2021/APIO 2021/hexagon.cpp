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
const int MOD = 1e9 + 7;

pair<int, int> change(pair<int, int> curr, int dir) {
    int x, y; tie(x, y) = curr;
    if (dir == 1) {
        return {x, y + 2};
    }
    else if (dir == 2) {
        return {x + 2, y + 1};
    }
    else if (dir == 3) {
        return {x + 2, y - 1};
    }
    else if (dir == 4) {
        return {x, y - 2};
    }
    else if (dir == 5) {
        return {x - 2, y - 1};
    }
    else {
        return {x - 2, y + 1};
    }
}

int draw_territory(int n, int a, int b, vector<int> d, vector<int> l) {
    set<pair<int, int>> path;
    path.insert({0, 0});
    pair<int, int> curr = {0, 0};
    range(i, 0, n) {
        range(j, 0, l[i]) {
            curr = change(curr, d[i]);
            path.insert(curr);
        }
    }

    int minX = 0, maxX = 0, minY = 0, maxY = 0;
    for (pair<int, int> p : path) {
        minX = min(minX, p.first);
        maxX = max(maxX, p.first);
        minY = min(minY, p.second);
        maxY = max(maxY, p.second);
    }

    if ((((minX % 4) + 4) % 4 == 0) != (((minY % 2) + 2) % 2 == 0)) {
        minY--;
    }
    if ((((maxX % 4) + 4) % 4 == 0) != (((maxY % 2) + 2) % 2 == 0)) {
        maxY++;
    }

    tie(minX, minY) = change(change(change({minX, minY}, 5), 5), 5);
    tie(maxX, maxY) = change(change(change({maxX, maxY}, 2), 2), 2);

    set<pair<int, int>> outside;
    queue<pair<int, int>> q;
    q.push({minX, minY});
    outside.insert({minX, minY});
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        if (u.first < minX or u.first > maxX or u.second < minY or u.second > maxY) {
            continue;
        }

        range(i, 1, 7) {
            pair<int, int> v = change(u, i);
            if (path.find(v) == path.end() and outside.find(v) == outside.end()) {
                outside.insert(v);
                q.push(v);
            }
        }
    }

    map<pair<int, int>, ll> dist;
    q.push({0, 0});
    ll res = 0;
    dist[{0, 0}] = 0;
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        if (outside.find(u) != outside.end()) {
            continue;
        }

        res = (res + (a + dist[u] * b)) % MOD;
        range(i, 1, 7) {
            pair<int, int> v = change(u, i);
            if (dist.find(v) == dist.end()) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return res;
}

int main() {
    print(draw_territory(
        17, 2, 3, 
        {1, 2, 3, 4, 5, 4, 3, 2, 1, 6, 2, 3, 4, 5, 6, 6, 1}, 
        {1, 2, 2, 1, 1, 1, 1, 2, 3, 2, 3, 1, 6, 3, 3, 2, 1}
    ));
}