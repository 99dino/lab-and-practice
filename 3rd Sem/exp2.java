import java.util.*;
// public class exp2 {
//     public static void main(String[] args) {
//         Dog dog1= new Dog();
//         Dog dog2= new Dog();
//         dog1.name="spot";
//         dog1.say="ruff";
//         dog2.name="scruffy";
//         dog2.say="bhau bhau";

//         System.out.println("Name : "+dog1.name+"\n"+"Say: "+dog1.say);
//         System.out.println("Name : "+dog2.name+"\n"+"Say: "+dog2.say);
        
//         Dog newDog;
//         newDog=dog1;
//         System.out.println("Name : "+newDog.name+"\n"+"Say: "+newDog.say);
//         if(dog1==dog2){
//             System.out.println("Dog1 reference variable equals to equals to Dog2 reference variable\n");
//         }
//         else{
//             System.out.println("Dog1 reference variable not equals to equals to Dog2 reference variable\n");
//         }
//         if(dog1==newDog){
//             System.out.println("Dog1 reference variable equals to newDog reference variable\n");
//         }
//         else{
//             System.out.println("Dog1 reference variable not equals to newDog reference variable\n");
//         }
//         if(dog2==newDog){
//             System.out.println("Dog2 reference variable equals to newDog reference variable\n");
//         }
//         else{
//             System.out.println("Dog2 reference variable not equals to newDog reference variable\n");
//         }
//     }
// }

// class Dog {
//     String name;
//     String say;
// }

// public class exp2 {
//     public static void check (String a, String b) {
//         //gives true if string a is equal to string b
//         if(a.equals(b)){
//             System.out.println(a+" equals to "+b);
//         }
//         else {
//             System.out.println(a+" not equals to "+b);
//         }
//         // Returns true if string a is equal to string b; it is case insensitive.
//         System.out.println("\nIgnoring case");
//         if(a.equalsIgnoreCase(b)){
//             System.out.println(a+" equals to "+b);
//         }
//         else{

//             System.out.println(a+" not equals to "+b);
//         }
//         // Returns an integer greater than 0, equal to 0, or less than 0 to indicate whether this string is >, =, < s1
//         if(a.compareTo(b)==0){
//             System.out.println(a+" equals to "+b);
//         }
//         else if(a.compareTo(b)<0){
//             System.out.println(a+" is less than "+b);
//         }
//         else{
//             System.out.println(a+" is greater than "+b);
//         }
//         // Returns an integer greater than 0, equal to 0, or less than 0 to indicate whether this string is >, =, < s1
//         // it is case insensitive
//         System.out.println("\nIgnoring case");
//         if(a.compareToIgnoreCase(b)==0){
//             System.out.println(a+" equals to "+b);
//         }
//         else if(a.compareToIgnoreCase(b)<0){
//             System.out.println(a+" is less than "+b);
//         }
//         else{
//             System.out.println(a+" is greater than "+b);
//         }
//     }
//     public static void main(String[] args) {
//         Scanner sc=new Scanner(System.in);
//         System.out.println("Enter string 1:" );
//         String a=sc.next();
//         System.out.println("Enter string 2:" );
//         String b=sc.next();
//         check(a,b);
//     }    
// }
