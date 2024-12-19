
#include<bits/stdc++.h>
using namespace std;

class Edge{
  public:
  int src; 
  int des;
  int wt;
};

// for comparision in priority queue
struct CompareSecond {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

stack<int> topologicalSort(vector<vector<Edge> >& graph, int src, int V){
  stack<int> s;
  stack<int> tans;
  s.push(src);
  vector<int> vis(V, 0);
  vis[src] = 1;

  while(!s.empty()){
    int c = s.top();
    s.pop();
    tans.push(c);

    for(int i = 0; i < graph[c].size(); ++i){
      if(!vis[graph[c][i].des]){
        vis[graph[c][i].des] = 1;
        s.push(graph[c][i].des);
      }
    }
    
  }

  stack<int> ans;
  while(!tans.empty()){
    int c = tans.top();
    ans.push(c);
    tans.pop();
  }

  return ans;
}

void dfs(vector<vector<Edge> >& graph, int src, vector<int>& vis){
  if(!vis[src]){
    vis[src] = 1;
    for(int i = 0; i < graph[src].size(); ++i){
      dfs(graph, graph[src][i].des, vis);
    }
    cout << src << " ";
  }
}

void kosaraju(vector<vector<Edge> >& graph, int src, int V){
  stack<int> tsc = topologicalSort(graph, src, V); 

  // creating a transpose graph
  vector<vector<Edge> > tgraph;
  for(int i = 0; i < graph.size(); ++i) {
    vector<Edge> temp; tgraph.push_back(temp);
  }

  for(int i = 0; i < graph.size(); ++i){
    for(int j = 0; j < graph[i].size(); ++j){
      Edge e = graph[i][j];
      Edge te;
      te.src = e.des; te.des = e.src; te.wt = e.wt;
      tgraph[te.src].push_back(te);
    }
  }

  // performing final dfs
  vector<int> vis(V, 0);
  while(!tsc.empty()){
     int c = tsc.top();
     tsc.pop();
     if(!vis[c]) dfs(graph, c, vis);
     cout << endl;
  }
  
}

int prims(vector<vector<Edge> >& graph, int V){
  vector<int> vis(V, 0);
  priority_queue<pair<int, int>, vector<pair<int, int> >, CompareSecond> pq;

  int ans = 0;
  pq.push(pair<int, int>(graph[0][0].src, 0));

  while(!pq.empty()){
    pair<int, int> p = pq.top();
    pq.pop();
    ans += p.second;
    vis[p.first] = 1;

    int min_c = INT_MAX;
    int nv;
    int flag = 0;

    for(int k = 0; k < V; ++k){
      if(vis[k]){
        for(int i = 0; i < graph[k].size(); ++i){
          if(!vis[graph[k][i].des] && min_c > graph[k][i].wt) {
            min_c = graph[k][i].wt;
            nv = graph[k][i].des;
            flag = 1;
          }
        }
      }
    }

    if (flag) pq.push(pair<int, int>(nv, min_c));
   

  }

  return ans;
}

void bellmanFord(vector<vector<Edge> >& graph, int src, int V){
  vector<int> dis(V, INT_MAX);
  dis[src] = 0;

  for(int i = 0; i < V-1; ++i){
    for(int j = 0; j < V; ++j){
      for(int k = 0 ; k < graph[j].size(); ++k){
        Edge e = graph[j][k];
        if(dis[e.src] != INT_MAX && dis[e.des] > dis[e.src] + e.wt) 
          dis[e.des] = dis[e.src] + e.wt;
      }
    } 
  }

  for(int i = 0; i < V; ++i) cout << dis[i] << " ";
  cout << endl;
  
}

void dijkstra(vector<vector<Edge> >&graph, int src, int V){
  priority_queue<pair<int, int>, vector<pair<int, int> >, CompareSecond> pq;

  vector<int> dis(V, INT_MAX);
  dis[src] = 0;
  vector<int> vis(V, 0);

  pq.push(pair<int, int>(src, 0));

  while(!pq.empty()){
    pair<int, int> c = pq.top();
    pq.pop();

    if(!vis[c.first]) {
      vis[c.first] = 1;
      for(int i = 0; i < graph[c.first].size(); ++i){
        if(dis[graph[c.first][i].des] > dis[graph[c.first][i].src] + graph[c.first][i].wt){
          dis[graph[c.first][i].des] = dis[graph[c.first][i].src] + graph[c.first][i].wt;
          pq.push(pair<int, int>(graph[c.first][i].des, graph[c.first][i].wt));
        }
      }
    }
  }

  for(int i = 0 ;i < dis.size(); ++i) cout << dis[i] << " ";
  cout << endl;

}

void createGraph(vector<vector<Edge> >& graph){
  
  Edge e;
  vector<Edge> t;
  e.src = 0; e.des = 2; e.wt = 15;
  t.push_back(e);
  e.src = 0; e.des = 3; e.wt = 30;
  t.push_back(e);
  graph.push_back(t);
  t.clear();

  e.src = 1; e.des = 0; e.wt = 10;
  t.push_back(e);
  graph.push_back(t);
  t.clear();


  e.src = 2; e.des = 1; e.wt = 50;
  t.push_back(e);
  graph.push_back(t);
  t.clear();

  e.src = 3; e.des = 4; e.wt = 30;
  t.push_back(e);
  graph.push_back(t);
  t.clear();

}

void bfs(vector<vector<Edge> > graph, vector<int>& visited, int start){
  queue<int> q;
  q.push(start);
  
  while(!q.empty()){
    int current = q.front();
    q.pop();
    if(!visited[current]){
      cout << current << endl;
      for(int i = 0; i < graph[current].size(); ++i){
        q.push(graph[current][i].des);
      }
      visited[current] = 1;
    }
  }
}

int main(){
  int V = 5;
  vector<vector<Edge> > graph;
  createGraph(graph);

  kosaraju(graph, 0, V);
  
}
