import java.util.*;
// import java.util.LinkedList*;

public class linkedlist {
    public static void display(LinkedList<Integer> ll) {
        // for (int i : ll)
        // System.out.print(i + " ");
        System.out.println(ll);
    }

    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        list.add(9);
        list.add(8);
        list.add(7);
        display(list);
        list.add(1, 1);
        display(list);
        list.add(2, 2);
        display(list);
        list.add(3, 1);
        display(list);
        list.add(4, 3);
        display(list);
        list.remove(list.get(2));
        display(list);
        list.remove(list.get(3));
        display(list);
        list.clear();
        display(list);
    }
}