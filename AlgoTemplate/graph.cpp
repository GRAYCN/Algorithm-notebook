//
// Created by w on 2020/11/10.
//


// adj matrix
void Dijkstra(int s) {
    fill(dis,dis+maxn,inf);
    dis[s]=0;

    for(int i=0; i<=N; i++) {

        int u=-1,min=inf;
        for(int j=0; j<=N; j++) {
            if(!vis[j] && dis[j]<min) {
                u=j;
                min=dis[j];
            }
        }

        if(u==-1) break;
        vis[u]=true;

        for(int v=0; v<=N; v++) {
            if(!vis[v] && G[u][v]!=inf) {
                if(dis[v]>dis[u]+G[u][v]) {
                    dis[v]=dis[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(dis[v]==dis[u]+G[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }

    }

    fill(vis,vis+maxn,false);
    DFS(SP);
}

//adj table
struct Node {
    int v, dis;
};
vector<Node> Adj[MAXV];
int n;
int d[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int a){
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u=j;
                MIN = d[j];
            }
        }

        if (u == -1) return;
        vis[u] = true;

        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            if(vis[v]== false && d[u]+Adj[u][j].dis < d[v]) {
                d[v] = d[u] + Adj[u][j].dis;
            }
        }

    }
}