#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define N 50000
using namespace std;
int dp[2][N],ls,lt;
char read1_file_name[N],read2_file_name[N],out_file_name[N];
string s,t;
char l1[N],l2[N];
int main(){
	scanf("%s %s %s",read1_file_name,read2_file_name,out_file_name);
	if (freopen(read1_file_name,"r",stdin)==NULL){
		printf("原文绝对路径出错\n");
		return 0;
	}
	else printf("读入原文成功\n");
	while (scanf("%s",l1)!=EOF)
		for (int i=0;l1[i];i++)
    		if (l1[i]<0)
				s+=l1[i];
	if (freopen(read2_file_name,"r",stdin)==NULL){
		printf("抄袭文绝对路径出错\n");
		return 0;
	}
	else printf("读入抄袭文成功\n");
    while (scanf("%s",l2)!=EOF)
    	for (int i=0;l2[i];i++)
    		if (l2[i]<0)
    			t+=l2[i];
    freopen(out_file_name,"w",stdout);
    ls=s.length(),lt=t.length();
	for (int i=1;i<ls;i++){
		int now=i%2;
        for (int j=1;j<lt;j++)
			if (dp[now][j-1]==i) dp[now][j]=dp[now][j-1];
			else
            if (s[i-1]==t[j-1])
                dp[now][j]=dp[now^1][j-1]+1;
            else
                dp[now][j]=max(dp[now^1][j],dp[now][j-1]);
    }
    cout<<1.0*dp[(ls-1)%2][lt-1]/(ls-1)<<endl;
    return 0;
}
