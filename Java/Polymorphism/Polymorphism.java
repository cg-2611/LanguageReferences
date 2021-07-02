import java.util.ArrayList;

public class Polymorphism {

    public static void main(String[] args) {
        SuperClass superClass = new SuperClass();
        SuperClass subClassOne = new SubClassOne();
        SuperClass subClassTwo = new SubClassTwo();

        ArrayList<SuperClass> array = new ArrayList<SuperClass>();
        array.add(superClass);
        array.add(subClassOne);
        array.add(subClassTwo);

        for(int i = 0; i < array.size(); i++) {
            System.out.println();
            array.get(i).print();
        }
    }

}
