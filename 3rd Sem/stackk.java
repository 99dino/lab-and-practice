import java.util.ArrayList;

@SuppressWarnings("unchecked")
class Stack<T> {
    private final ArrayList<T> elements;

    public Stack() {
        elements = new ArrayList<T>(100);
    }

    public void push(T value) {
        elements.add(value);
    }

    public void pop() {
        if (!elements.isEmpty()) {
            System.out.println(elements.remove(elements.size() - 1));
            // throw new stackexception("nothing to remove");
        } else {
            System.out.println("nono");
        }
    }
}

public class stackk {
    public static void main(String[] args) {
        Stack ok = new Stack();
        ok.push(10);
        ok.push(40);
        ok.push(60);
        ok.push(70);
        ok.push(30);
        ok.pop();
        ok.pop();
        ok.pop();
        ok.pop();
        ok.pop();

    }

}