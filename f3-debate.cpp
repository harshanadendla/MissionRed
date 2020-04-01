/*
	YES PAIN YES GAIN
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
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

//int pow[N]
const int N=1e5;
const int mod=1e9+7;


void solve()
{
	unordered_map<string,int> type={ {"00",0} , {"01",1} , {"10",2} , {"11",3} };
	vi v[4];

	int n,a,ans=0,cnt=0;
	string str;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>str>>a;
		v[type[str]].pb(a);
	}

	for(int i : v[3]) 
	{
		ans+=i;
		cnt++;
	}

	for(int i=0;i<3;i++) sort(all(v[i]));

	while(v[2].size() && v[1].size())
	{
		ans+=v[2].back();
		v[2].pop_back();

		ans+=v[1].back();
		v[1].pop_back();
	}

	vi u;
	for(int i : v[0]) u.pb(i);
	for(int i : v[1]) u.pb(i);
	for(int i : v[2]) u.pb(i);

	sort(all(u));

	while(cnt && u.size())
	{
		ans+=u.back();
		u.pop_back();
		cnt--;
	}

	cout<<ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif

	clock_t t1,t2;
	t1=clock();

	int t=1;
	//cin>>t;

	while(t--)
	{
		solve();
	}

	#ifndef ONLINE_JUDGE
	t2=clock();
	cerr<<"timeTaken : "<<(t2-t1)/(double)CLOCKS_PER_SEC;
	#endif

	return 0;
}