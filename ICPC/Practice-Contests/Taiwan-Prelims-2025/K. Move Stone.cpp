#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

#define ll long long
 
template<typename T>
using inverse_priority_queue = std::priority_queue<T, vector<T>, greater<T>>;
 
const ll INF = 1e18 + 1000;
 
// A reference implementation of Dinitz's algorithm for minimum-cost flows.
// Note: this implementation has been created with educational
// value in mind, not efficiency. Other implementations with
// better constant factors exist; if you're looking for a black
// box to use in a contest, you're better off looking elsewhere.
 
// This struct represents the state of an edge, together with its
// reverse edge that may appear in some G_f, during the execution
// of the algorithm.
struct Edge {
  int from, to; // The edge is from->to in the original graph.
  ll capac, flow;
 
  // The cost of the edge. In this implementation, we add potentials
  // to the edges directly (it is easy to see that if we add potentials,
  // the reverse edge will still have cost equal to -(forward edge cost).
  ll _cost; 
 
  // Gets the endpoint other than u of the edge.
  int oth (int u) {
    return u ^ from ^ to; // xor trick
  }
 
  // Gets the capacity of the edge u->oth(u) in G_f.
  ll capacity (int u) {
    if (u == from) {
      return capac - flow;
    } else {
      return flow;
    }
  }
 
  // Gets the cost of the edge u->oth(u) in G_f
  ll cost (int u) {
    if (u == from) {
      return _cost;
    } else {
      return -_cost;
    }
  }
 
  // Returns whether the edge u->oth(u) exists in u.
  bool exists (int u) {
    return capacity(u) != 0;
  }
 
  // Adds df flow to the edge in G if u == from,
  // subtracts it otherwise.
  void add_flow (int u, ll df) {
    if (u == from) {
      flow += df;
    } else {
      flow -= df;
    }
  }
};
 
// At any given time, represents one particular G_f. We modify this class on the
// fly when adding a flow.
class MaxFlow {
  // number of vertices
  int n;
  int source, sink;
 
  // the current potential of the sink; the only potential which we actually need
  ll sink_potential; 
 
  // adj[u] is the set of edges incident to u
  vector<vector<Edge*>> adj;
 
  // we also keep a list of all edges, for easy retrieval of flow on edge
  vector<Edge*> edges;
 
  void recalc_edge_costs (const vector<ll> &dist) {
    for (auto e : edges) {
      if (dist[e->from] >= INF || dist[e->to] >= INF) {
        // one of these vertices is no longer reachable. we can ignore these edges entirely
        continue;
      }
 
      e->_cost += dist[e->from];
      e->_cost -= dist[e->to];
    }
 
    sink_potential += dist[sink];
  }
 
  // returns true if sink is reachable from source
  bool recalc_dist_bellman_ford () {
    vector<ll> dist (n, INF);
 
    dist[source] = 0;
    for (int k = 0; k < n; k++) {
      for (auto e : edges) {
        if (e->from == e->to) {
          // see the constructor. we pretend those don't exist.
          continue;
        }
 
        // this is calculated at the beginning, so we can use "from" and "to", no
        // flow has been added yet.
        dist[e->to] = min(dist[e->to], dist[e->from] + e->_cost);
      }
    }
 
    if (dist[sink] >= INF) {
      return false;
    }
 
    recalc_edge_costs(dist);
    return true;
  }
 
  bool recalc_dist_dijkstra () {
    vector<ll> dist (n, INF);
    vector<int> processed (n, 0);
 
    inverse_priority_queue<pair<ll, int>> Q;
    dist[source] = 0;
    Q.push({dist[source], source});
 
    while (!Q.empty()) {
      int u;
      ll d;
      tie(d, u) = Q.top();
      Q.pop();
 
      if (processed[u]) {
        continue;
      }
      processed[u] = true;
 
      for (auto e : adj[u]) {
        if (!e->exists(u)) {
          continue;
        }
 
        if (dist[u] + e->cost(u) < dist[e->oth(u)]) {
          dist[e->oth(u)] = dist[u] + e->cost(u);
          Q.push({dist[e->oth(u)], e->oth(u)});
        }
      }
    }
 
    if (dist[sink] >= INF) {
      return false;
    }
 
    recalc_edge_costs(dist);
    return true;
  }
 
  // lvl[u] is the layer (or distance from s) at the current DAG.
  // updated via dinitz_bfs
  vector<int> lvl;
 
  void dinitz_bfs () {
    // we use a value greater than n to denote "unexplored"
    // or what is called "undefined" in the blog. no vertex actually
    // has a distance greater than n.
    lvl = vector<int> (n, n + 10); 
 
    queue<int> Q;
    Q.push(source);
    lvl[source] = 0;
 
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
 
      for (auto e : adj[u]) {
        if (!e->exists(u)) {
          continue;
        }
 
        // this is supposed to be run in the shortest-paths DAG.
        // if we use shortest-path potentials, then the shortest-paths DAG is
        // exactly the edges that have cost 0.
        if (e->cost(u) != 0) {
          continue;
        }
 
        int v = e->oth(u);
        if (lvl[v] > n) {
          lvl[v] = lvl[u] + 1;
          Q.push(v);
        }
 
        // in the actual implementation, we don't explicitly add edges to the
        // DAG. we simply say that an edge u->v is in the DAG if lvl[v] = lvl[u] + 1
      }
    }
  }
 
  bool in_current_dag (int u, int v) {
    return lvl[v] == lvl[u] + 1;
  }
 
  // as in the blog, tries to push F flow from u
  // returns how much flow could actually be pushed
  // the third parameter is used to maintain what is
  // called v.blocked in the blog; note that it is a
  // reference.
  ll dinitz_dfs (int u, ll F, vector<int> &blocked) {
    if (u == sink) {
      return F;
    }
 
    ll flow_pushed = 0;
    bool all_blocked = true;
    for (auto e : adj[u]) {
      int v = e->oth(u);
      if (!in_current_dag(u, v)) {
        continue;
      }
 
      if (e->exists(u) && e->cost(u) == 0 && !blocked[v]) {
        // note that here we use e->capacity(u) instead of
        // the e.capacity - e.flow in the blog, as the Edge
        // struct automatically modifies the capacities when
        // we add flow.
        ll dF = dinitz_dfs(v, min(F, e->capacity(u)), blocked);
 
        flow_pushed += dF;
        F -= dF;
        e->add_flow(u, dF);
      }
 
      if (e->exists(u) && e->cost(u) == 0 && !blocked[v]) {
        all_blocked = false;
      }
    }
 
    if (all_blocked) {
      blocked[u] = true;
    }
 
    return flow_pushed;
  }
 
  ll dinitz_dfs () {
    vector<int> blocked (n, false);
    return dinitz_dfs(source, INF, blocked);
  }
 
