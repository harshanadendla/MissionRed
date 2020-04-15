//bavundi..easy logic ee..cheppaga...needs 5-6 extra minsof thinking....
//and found a failing case...mnam 1 ni decompose cheyyatla....so after the pq is full of 1's
//...instead of getting terminated and printing NO....adi just kept on continuing...and gave k-2*n 1's
//as output

/*
    YES PAIN YES GAIN
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template<class T> using rbTree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define unmap unordered_map
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define vvi vector<vector<int>>
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl

const int N=1e5;
const int M=2e5;
const int mod=1e9+7;

void solve()
{
    int cnt=0;
    priority_queue<int> pq;

    int n,k;
    cin>>n>>k;

    if(k>n)
    {
        cout<<"NO";
        return;
    }

    for(int i=0;i<31;i++)
    {
        if(n & (1<<i))
        {
            pq.push((1<<i));
            cnt++;
        }
    }

    if(cnt>k)
    {
        cout<<"NO";
        return;
    }

    while(cnt<k && !pq.empty())
    {
        int t=pq.top();
        pq.pop();

        if(t/2 >= 1)
        {
            pq.push(t/2);
            pq.push(t/2);
        }

        if(pq.empty())
        {
            cout<<"NO";
            return;
        }

        cnt++;
    }

    if(cnt<k)
    {
        cout<<"NO";
        return;
    }

    cout<<"YES\n";    
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    //cin>>t;

    while(t--)
    {
        solve();
    }

    #ifndef ONLINE_JUDGE
    cout << "\n\ntime: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms";
    #endif

    return 0;
}