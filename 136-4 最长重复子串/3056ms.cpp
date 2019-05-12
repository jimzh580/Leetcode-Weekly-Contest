class Solution {
public:
    typedef long long ll;
    int P=998244353,P1=1000000007,base=233,base1=666;
    int h[100005],h1[100005],p[100005],p1[100005];
    set<pair<int,int>> s;
    string longestDupSubstring(string S) {
        int n=S.size(),i,j,k,l,r,mid;
        pair<int,int> o;
        for(i=h[0]=0;i<n;i++)h[i+1]=((ll)h[i]*base+S[i])%P;
        for(i=h1[0]=0;i<n;i++)h1[i+1]=((ll)h1[i]*base1+S[i])%P1;
        for(i=p[0]=1;i<=n;i++)p[i]=(ll)p[i-1]*base%P;
        for(i=p1[0]=1;i<=n;i++)p1[i]=(ll)p1[i-1]*base1%P1;
        l=0;
        r=n;
        while(l+1<r)
        {
            mid=l+r>>1;
            s.clear();
            for(i=mid;i<=n;i++)
            {
                j=(h[i]+(ll)(P-h[i-mid])*p[mid])%P;
                k=(h1[i]+(ll)(P1-h1[i-mid])*p1[mid])%P1;
                o=make_pair(j,k);
                if(s.find(o)==s.end())s.insert(o);
                else break;
            }
            if(i>n)r=mid;
            else l=mid;
        }
        s.clear();
        for(i=l;i<=n;i++)
        {
            j=(h[i]+(ll)(P-h[i-l])*p[l])%P;
            k=(h1[i]+(ll)(P1-h1[i-l])*p1[l])%P1;
            o=make_pair(j,k);
            if(s.find(o)==s.end())s.insert(o);
            else break;
        }
        string ans="";
        for(j=i-l;j<i;j++)ans+=S[j];
        return ans;
    }
};