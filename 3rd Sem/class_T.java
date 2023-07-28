import java.util.*;
// write a program to implement multiple inheritance 

// person 
// @student    @teacher
// class_T

interface Person {
    public abstract void this_person_says();
}

interface Student extends Person {
    public void student_says();
}

interface Teacher extends Person {
    public void teacher_says();
}

public class class_T implements Student, Teacher {
    class_T() {
        System.out.println("Constructor of class_T invoked");
    }
    public void this_person_says() {
        System.out.println("It says PERSON interface");
    }
    public void student_says() {
        System.out.println("It says STUDENT interface");
    }
    public void teacher_says() {
        System.out.println("It says TEACHER interface");
    }

    public static void main(String[] args) {
        class_T obj = new class_T();
        obj.this_person_says();
        obj.student_says();
        obj.teacher_says();
    }
}