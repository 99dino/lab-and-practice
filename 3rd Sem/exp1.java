import java.util.*;

public class exp1 {
        public static void main(String[] args) {
        FLOAT a = new FLOAT();
        System.out.println(a.x);
    }
}
class FLOAT {
    String x;
};


// public class exp1 {
// public static void main(String[] args) {
// int a = 1;
// while (a < 10) {
// switch (a) {
// case 1:
// System.out.println("One Sheep");
// break;
// case 2:
// System.out.println("Two Sheep");
// break;
// case 3:
// System.out.println("Three Sheep");
// break;
// case 4:
// System.out.println("Four Sheep");
// break;
// case 5:
// System.out.println("Five Sheep");
// break;
// case 6:
// System.out.println("Six Sheep");
// break;
// case 7:
// System.out.println("Seven Sheep");
// break;
// case 8:
// System.out.println("Eight Sheep");
// break;
// case 9:
// System.out.println("Nine Sheep");
// break;
// default:
// break;
// }a++;

// }
// }
// }

// public class exp1 {
// public static void main(String[] args) {
// Scanner sc=new Scanner(System.in);
// int n=sc.nextInt();
// int prime[]=new int[n+1];
// for(int i=0;i<=n;i++){prime[i]=1;}
// for(int i=2;i*i<=n;i++){
// if(prime[i]==1){
// for(int j=i*i;j<=n;j+=i){
// prime[j]=0;
// }
// }
// }
// System.out.println("Prime numbers upto "+n+ " are :");
// for(int i=2;i<n+1;i++){
// if(prime[i]==1){
// System.out.print(i+" ");
// }
// }
// System.out.println("");
// }
// }
// public class exp1 {
// public static void main(String[] args) {
// Float x= new Float();
// Float y= new Float();
// System.out.println("X= "+x.x);
// System.out.println("Y= "+y.x);

// x.update(12.45f);
// System.out.println("Changing X= "+12.45);
// System.out.println("changes occured in both the reference object");

// System.out.println("X= "+x.display());
// System.out.println("Y= "+y.display());
// }
// }
// class Float {
// float x;
// }