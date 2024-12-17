#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Edge{
  public:
  int src; 
  int des;
  int wt;
};

struct CompareSecond {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

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
  e.src = 0; e.des = 1; e.wt = 2;
  t.push_back(e);
  e.src = 0; e.des = 2; e.wt = 4;
  t.push_back(e);
  graph.push_back(t);
  t.clear();

  e.src = 1; e.des = 3; e.wt = 7;
  t.push_back(e);
  e.src = 1; e.des = 2; e.wt = 1;
  t.push_back(e);
  graph.push_back(t);
  t.clear();


  e.src = 2; e.des = 4; e.wt = 3;
  t.push_back(e);
  graph.push_back(t);
  t.clear();

  e.src = 3; e.des = 5; e.wt = 1;
  t.push_back(e);
  graph.push_back(t);
  t.clear();

  e.src = 4; e.des = 3; e.wt = 2;
  t.push_back(e);
  e.src = 4; e.des = 5; e.wt = 5;
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
  int V = 6;
  vector<vector<Edge> > graph;
  createGraph(graph);

  bellmanFord(graph, 0, V);

}