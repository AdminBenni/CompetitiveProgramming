struct graph
{
    vu dist;vector<bool> vis;vector<vector<pu>>edg;
    graph(ul n){edg.resize(n);dist.resize(n);vis.resize(n);}
    void connect1(ul v, ul u, ul w=1){edg[v].pb(pu{w,u});}
    void connect(ul v, ul u, ul w=1){connect1(v,u,w);connect1(u,v,w);}
    ul bfs(ul);ul dfs(ul);void dijk(ul);bool cyclic(ul);bool bipart(ul start);
};

ul graph::bfs(ul start){
    fill(vis.begin(),vis.end(),0);fill(dist.begin(),dist.end(),-1);
    ul cnt=1;queue<ul>q;q.push(start);dist[start]=0;vis[start]=true;
    while(!q.empty()){
        ul cur=q.front();q.pop();
        rep(i,0,edg[cur].size()){
            ul nxt=edg[cur][i].sc;
            if(!vis[nxt]){
                cnt++;vis[nxt]=true;q.push(nxt);
                dist[nxt]=dist[cur]+edg[cur][i].fs;
            }
        }
    }return cnt;
}

ul graph::dfs(ul start){
    fill(vis.begin(),vis.end(),0);fill(dist.begin(),dist.end(),-1);
    ul cnt=1;stack<ul>q;q.push(start);dist[start]=0;vis[start]=true;
    while(!q.empty()){
        ul cur=q.top();q.pop();
        rep(i,0,edg[cur].size()){
            ul nxt=edg[cur][i].sc;
            if(!vis[nxt]){
                cnt++;vis[nxt]=true;q.push(nxt);
                dist[nxt]=dist[cur]+edg[cur][i].fs;
            }
        }
    }return cnt;
}

bool graph::cyclic(ul start){
    fill(vis.begin(),vis.end(),0);stack<pu>q;
    q.push({start,start});vis[start]=true;
    while(!q.empty()){
        ul cur=q.top().fs,par=q.top().sc;q.pop();
        rep(i,0,edg[cur].size()){
            ul nxt=edg[cur][i].sc;
            if(!vis[nxt]){vis[nxt]=true;q.push({nxt,cur});}
            else if(nxt!=par)return true;
        }
    }return false;
}

bool graph::bipart(ul start){
    vector<char>done(edg.size(),2);
    queue<pu>q;q.push({start,1});done[start]=0;
    while(!q.empty()){
        ul cur=q.front().fs,t=q.front().sc;q.pop();
        rep(i,0,edg[cur].size()){
            ul nxt=edg[cur][i].sc;
            if(done[nxt]==2){done[nxt]=t;q.push({nxt,!t});}
            else if(done[nxt]!=t)return false;
        }
    }return true;
}

void graph::dijk(ul start){
    priority_queue<pu,vector<pu>,greater<pu>>pq;
    pq.push(pu{0,start});dist[start]=0;
    while(!pq.empty())
    {
        pu cur=pq.top();pq.pop();if(vis[cur.sc])continue;
        dist[cur.sc]=cur.fs;vis[cur.sc]=true;
        rep(i, 0, edg[cur.sc].size())
        {
            pu nxt=edg[cur.sc][i];ul weight=nxt.fs;ul vertex_index=nxt.sc;
            if(!vis[vertex_index])pq.push(pu{weight+cur.fs,vertex_index});
        }
    }
}
