import java.util.*;

// public class assgn3 {

//     public static boolean equals(int[] arr1, int[] arr2){
//         Arrays.sort(arr1);
//         Arrays.sort(arr2);
//         int n=arr1.length;
//         int m=arr2.length;
//         if(n!=m){return false;}
//         else{
//             for(int i=0;i<n;i++){
//                 if(arr1[i]!=arr2[i]){
//                     return false;
//                 }
//             }
//             return true;
//         }
//     }
//     public static void main(String[] args) {
//         Scanner inp=new Scanner(System.in);
//         System.out.print("Enter length of array1: ");
//         int n=inp.nextInt();
//         int arr1[]=new int[n];
//         System.out.println("Enter "+n+" elments.");
//         for(int i=0;i<n;i++){
//             arr1[i]=inp.nextInt();
//         }
//         System.out.print("Enter length of array2: ");
//         int m=inp.nextInt();
//         int arr2[]=new int[m];
//         System.out.println("Enter "+m+" elments.");
//         for(int i=0;i<m;i++){
//             arr2[i]=inp.nextInt();
//         }
//         if(equals(arr1,arr2)){
//             System.out.println("identical");

//         }
//         else{
//             System.out.println("not identical");
//         }
        
//     }
// }

// public class assgn3 {

//     public static int [] remove_duplicacy(int arr[],int n) {
//         int k=0;
//         ArrayList<Integer> distinct = new ArrayList<Integer>();
//         for(int i=0;i<n;i++){
//             int count=0;
//             for(int j=0;j<i;j++){
//                 if(arr[j]==arr[i]){
//                     count++;
//                 }
//             }
//             if(count==0){
//                 distinct.add(arr[i]);
//             }
//         }
//         int ok[]=new int[distinct.size()];
//         for(int i=0;i<distinct.size();i++){
//             ok[i]=distinct.get(i);
//         }
//         return ok;

//     }
//     public static void main(String[] args) {
//         Scanner inp=new Scanner(System.in);
//         System.out.print("Enter length of array: ");
//         int n=inp.nextInt();
//         int arr[]=new int[n];
//         System.out.println("Enter "+n+" elments.");
//         for(int i=0;i<n;i++){
//             arr[i]=inp.nextInt();
//         }
//         int []ans=remove_duplicacy(arr,n);
//         System.out.println("After removing Duplicates element: ");
//         for(int i=0;i<ans.length;i++){
//             System.out.print(ans[i]+" ");
//         }
//     }
// }

// public class assgn3 {
//     public static void main(String[] args) {
//         Scanner inp=new Scanner(System.in);
//         System.out.print("Enter length of array: ");
//         int n=inp.nextInt();
//         int arr[]=new int[n];
//         System.out.println("Enter "+n+" elments.");
//         for(int i=0;i<n;i++){
//             arr[i]=inp.nextInt();
//         }
//         for(int i=0;i<=n-4;i++){
//             if(arr[i]==arr[i+1]&&arr[i+1]==arr[i+2]&&arr[i+2]==arr[i+3]){
//                 System.out.println("hai 4 consecutive same numebrs");return;
//             }
//         }
//         System.out.println("nahi hai 4 ek saath same number");
//     }
// }
// public class assgn3 {

//     public static void main(String[] args) {
//         Scanner inp=new Scanner(System.in);
//         System.out.print("Enter String 1: ");
//         String str1=inp.nextLine();
//         System.out.print("Enter String 2: ");
//         String str2=inp.nextLine();
//         if(str1.contains(str2)){
//             System.out.println(str2+" is the substring of "+str1);
//         }
//         else{
//             System.out.println(str2+" is not the substring of "+str1);
//         }
//     }
// }

// DDD-DD-DDDD
// public class assgn3 {
//     public static boolean check(String s) {
//         if(s.length()!=11){
//             return false;
//         }
//         for(int i=0;i<s.length();i++){
//             if(i==3||i==6){
//                 if(s.charAt(i)!='-')
//                     return false;
//             }
//             else if(s.charAt(i)<'0'||s.charAt(i)>'9'){
//                 return false;
//             }
//         }
//         return true;
//     }

//     public static void main(String[] args) {
//         Scanner inp=new Scanner(System.in);
//         System.out.print("Enter a SSN: ");
//         String s=inp.nextLine();
//         if(check(s)){
//             System.out.println("valid input");
//         }
//         else{
//             System.out.println("invalid input");
//         }
//     }
// }

// public class assgn3 {

//     public static void main(String[] args) {
//         Scanner inp=new Scanner(System.in);
//         System.out.print("Enter String 1: ");
//         String str1=inp.nextLine();
//         System.out.print("Enter String 2: ");
//         String str2=inp.nextLine();
//         int i=0,j=0;
//         while(i<str1.length()&&j<str2.length()){
//             if(str1.charAt(i)!=str2.charAt(j)){
//                 break;
//             }
//             i++;j++;
//         }
//         if(i!=0){
//             System.out.print("Common Prefix is: ");
//             for(int k=0;k<i;k++){
//                 System.out.print(str1.charAt(k));
//             }
//         }
//         else{
//             System.out.println("NO common prefix");
//         }
//     }
// }

// public class assgn3 {

//     public static boolean  eight(String s){
//         if(s.length()>=8)
//             return true;
//         else 
//             return false;
//     }
//     public static boolean  letterdigit(String s){
//         for(int i=0;i<s.length();i++){
//             if(!Character.isLetter(s.charAt(i))&&!Character.isDigit(s.charAt(i)))
//                 return false;
//         }
//         return true;

//     }
//     public static boolean  twodigit(String s){
//         int count=0;
//         for(int i=0;i<s.length();i++){
//             if(Character.isDigit(s.charAt(i)))
//                 count++;
//         }
//         if(count>=2)
//             return true;
//         else
//             return false;
//     }
//     public static void main(String[] args) {
//         Scanner inp=new Scanner(System.in);
//         System.out.print("Enter your Password: ");
//         String str=inp.next();
//         if(twodigit(str)&&letterdigit(str)&&eight(str)){
//             System.out.println("Password is valid");
//         }
//         else{
//             System.out.println("Password is not valid");
//         }
//     }
// }
// public class assgn3 {
//     public static int countLetters(String s){
//         int count=0;
//         for(int i=0;i<s.length();i++){

//             if(Character.isLetter(s.charAt(i)))
//             count++;
//         }
//         return count;
//     }
//     public static void main(String[] args) {
//         Scanner inp=new Scanner(System.in);
//         System.out.print("Enter a String: ");
//         String word=inp.next();
//         System.out.println("No of Letter in "+word+" is "+countLetters(word));
//     }
// }








