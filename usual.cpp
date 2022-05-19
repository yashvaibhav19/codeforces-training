#include<iostream>
using namespace std;

int main()
{
	string s;
    cin>>s;
    s=")"+s;
    int n=s.length();
    int maxi=0,cnt=0;
    stack<int> unclosed;
    unclosed.push(0);
    rep(i,1,n)
    {
        if(s[i]=='(')
        {
            unclosed.push(i);
            continue;
        }
        if(s[unclosed.top()]=='(')
        {
            unclosed.pop();
            int l=i-unclosed.top();
            maxi=max(maxi,l);
            continue;
        }
        unclosed.push(i);
    }
    if(!maxi) {cnt=1; goto print;}
    while(unclosed.size()) unclosed.pop();
    unclosed.push(0);
    rep(i,1,n)
    {
        if(s[i]=='(')
        {
            unclosed.push(i);
            continue;
        }
        if(s[unclosed.top()]=='(')
        {
            unclosed.pop();
            int l=i-unclosed.top();
            if(l==maxi) cnt++;
            continue;
        }
        unclosed.push(i);
    }
    print:
    cout<<maxi<<" "<<cnt;
	return 0;
}