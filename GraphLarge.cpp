// #include union find

class Graph
{
public:
    Graph(){}
    Graph(ul n)
    {
        nodes = n;
        uf = union_find(n);
        edg = vector<vector<pu>>(n);
        vis = vector<bool>(n);
        dist = vector<ul>(n);
    }
    void connect(ul v, ul u, ul w1, ul w2)
    {
        uf.unite(v,u);
        edg[v].pb(pu{w1,u});
        edg[u].pb(pu{w2,v});
        edg_cnt += 2;
    }
    void connect(ul v, ul u, ul w=1)
    {
        connect(v,u,w,w);
    }
    void connectOne(ul v, ul u, ul w=1)
    {
        uf.unite(v,u);
        edg[v].pb(pu{w,u});
        edg_cnt++;
    }
    void connectSafe(ul v, ul u, ul w=1)
	{
		if(uf.joined(v,u)) return;
		connect(v,u,w,w);
	}
    void connectOneSafe(ul v, ul u, ul w=1)
	{
		if(uf.joined(v,u)) return;
		connectOne(v,u,w);
	}
    void bfs(ul start)
    {
        fill(vis.begin(), vis.end(), false);
        fill(dist.begin(), dist.end(), -1);
        cnt = 1;
        queue<ul> q;
        q.push(start);
        dist[start] = 0;
        vis[start] = true;
        while(!q.empty())
        {
            ul cur = q.front();
            q.pop();
            rep(i, 0, edg[cur].size())
            {
                ul nxt = edg[cur][i].sc;
                if(!vis[nxt])
                {
                    cnt++;
                    vis[nxt] = true;
                    dist[nxt] = dist[cur]+edg[cur][i].fs;
                    q.push(nxt);
                }
            }
        }
    }
    void dfs(ul start)
    {
        fill(vis.begin(), vis.end(), false);
        fill(dist.begin(), dist.end(), -1);
        cnt = 1;
        stack<ul> s;
        s.push(start);
        dist[start] = 0;
        vis[start] = true;
        while(!s.empty())
        {
            ul cur = s.top();
            s.pop();
            rep(i, 0, edg[cur].size())
            {
                ul nxt = edg[cur][i].sc;
                if(!vis[nxt])
                {
                    cnt++;
                    vis[nxt] = true;
                    dist[nxt] = dist[cur]+edg[cur][i].fs;
                    s.push(nxt);
                }
            }
        }
    }
    void dijkstra(ul start)
    {
        priority_queue< pu, vector<pu>, greater<pu>>pq;
        pq.push(pu{0,start});
        dist[start] = 0;
        while(!pq.empty())
        {
            pu cur = pq.top();
            pq.pop();
            if(vis[cur.sc]) continue;
            dist[cur.sc] = cur.fs;
            vis[cur.sc] = true;
            rep(i, 0, edg[cur.sc].size())
            {
                pu nxt = edg[cur.sc][i];
                ul weight = nxt.fs;
                ul vertex_index = nxt.sc;
                if(!vis[vertex_index]) pq.push(pu{weight + cur.fs, vertex_index});
            }
        }
    }
    ul mst() {
		ul cost = 0;
		union_find ds(nodes);
        vector<pair<ul,pu>> flat_edg(edg_cnt);
        get_edges_flat(flat_edg);
		sort(flat_edg.begin(), flat_edg.end());
		rep(i, 0, flat_edg.size()) {
			ul x = flat_edg[i].sc.fs;
			ul y = flat_edg[i].sc.sc;
			if (!ds.joined(x, y)) {
				cost += flat_edg[i].fs;
				ds.unite(x, y);
			}
		}
		return cost;
	}
    ul d_mst() // destructive mst
    {
        ul cost = 0;
		uf = union_find(nodes);
        vector<vector<pu>> new_edg(nodes);
        vector<pair<ul,pu>> flat_edg(edg_cnt);
        get_edges_flat(flat_edg);
		sort(flat_edg.begin(), flat_edg.end());
        edg_cnt = 0;
		rep(i, 0, flat_edg.size()) {
			ul x = flat_edg[i].sc.fs;
			ul y = flat_edg[i].sc.sc;
			if (!uf.joined(x, y)) {
                new_edg[flat_edg[i].sc.fs].pb(pu{flat_edg[i].fs,flat_edg[i].sc.sc});
                edg_cnt++;
				cost += flat_edg[i].fs;
				uf.unite(x, y);
			}
		}
        edg = new_edg;
		return cost;
    }
    void get_edges_flat(vector<pair<ul,pu>> &flat)
    {
        ul loc = 0;
        rep(i,0,edg.size())
        {
            rep(j,0,edg[i].size())
            {
                pair<ul,pu> tmp;
                tmp.fs = edg[i][j].fs;
                tmp.sc = {i, edg[i][j].sc};
                flat[loc] = tmp;
                loc++;
            }
        }
    }
    vector<vector<pu>> edg;
    union_find uf;
    vector<ul> dist;
    vector<bool> vis;
    ul nodes = 0, edg_cnt = 0, cnt = 0;
};
