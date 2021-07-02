import java.util.Random;

public class RandomNumbers {

    public static void main(String[] args) {
        // Math.random() bounds default to 0.0 - 0.999...
        // Math.random() * 4 changes bounds to 0.0 - 3.999...
        Double randomDouble = Math.random() * 8;

        System.out.println("Using Math.random():");
        System.out.println("Random double between 0 and 7.999...: " + randomDouble);
        System.out.println();

        // seed automatically generated use, Random(int seed) to specify a seed
        Random random = new Random();

        System.out.println("Using Random.nextInt():");
        System.out.println("Random int (no args): " + random.nextInt());
        System.out.println("Random int between 0 and 100: " + random.nextInt(101));
        System.out.println("Random int between 10 and 40: " + (random.nextInt(30) + 10));
        System.out.println();

        System.out.println("Using Random.nextDouble():");
        System.out.println("Random double: " + random.nextDouble());
        System.out.println("Random double between 1 and 2: " + (random.nextDouble() + 1));
        System.out.println();

        System.out.println("Using Random.nextBoolean(): ");
        System.out.println("Random boolean: " + random.nextBoolean());
    }

}
