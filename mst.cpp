// #include union find

ul mst(ul n, vector<pair<ul,pu>>& edg) {
	ul cost=0;union_find ds(n);
    vector<pair<ul,pu>>ne;ne.reserve(edg.size());
	sort(edg.begin(),edg.end());
	rep(i,0,edg.size()) {
		ul x=edg[i].sc.fs,y=edg[i].sc.sc;
		if (!ds.joined(x, y)){ne.pb(edg[i]);cost+=edg[i].fs;ds.unite(x, y);}
	}edg=ne;return cost;
}
