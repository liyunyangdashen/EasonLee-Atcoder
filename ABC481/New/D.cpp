#include<iostream>
#include<cstring>
#include<queue>
#include<map>
#include<utility>
using namespace std; using pii = pair<int,int>; const int N = 2e5 + 5,INF = 0x3f3f3f3f;
int n,m,s,t,u,v,dis[N],minn[N]; bool vis[N]; map<int,bool> adj[N]; 
void Dijkstra(int st){
  memset(dis,0x3f,sizeof(dis));
  priority_queue<pii,vector<pii>,greater<pii> > pq;
  pq.push(make_pair(0,st)); dis[st] = 0;
  while (!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    if (vis[u]) continue; 
    vis[u] = 1;
    for (auto e : adj[u]){
      int v = e.first,w = e.second; 
      if (!vis[v] && dis[v] > dis[u] + w){
        dis[v] = dis[u] + w;
        pq.push(make_pair(dis[v],v));
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> s >> t;
  memset(minn,0x3f,sizeof(minn));
  while (m--){
    cin >> u >> v;
    adj[u][v] = 1;
    if (minn[u] >= v){//See in Almost D.cpp
      if (minn[u] != INF) adj[u][minn[u]] = 1;
      adj[u][v] = 0; minn[u] = v;
    }
  }
  Dijkstra(s);
  cout << (dis[t] == INF ? -1 : dis[t]);
  return 0;
}
