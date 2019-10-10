#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
#define pb push_back
map<string,std::vector<string>> v;
string txt;
bool vis=false;
void dfs(string s)
{
	if(s==txt)
	{
		vis=true;
		return ;
	}
	if(sz(s)>sz(txt))
		return ;
	for(int i=0;i<sz(s);i++)
	{
		if(s[i]>='A' and s[i]<='Z')
		{
			string fst="";
			for(int j=0;j<i;j++)
				fst+=s[j];
			string sc="";
			for(int j=i+1;j<sz(s);j++)
				sc+=s[j];	
			string tmp;
			tmp+=s[i];
			for(auto it : v[tmp])
			{
				string nw;
				if(sz(fst))
					nw+=fst;
				nw+=it;
				if(sz(sc))
					nw+=sc;
				if(sz(nw)==0)
					return ;
			dfs(nw);
			}
		}
	}
}
int main()
{

			int n;
			cin>>n;
			for(int i = 0;i<n;i++)
			{
				string a,b;
				cin>>a>>b;
				v[a].pb(b);				
			}
			cin>>txt;
			dfs("S");
			puts(vis?"POSSIBLE":"NOT POSSIBLE");

}