struct union_find // zero indexed
{
    vu par,sz;
    union_find(){}
    union_find(ul n){par=vector<ul>(n),sz=vector<ul>(n);rep(i,0,n)par[i]=i,sz[i]=1;}
    ul find(ul a){return par[a]=par[a]==a?a:find(par[a]);}
    void unite(ul a,ul b){ul pa=find(a),pb=find(b);if(pa==pb)return;par[pb]=find(pa);sz[pa]+=sz[pb];}
    bool joined(int a, int b) { return find(a) == find(b);}
    ul size(ul a){return sz[find(a)];}
};
