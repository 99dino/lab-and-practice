#include<stdio.h>
int main(){
    int ly,t,days,months=0,year;
    printf("if leap year enter 1 else 0 = ");
    scanf("%d",&ly);
    printf("enter totoal no of days = ");
    scanf("%d",&t);
    if(ly==1){
        int a[12]={31,29,31,30,31,30,31,31,30,31,30,31};
        year=t/366;
        int dl=t-366*year;
        for(int i=0;i<12;i++){
            if(dl-a[i]>=0){
                months++;dl=dl-a[i];
            }else{break;}
        }
        printf("%d days equals = %d years %d months and %d days",t,year,months,dl);
    }
    else{
        int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        year=t/365;
        int dl=t-365*year;
        for(int i=0;i<12;i++){
            if(dl-a[i]>=0){
                months++;dl=dl-a[i];
            }else{break;}
        }
        printf("%d days equals = %d years %d months and %d days",t,year,months,dl);
    }

    return 0;
}