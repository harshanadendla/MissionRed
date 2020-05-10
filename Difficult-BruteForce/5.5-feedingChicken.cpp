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
#define int long long
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
#define dbg(x) cout<<#x<<" "<<x<<"\n"
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=1e2+5;
const int mod=1e9+7;

int r,c,k;
vector<vector<char>> farm(N,vector<char>(N,'.'));
vector<pii> rice;
vector<vector<char>> ans(N,vector<char>(N,'.'));
int riceF,idx,ctr,minV,maxV;
string str="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void setMems() {
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            farm[i][j]='.';
            ans[i][j]='.';
        }
    }
    rice.clear();
    riceF=0;
    idx=0;
    ctr=0;
}

void solve() {
    cin>>r>>c>>k;

    setMems();

    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            cin>>farm[i][j];
            if (farm[i][j]=='R') {
                rice.pb(mp(i,j));
                riceF++;
            }
        }
    }

    minV=riceF/k;
    maxV=riceF%k;

    for (int i=0;i<r;i++) {
        if (i%2 == 0) {
            for (int j=0;j<c;j++) {
                ans[i][j]=str[idx];
                if (farm[i][j]=='R') {
                    ctr++;
                    if (maxV > 0) {
                        if (ctr == minV+1) {
                            ctr=0;
                            maxV--;
                            idx++;
                        }
                    } else {
                        if (ctr == minV) {
                            ctr=0;
                            idx++;
                            if (idx==k) {
                                idx--;
                            }
                        }
                    }
                }
            }
        } else {
            for (int j=c-1;j>=0;j--) {
                ans[i][j]=str[idx];
                if (farm[i][j]=='R') {
                    ctr++;
                    if (maxV > 0) {
                        if (ctr == minV+1) {
                            ctr=0;
                            maxV--;
                            idx++;
                        }
                    } else {
                        if (ctr == minV) {
                            ctr=0;
                            idx++;
                            if (idx==k) {
                                idx--;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int t=1;
    cin>>t;

    while(t--) {
        solve();
    }

    return 0;
}