import java.util.*;
public class main_overload {
    public static void main(String[] args) {
        Graph<Character> graph = new UnweightedGraph<>();
        graph.addVertex('U');
        graph.addVertex('V');
        int indexForU = graph.getIndex('U');
        int indexForV = graph.getIndex('V');
        System.out.println("indexForU is " + indexForU);
        System.out.println("indexForV is " + indexForV);
        graph.addEdge(indexForU, indexForV);
        System.out.println("Degree of U is " + graph.getDegree(indexForU));
        System.out.println("Degree of V is " + graph.getDegree(indexForV));
        // graph.getDegree(indexForV));
    }
}

/*
 * public class main_overload{
 * //static keyword is used to avoid creating an instance of this class to use
 * this methods
 * public static void main(char a) {
 * //print the ASCII value of the given character
 * System.out.println("ASCII value of the given character is "+ (int)(a)+".");
 * }
 * public static void main(int n) {
 * //print the prime numbers upto n
 * int prime[]=new int[n+1];
 * for(int i=0;i<n;i++){prime[i]=1;}
 * for(int i=2;i*i<=n;i++){
 * if(prime[i]==1){
 * for(int j=i*i;j<=n;j+=i){
 * prime[j]=0;
 * }
 * }
 * }
 * System.out.println("Prime numbers upto "+n+ " are :");
 * for(int i=2;i<n+1;i++){
 * if(prime[i]==1){
 * System.out.print(i+" ");
 * }
 * }
 * System.out.println("");
 * }
 * public static void main(String name) {
 * // prints the length of the name
 * System.out.println("The length of the given name is "+name.length()+".");
 * }
 * public static void main(String[] args) {
 * 
 * //main function is overloaded having char as a formal parameters
 * main('a');
 * 
 * //main function is overloaded having integers as a formal parameters
 * main(40);
 * 
 * //main function is overloaded having String as a formal parameters
 * main("Priyanshu");
 * }
 * }
 */