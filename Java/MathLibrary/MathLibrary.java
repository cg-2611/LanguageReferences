public class MathLibrary {
	public static void main(String[] args) {
		// constants
		System.out.println("pi = " + Math.PI);
		System.out.println("e = " + Math.E);
		System.out.println();

		// absolute value
		System.out.println("|-9| = " + Math.abs(-9));
		System.out.println();

		// rounding
		System.out.println("Round 4.5 = " + Math.round(4.5));
		System.out.println("Ceil 3.2 =  " + Math.ceil(3.2));
		System.out.println("Floor 5.9= " + Math.floor(5.9));
		System.out.println();

		// division
		System.out.println("Floor 21 / 6 = " + Math.floorDiv(21, 6));
		System.out.println();

		// exponents
		System.out.println("2^8 = " + Math.pow(2, 8));
		System.out.println();

		// logarithms
		System.out.println("log_e 2 = " + Math.log(2));
		System.out.println("log_10 2 = " + Math.log10(2));
		System.out.println();

		// trigonometry
		System.out.println("sin((4 * pi) / 7) = " + Math.sin((4 * Math.PI) / 7));
		System.out.println("cos(pi/6) = " + Math.cos(Math.PI / 6));
		System.out.println("tan(0.4) = " + Math.tan(0.4));
		System.out.println();

		//angles
		System.out.println("90 degrees to radians = " + Math.toRadians(90));
		System.out.println("(6 * pi) / 4 radians to degrees = " + Math.toDegrees((6 * Math.PI) / 4));

	}
}