public:
  MaxFlow (int _source, int _sink, const vector<tuple<int, int, ll, ll>> &_edges)
    : source(_source), sink(_sink), sink_potential(0) {
    n = max(1 + source, 1 + sink);
    for (auto e : _edges) {
      n = max(n, max(1 + get<0>(e), 1 + get<1>(e)));
    }
 
    adj = vector<vector<Edge*>> (n, vector<Edge*> (0));
    for (auto e : _edges) {
      auto ee = new Edge();
      ee->from = get<0>(e);
      ee->to = get<1>(e);
      ee->flow = 0;
      ee->capac = get<2>(e);
      ee->_cost = get<3>(e);
 
      edges.push_back(ee);
      if (ee->from != ee->to) {
        // don't add self-loops to the adjacency list; they don't do anything
        // useful to the graph and may mess up the algorithm.
        // if they are positive, then they are useless
        // if they are negative, then the assumption is violated
        adj[ee->from].push_back(ee);
        adj[ee->to].push_back(ee);
      }
    }
  }
 
  // returns a pair <flow, cost>
  pair<ll, ll> calc_max_flow () {
    bool any_path = recalc_dist_bellman_ford();
    if (!any_path) {
      return {0LL, 0LL};
    }
 
    ll tot_flow = 0, tot_cost = 0;
    while (true) {
      any_path = recalc_dist_dijkstra();
      if (!any_path) {
        break;
      }
 
      while (true) {
        dinitz_bfs();
        if (lvl[sink] > n) {
          // t is not reachable from s anymore.
          break;
        }
 
        ll cur_flow = dinitz_dfs();
        tot_flow += cur_flow;
        tot_cost += cur_flow * sink_potential;
      }
    }
 
    return {tot_flow, tot_cost};
  }
 
  ll flow_on_edge (int idx) {
    return edges[idx]->flow;
  }
};
 
// convenience class for building the graph without awkward make_tuples
class GraphBuilder {
  int source, sink;
  vector<tuple<int, int, ll, ll>> edges;
 
public:
  GraphBuilder (int _source, int _sink) : source(_source), sink(_sink), edges(0) {}
 
  void add_edge (int u, int v, ll capacity, ll cost) {
    edges.push_back(make_tuple(u, v, capacity, cost));
  }
 
  MaxFlow build () {
    return MaxFlow(source, sink, edges);
  }
};

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<int>> a(n, vector<int>(n));
	rep(i, 0, n) {
		arrput(a[i]);
	}

	int N = n * n;
	GraphBuilder m(2 * N + 2 + 2 * n + 1, 2 * N + 2 * n + 2);
	rep(i, 0, n) {
		rep(j, 0, n) {
			m.add_edge(2 * N + 2 * n + 1, i * n + j, a[i][j], 0);
			m.add_edge(i * n + j, 2 * N + i, N, 1);
			m.add_edge(i * n + j, 2 * N + n + j, N, 1);
			m.add_edge(i * n + j, i * n + j + N, N, 0);
			m.add_edge(2 * N + i, i * n + j + N, N, 0);
			m.add_edge(2 * N + n + j, i * n + j + N, N, 0);
			m.add_edge(i * n + j + N, 2 * N + 2 * n + 2, 1, 0);

			// m.add_edge(2 * N + 2 * n + 1, i * n + j, 0, a[i][j]);
			// m.add_edge(i * n + j, 2 * N + i, 1, N);
			// m.add_edge(i * n + j, 2 * N + n + j, 1, N);
			// m.add_edge(i * n + j, i * n + j + N, 0, N);
			// m.add_edge(2 * N + i, i * n + j + N, 0, N);
			// m.add_edge(2 * N + n + j, i * n + j + N, 0, N);
			// m.add_edge(i * n + j + N, 2 * N + 2 * n + 2, 0, 1);
		}
	}
	rep(i, 0, n) {
		m.add_edge(2 * N + i, 2 * N + 2 * n, N, 1);
		m.add_edge(2 * N + n + i, 2 * N + 2 * n, N, 1);
		m.add_edge(2 * N + 2 * n, 2 * N + i, N, 0);
		m.add_edge(2 * N + 2 * n, 2 * N + n + i, N, 0);

		// m.add_edge(2 * N + i, 2 * N + 2 * n, 1, N);
		// m.add_edge(2 * N + n + i, 2 * N + 2 * n, 1, N);
		// m.add_edge(2 * N + 2 * n, 2 * N + i, 0, N);
		// m.add_edge(2 * N + 2 * n, 2 * N + n + i, 0, N);
	}
	print(m.build().calc_max_flow().second);
}
