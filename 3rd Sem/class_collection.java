import java.util.*;

public class class_collection {

    // generic method printArray
    public static <T> void printArray(T[] inputArray) {
        // display array elements
        for (T element : inputArray)
            System.out.print(element + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        Integer[] intArray = { 1, 2, 3, 4, 5 };
        Double[] doubleArray = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
        Character[] charArray = { 'P', 'R', 'I', 'Y', 'A', 'N', 'S', 'H', 'U' };
        printArray(intArray);// pass an Integer array
        printArray(doubleArray);// pass a Double array
        printArray(charArray);// pass a Character array
    }
}