#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> ok;
 
void dfs(int src,int par)
{
    for(auto &edge : graph[src])
    {
        if(edge != par)
        {
            dfs(edge, src);
            ok[src] = (ok[src] + ok[edge]) % 2;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q, ans = 0; 
    cin >> n >> q;
    graph.resize(n);
    ok.resize(n);
    ok.assign(n, 0);
    vector<int> cols(n);
    for(int i = 0; i < n; i++)
        cin >> cols[i];
    for(int i = 0; i < n - 1; i++)
    {
        int x, y; 
        cin >> x >> y;
        x--; 
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 0; i < q; i++)
    {
        int x; 
        cin >> x;
        x--;
        ok[x] = (ok[x] + 1) % 2;
    }
    dfs(0, -1);
    for(int i = 0; i < n; i++)
    {
        if(ok[i])
            cols[i] ^= 1;
        ans += (cols[i] == 1);
    }
    cout << ans << endl;
    return 0;
}
