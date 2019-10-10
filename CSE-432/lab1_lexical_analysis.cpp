//lab1 lexical anaysis-1504054
#include<bits/stdc++.h>
using namespace std;
string s,t;
vector<pair<string,int> > vec;
vector<string>vec1;
map<string,int> m;
string arr[100];
int k=0;
int checkidentifier()
{
    if(t=="int" || t=="myfunc" || t=="return")
    return 0;
    else return 1;
}
void checkpar_op(char x)
{
    t="";
    t+=x;
    if(x=='(' || x==')' || x=='{' || x=='}'||x=='+'|| x=='++'||x=='-'|| x=='--'||x=='='|| x==',')
        vec.push_back(make_pair(t,0));

}
void lexical()
{

    int i,j;
    for(i=0;i<s.size();i++)
    {
        t="";
        if(s[i]==' ') continue;

        if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
        {

        for(j=i;j<s.size();j++)
        {
            if(s[j]>='a'&&s[j]<='z'||s[i]>='A'&&s[i]<='Z')
                t+=s[j];
            else
                break;
        }
        int iden=checkidentifier();
        if(iden==0)
            vec.push_back(make_pair(t,0));
        else
            {
                if(m[t]==0)

                {   arr[k]=t;
                m[t]=++k;
                }
                vec.push_back(make_pair("id",m[t]));
                //vec1.push_back(t);
            }
        i=j-1;
        }

        else
            checkpar_op((char)s[i]);

    }
}

int main()
{
   //
    freopen("input1.txt","r",stdin);
     while(getline(cin,s))
    {

    lexical();

    }

    for(int i=0;i<vec.size();i++)
    {
        cout<<"<"<<vec[i].first;
        if(vec[i].second!=0)
        {
            cout<<","<<vec[i].second;
        }
        cout<<"> "<<endl;
    }
    cout<<"Symbol Table\n";
    int sz=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<k;i++)
    {
        cout<<i+1<<"-"<<arr[i]<<endl;
    }

}
