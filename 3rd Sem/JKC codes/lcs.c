#include<stdio.h>
#include<string.h>
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int lcs(int n,int m,char s1[],char s2[]){
    if(m<0 || n<0){
        return 0;
    }
    int ans=lcs(n-1,m,s1,s2);
    ans=max(ans,lcs(n,m-1,s1,s2));
    ans=max(ans,(s1[n]==s2[m])+lcs(n-1,m-1,s1,s2));
    return ans;
}
int lcs_ans(char s1[],char s2[]){
    int n=strlen(s1);
    int m=strlen(s2);
    //printf("%d\n",n);
    //printf("%d\n",m);
    return lcs(n-1,m-1,s1,s2);
}
int main(){
    char s1[100],s2[100];
    printf("Enter string 1:\n");
    scanf("%s",s1);
    printf("Enter string 2:\n");
    scanf("%s",s2);
    printf("%d\n",lcs_ans(s1,s2));
    return 0;
}