#include <bits/stdc++.h>
using namespace std;
 
//DataTypes
using str =  string;
using ll  = long long;
using ld  = long double;
using vl  = vector<ll>;
using vd  = vector<ld>;
using vs  = vector<str>;
using vpl = vector<pair<ll,ll>>;
using sll = set<ll>;
using pll = pair<ll,ll>;

//Constants
ll M = 9e18;
const int N = 2e5+5;
const ld pi = 3.141592653589793238;
const ll INF = 9e18;
 
ll n, x, y, a, b, c, k, q, m; str s;
 
//---------------------------------------------------------------------------------------------------------------------------------
//Let's Go :)
 
void impl(ll id, ll val, vl &tree)
{
 
    id+=k;
    tree[id] = val;
    id/=2;
 
    while(id)
    {
        tree[id] = min(tree[2*id],tree[2*id + 1]);
        id/=2;
    }
}
 
ll cal(ll a, ll b, vl &tree)
{
    a+=k; b+=k;
    ll ans = M;
 
    while(a<=b)
    {
        if(a&1) ans = min(ans,tree[a++]);
        if(b&1^1) ans = min(ans,tree[b--]);
 
        a/=2, b/=2;
    }
 
    return ans;
}
 
void solve()
{
    cin >> n;
    vl a(n-1), b(n), l(n), r(n), v(n,M);
 
    inpt(a); inpt(b); inpt(l); inpt(r);
 
    k = n;
 
    while(k&(k-1))
    {
        v.pus(M); 
        k++;
    }
 
    vl tree(2*k,M); v[0] = 0;
    For(k) impl(i,v[i],tree);  
 
	impl(0,b[0],tree);
    
    For1(n)
    {
        v[i] = v[i-1]+a[i-1];
        v[i] = min(v[i],cal(l[i]-1,r[i]-1,tree));
 
 
        impl(i,v[i]+b[i],tree);
    }
 
    For(n) cout << v[i] << ' '; nl
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    
    while(t--) solve();
    
    return 0;
}
