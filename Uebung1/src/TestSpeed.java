/**
 * 
 */

/**
 * @author Davina Golomingi
 *
 */
public class TestSpeed {
	private static long startTime, stopTime, elapsedTime;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//Zeitmessungen Aufgabe 1
		System.out.println("Zeitmessungen Aufgabe 1");
	    Matrix mA = new Matrix(500, 6000);
	    Matrix mB = new Matrix(6000, 400);
	    System.out.println("Java Teil:");
	    startTime = System.currentTimeMillis();
	    Matrix resJ = mA.multiply(mB);
	    stopTime = System.currentTimeMillis();
	    elapsedTime = stopTime - startTime;
	    System.out.println(elapsedTime + " Milisekunden.");
	    System.out.println();
	    System.out.println("C++ Teil:");
	    startTime = System.currentTimeMillis();
	    Matrix resC = mA.multiplyNative(mB);
	    stopTime = System.currentTimeMillis();
	    elapsedTime = stopTime - startTime;
	    System.out.println(elapsedTime + " Milisekunden.");
	    System.out.println();
	    String gleich;
	    if(resJ.equals(resC)) {
	    	gleich = "ja";
	    }else {
	    	gleich = "nein";
	    }
	    
	    System.out.println("Sind beide Resultate gleich? " + gleich);
	    System.out.println();
	    
	    //Zeitmessungen Aufgabe 2
	    Matrix mM = new Matrix(250, 250);
	    System.out.println("Zeitmessungen Aufgabe 2");
	    System.out.println("Java Teil:");
	    startTime = System.currentTimeMillis();
	    Matrix resJ2 = mM.power(91);
	    stopTime = System.currentTimeMillis();
	    elapsedTime = stopTime - startTime;
	    System.out.println(elapsedTime + " Milisekunden.");
	    System.out.println();
	    System.out.println("C++ Teil:");
	    startTime = System.currentTimeMillis();
	    Matrix resC2 = mM.powerNative(91);
	    stopTime = System.currentTimeMillis();
	    elapsedTime = stopTime - startTime;
	    System.out.println(elapsedTime + " Milisekunden.");
	    System.out.println();
	    if(resJ2.equals(resC2)) {
	    	gleich = "ja";
	    }else {
	    	gleich = "nein";
	    }
	    
	    System.out.println("Sind beide Resultate gleich? " + gleich);
	    System.out.println();

		System.out.println("-------------------------------------------------");
		int hM1 = 2;
		int bM1 = 2;
		int hM2 = 6000;
		int bM2 = 400;
		Matrix m1 = new Matrix(hM1, bM1);
		Matrix m2 = new Matrix(hM2, bM2);
		
		System.out.println("Matrix 1:");
		for(int h1 = 0; h1 < hM1; h1++) {
			for(int b1 = 0; b1 < bM1; b1++) {
				System.out.print(m1.getValue(h1, b1) + " ; ");
			}
			System.out.println();
		}
		

//		
//		System.out.println("Matrix 2:");
//		for(int h2 = 0; h2 < hM2; h2++) {
//			for(int b2 = 0; b2 < bM2; b2++) {
//				System.out.print(m2.getValue(h2, b2) + " ; ");
//			}
//			System.out.println();
//		}
	
//		Matrix mr = m1.multiply(m1);
//		System.out.println("Matrix R:");
//		for(int hr = 0; hr < hM1; hr++) {
//			for(int br = 0; br < bM1; br++) {
//				System.out.print(mr.getValue(hr, br) + " ; ");
//			}
//			System.out.println();
//		}
//
//		System.out.println("Matrix R2:");
//		Matrix mr2 = m1.multiplyNative(m1);
//
//		for(int hr = 0; hr < hM1; hr++) {
//			for(int br = 0; br < bM1; br++) {
//				System.out.print(mr2.getValue(hr, br) + " ; ");
//			}
//			System.out.println();
//		}
//		System.out.println(mr.equals(mr2));
		
		Matrix m3 = m1.power(5);
		System.out.println("Matrix pow1:");
		for(int hr = 0; hr < hM1; hr++) {
			for(int br = 0; br < bM1; br++) {
				System.out.print(m3.getValue(hr, br) + " ; ");
			}
			System.out.println();
		}	
		

		
		Matrix m4 = m1.powerNative(5);
		System.out.println("Matrix pow2:");
		for(int hr = 0; hr < hM1; hr++) {
			for(int br = 0; br < bM1; br++) {
				System.out.print(m4.getValue(hr, br) + " ; ");
			}
			System.out.println();
		}
		
		System.out.println(m3.equals(m4));
		
		

	}

}
