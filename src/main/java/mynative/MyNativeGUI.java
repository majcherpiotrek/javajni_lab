package mynative;

public class MyNativeGUI {
	
	public static void main(String[] args) {
		System.out.println("Starting!");
		MyNative mynative = new MyNative();
		
		//	MULTI01
		Double a[] = {1.0, 2.0, 3.0};
		Double b[] = {1.0, 2.0, 3.0};
		mynative.setA(a);
		mynative.setB(b);
		
		System.out.println("\nCouting multi01!");
		String a_string = "a as parameter: ";
		String b_string = "b as parameter: ";
		for (int i=0; i<a.length; i++) {
			a_string += a[i] + " ";
			b_string += b[i] + " ";
		}
		System.out.println(a_string);
		System.out.println(b_string);
		Double d = mynative.multi01(a, b);
		System.out.println("Result: " + d);
		////////////////////////////////////
		
		//	MULTI02
		System.out.println("\nCouting multi02!");
		a_string = "a as parameter: ";
		b_string = "b from object: ";
		Double a_param[] = {11.0, 3.0, 0.0};
		b = mynative.getB();
		for (int i=0; i<a_param.length; i++) {
			a_string += a_param[i] + " ";
			b_string += b[i] + " ";
		}
		System.out.println(a_string);
		System.out.println(b_string);
		d = mynative.multi02(a_param);
		System.out.println("Result: " + d);
		//////////////////////////////////////
		
		//	MULTI03
		System.out.println("\nCouting multi03!");
		mynative.multi03();
		a = mynative.getA();
		b = mynative.getB();
		
		a_string = "a from object: ";
		b_string = "b from object : ";
		for (int i=0; i<a.length; i++) {
			a_string += a[i] + " ";
			b_string += b[i] + " ";
		}
		System.out.println(a_string);
		System.out.println(b_string);
		System.out.println("Result from object:" + mynative.getC());
		///////////////////////////////////////////////
	}
	
	
}
