#include<stdio.h>
#include<string.h>
int main(){
    char s[100000],ss[100000];
    printf("enter a string-> ");
    gets(s);
    printf("enter a substring to delete from the given string-> ");
    gets(ss);//comparing the substring from the index i of length strlen(substring)
    for(int i=0;s[i]!='\0';i++){
        //if found then slide the strlen(substring) no. of charcater to the left
        //and  puting '\0' at the end
        if(strncmp(&s[i],ss,strlen(ss))==0){
            int j;//sliding character to left(that is overlapping the substring)
            //that is vanishing the substring
            for(j=i+strlen(ss);s[j]!='\0';j++){
                s[j-strlen(ss)]=s[j];
            }
            s[j-strlen(ss)]='\0';//putting null character at the end
            printf("%d\n",strlen(s));//i--;
        }
    }
    puts(s);
    return 0;
}
// int main(){

//     char s[100000],ss[100000];
//     printf("enter a string-> ");
//     gets(s);
//     printf("enter a substring to delete from the given string-> ");
//     gets(ss);//here substring is and
//     for(int i=0;s[i]!='\0';){
//         //checking if the substring is found at index i or not
//         if(strncmp(&s[i],ss,strlen(ss))==0){
//             //if found then don't print it and update the index
//             //index me lenght add kardo substring ka
//             i+=strlen(ss);
//         }//if not found then simply print the character and move forward(index++)
//         else{printf("%c",s[i]);i++;}
//     }
//     return 0;
// }
//Medicines and Bandaid must be kept in First aid box.


