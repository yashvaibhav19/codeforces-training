#include<bits/stdc++.h>
using namespace std;

template<typename T>
vector<int> manacher(int n,const T &s)
{
    if(n<1) return vector<int>({});
    vector<int> res(2*n-1,0);
    int l=-1,r=-1;
    for(int z=0;z<2*n-1;z++)
    {
        int i=(z+1)/2,j=z/2;
        int p=(i>=r?0:min(r-i,res[2*(l+r)-z]));
        while(j+1+p<n && i-1-p>=0 && s[i-1-p] == s[j+1+p]) p++;
        if(j+p>r)
        {
            l=i-p;
            r=j+p;
        }
        res[z]=p;
    }
    return res;
}

int main()
{
    string s="abba";
    vector<int> ans=manacher(s.length(),s);
    for(auto x:ans) cout<<x<<" ";
    return 0;
}
