import java.util.*;
import java.lang.*;
// implement stack

public class stackkkk {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = 1, data;
        Stack<Integer> st = new Stack<Integer>();
        do {
            System.out.println("1.PUSH\n2.POP\n3.DISPLAY\n4.QUIT");
            a = sc.nextInt();
            switch (a) {
                case 1:
                    System.out.println("Enter element to push into stack");
                    data = sc.nextInt();
                    st.push(data);
                    break;
                case 2:
                    System.out.print("Popped element is :");
                    st.pop();
                    break;
                case 3:
                    System.out.println(st);
                    break;
                case 4:
                    System.out.println("Bye Bye");
                    break;
                default:
                    System.out.println(("Invalid operation"));
                    break;
            }
        } while (a != 4);
    }
}
