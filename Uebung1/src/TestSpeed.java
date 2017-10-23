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
	
	    //Typische Ausgabe
//	    Zeitmessungen Aufgabe 1
//	    Java Teil:
//	    11265 Milisekunden.
//
//	    C++ Teil:
//	    9601 Milisekunden.
//
//	    Sind beide Resultate gleich? ja
//
//	    Zeitmessungen Aufgabe 2
//	    Java Teil:
//	    2116 Milisekunden.
//
//	    C++ Teil:
//	    1666 Milisekunden.
//
//	    Sind beide Resultate gleich? nein --> Annahme: es handelt sich um Rundungsfehler (diese wurden bei der AUsgabe von kleinere Matrizen auch z.T. festgestellt)

	}

}
