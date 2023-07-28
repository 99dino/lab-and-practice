import java.util.*;
import java.lang.*;

class compare {
    public static void comp(String a, String b) {
        boolean ans = a.equals(b);
        if (ans == false)
            System.out.println(a + " is not equal to " + b);
        else
            System.out.println(a + " is equal to " + b);
    }
}

public class ok {
    public static void main(String[] args) {
        compare dog = new compare();
        dog.comp("hello", "hello");
    }
}
