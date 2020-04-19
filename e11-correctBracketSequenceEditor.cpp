/*
    YES PAIN YES GAIN
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template<class T>
using rbTree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define unmap unordered_map
#define mset multiset
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=1e5;
const int mod=1e9+7;

void solve()
{
    int n,m,p;
    string str,ops;
    cin>>n>>m>>p>>str>>ops;
    p--;

    stack<int> st;
    int jodi[n],l[n],r[n];
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            st.push(i);
        }
        else
        {
            jodi[i]=st.top();
            jodi[st.top()]=i;
            st.pop();
        }
    }

    for(int i=0;i<n;i++)
    {
        l[i]=i-1;
        r[i]=i+1;
    }

    for(int i=0;i<m;i++)
    {
        if(ops[i]=='L') p=l[p];
        else if(ops[i]=='R') p=r[p];
        else
        {
            int lidx=min(p,jodi[p]);
            int ridx=max(p,jodi[p]);

            fill(str.begin()+lidx,str.begin()+ridx+1,'*');

            l[r[ridx]]=l[lidx];
            r[l[lidx]]=r[ridx];

            (r[ridx]<n) ? p=r[ridx] : p=l[lidx] ;
        }
    }

    for(int i=0;i<n;i++) if(str[i] != '*') cout<<str[i];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}