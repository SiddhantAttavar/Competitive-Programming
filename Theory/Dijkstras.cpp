#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int main() {
    input(int, n);
    input(int, m);

    vector<pair<int, int>> graph[n];
    range(i, 0, m) {
        input(int, u);
        input(int, v);
        input(int, w);
        graph[u - 1].push_back(make_pair(v - 1, w));
        graph[v - 1].push_back(make_pair(u - 1, w));
    }

    bool visited[n];
    int distance[n];
    priority_queue<pair<int, int>> priorityQueue;
    priorityQueue.push(make_pair(0, 0));
    distance[0] = 0;
    range(i, 1, n) {
        priorityQueue.push(make_pair(numeric_limits<int>::max(), i));
        distance[i] = numeric_limits<int>::max();
    }

    while (!priorityQueue.empty()) {
        int u = priorityQueue.top().second;
        priorityQueue.pop();

        for (pair<int, int> v: graph[u]) {
            if (distance[u] < numeric_limits<int>::max() && distance[v.first] > (distance[u] + v.second)) {
                priorityQueue.push(make_pair(distance[u] + v.second, v.first));
                distance[v.first] = distance[u] + v.second;
            }
        }
    }

    range(i, 0, n) {
        println("1 => %d: %d", i + 1, distance[i]);
    }
}