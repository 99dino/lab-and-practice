import java.util.*;
public class exp3 {
    public static void main(String[] args) {
        // System.out.println("passed\n");
        qwerty ok=new qwerty(10,20,30);
        System.out.println(ok.a+"\n"+ok.b);
    }
    
}
class qwerty{
    int a,b;
    qwerty(int a,int b){
        this.a=a;
        this.b=b;
    }
    qwerty(int a,int b,int c){
        this(b,a);
    }
}

// public class exp3 {
//     public static void main(String[] args) {
//         qwerty ok=new qwerty();
//         System.out.println("A class without a constructor");
//         System.out.println(ok.a);
//         System.out.println("There is no constructor given still It gives value 0");
//     }
    
// }
// class qwerty{
//     int a;
// }
// public class exp3 {
//     public static void main(String[] args) {
//         Scanner sc=new Scanner(System.in);
//         Dog kutta= new Dog();
//         kutta.bark(1);
//         kutta.bark(69.69f);
//         kutta.bark(true);
//     }
// }
// class Dog{
//     void bark(int a){
//         System.out.println("Dog is Barking");
//     }
//     void bark(float a){
//         System.out.println("Dog is Howling");
//     }
//     void bark(boolean a){
//         System.out.println("Dog is Haurr-Grrrr");
//     }
// }
