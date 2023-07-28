#include<stdio.h>
#include<string.h>
#define rep(i,n) for(int i=0;i<n;i++)

void givestr(char *a,int n,int m){
    int x=n+m,y=(n>m?n:m);
    char s[x][y+1];//making a array of strings
    //total no of string would be n+m=x
    //and max length of string is max(m,n)+1{+1 is for null character} 
    char *st=*s;//pointer pointing to base address of array of string(s)
    rep(i,n){
        rep(j,m){
            *(st)=*(a+i*m+j);st++;
            //*(a+i*m+j) this thing is making a string horizontally
        }
        *(st)='\0';//ending with null character to make a valid string
        st=*s+(i+1)*(y+1);//pointer jumping to next base address of string
    }int q=n;
    rep(j,m){
        rep(i,n){
            *(st)=*(a+i*m+j);st++;
            // *(a+i*m+j) this thing making a string vertically
        }
        *(st)='\0';//same ending with null character
        st=*s+(q+1)*(y+1);q++;//and jumping to next base address of next string
    }
    printf("\nbefore sorting :\n");
    rep(i,n+m){
        printf("%d->%s\n",i+1,(*s+i*(y+1)));
        //(*s+i*(y+1)) this thing is the base address of the strings
    }
    //after storing all the strings in array of strings
    //applying sorting algorithm
    rep(i,n+m){
        rep(j,n+m){
            if(strcmp(s[i],s[j])>0){
                char t[n+m];
                strcpy(t,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],t);
            }
        }
    }
    printf("\nafter sorting :\n");
    rep(i,n+m){
        printf("%d->%s\n",i+1,(*s+i*(y+1)));
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    char a[n][m];
    //taking input through user
    rep(i,n){
        rep(j,m){
            scanf("\n%c",(*a+i*m+j));
        }
    }
    givestr(*a,n,m);//passing base address of char matrix and n,m (size also)
    return 0;
}