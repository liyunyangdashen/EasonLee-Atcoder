#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<utility>
using namespace std; using ll = long long; const int N = 2e5 + 5,INF = 0x3f3f3f3f;
using pil = pair<int,ll>; using pli = pair<ll,int>; //we must use long long
ll n,q,a[2 * N],dis[N],s,t; bool vis[N]; vector<pil> adj[N];
void Dijkstra(int st){
  memset(dis,0x3f,sizeof(dis));
  priority_queue<pli,vector<pli>,greater<pli> > pq;
  pq.push(make_pair(0,st)); dis[st] = 0;
  while (!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto e : adj[u]){
      int v = e.first,w = e.second; 
      if (!vis[v] && dis[v] > dis[u] + w)
        dis[v] = dis[u] + w,
        pq.push(make_pair(dis[v],v));
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1;i <= n;i++){
    cin >> a[i];
    a[i + n] = a[i];
    adj[i].push_back(make_pair(i % n + 1,a[i]));//use i%n+1
    adj[i % n + 1].push_back(make_pair(i,a[i]));//follow
  }
  for (int i = 1;i < 2 * n;i++)
    a[i] += a[i - 1];
  for (int i = 1;i <= n;i++){
    cin >> s;
    adj[n + 1].push_back(make_pair(i,s));
    adj[i].push_back(make_pair(n + 1,s));
  }
  Dijkstra(n + 1);
  while (q--){
    cin >> s >> t;
    if (s > t) swap(s,t);
    if (t == n + 1)
      cout << dis[s] << '\n';
    else
      cout << min(min(a[t - 1] - a[s - 1],a[s + n - 1] - a[t - 1]),dis[s] + dis[t]) << '\n';
  }
  return 0;
}
