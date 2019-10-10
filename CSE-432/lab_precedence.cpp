#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()

string chk(int x)
{
	string k;
	while(x)
	{
		int m=x%10;
		k+='0'+m;
		x/=10;
	}
	return k;
}

string chk1(int x)
{
	string k;
	while(x>0)
	{
		k+='0'+(x%10);
		x/=10;
	}
	reverse(all(k));
	return k;
}	

ll sm;
ll norm(int s)
{
	int k=0;
	while(s>0)
	{
		k=k*10+(s%10);
		s/=10;
	}
	return k;

}

int main()
{
			string s,tmp="";
			cin>>s;
			int ok=0;
			tmp="";
			int a,b;
			for(int i=0;i<s.size();i++)
			{
					if(s[i+1]=='^')
					{
						int k=i;
						a=0;
						while(s[k]>='0' and s[k]<='9' and k>=0)
							a=a*10+(s[k--]-'0');
						int j=1;
						a=norm(a)*(s[i]=='0'?10:1);
						sm=0;
						k=i+2;
						b=0;
						while(s[k]>='0' and s[k]<='9' and k<s.size())
							b=b*10+(s[k++]-'0');
						ll x=pow(a,b);
						tmp+=chk1(x);
						i=k-1;
					}
					else tmp+=s[i];
			}
			ok=0;
			s=tmp;
			tmp="";
			for(int i=0;i<s.size();i++)
			{
					if(s[i+1]=='/')
					{
						int k=i;
						a=0;
						while(s[k]>='0' and s[k]<='9' and k>=0)
							a=a*10+(s[k--]-'0');
						int j=1;
						a=norm(a)*(s[i]=='0'?10:1);
						sm=0;
						k=i+2;
						b=0;
						while(s[k]>='0' and s[k]<='9' and k<s.size())
							b=b*10+(s[k]-'0'),k++;
							ll x=a/b;

							while(tmp[tmp.size()-1]>='0' and tmp[tmp.size()-1]<='9')
								tmp.pop_back();
							tmp+=chk1(x);				
							i=k-1;
					}
					else tmp+=s[i];		
			}
			ok=0;
			cout<<tmp<<endl;
			s=tmp;
			tmp="";
			for(int i=0;i<s.size();i++)
			{
					if(s[i+1]=='*')
					{
						int k=i;
						a=0;

						while(s[k]>='0' and s[k]<='9' and k>=0)
							a=a*10+(s[k--]-'0');
						int j=1;
						a=norm(a)*(s[i]=='0'?10:1);
						sm=0;
						k=i+2;
						b=0;

						while(s[k]>='0' and s[k]<='9' and k<s.size())
							b=b*10+(s[k++]-'0');
						ll x=a*b;
						sm+=x;
							while(tmp[tmp.size()-1]>='0' and tmp[tmp.size()-1]<='9')
								tmp.pop_back();
						tmp+=chk1(x);
						ok=1;
						i=k-1;
					}
					else tmp+=s[i];
					
					}
			ok=0;
				//		cout<<tmp<<endl;
			s=tmp;
			tmp="";
			a=0,b;
			ll sum=0,n=1;
			for(int i=0;i<s.size();i++)
			{
				if(s[i+1]=='+' or s[i+1]=='-')
				{
						int k=i;
						a=0;
						while(s[k]>='0' and s[k]<='9' and k>=0)
							a=a*10+(s[k--]-'0');
						int j=1;
						a=norm(a)*(s[i]=='0'?10:1);
						sm=0;
						k=i+2;
						b=0;
						while(s[k]>='0' and s[k]<='9' and k<s.size())
							b=b*10+(s[k++]-'0');
						ll x;
						if(s[i+1]=='+')
							 x=a+b;
						else 
							x=a-b;
						sum+=x;
						tmp+=chk1(x);
						i=k-1;
				}
			}
		//	

			            int k=s.size()-1;
						a=0;

						if(s[k]=='0')
						{
							a=1;
							k--;
						}
						while(s[k]>='0' and s[k]<='9' and k>=0 )
							a=a*10+(s[k--]-'0');
						if(s[k]=='-')
							n=-1;
						else  n=1;
					//
						a=norm(a)-(s[s.size()-1]=='0'?1:0);	
						cout<<sum+a*n<<endl;
}
