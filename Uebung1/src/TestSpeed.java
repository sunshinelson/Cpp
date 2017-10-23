/**
 * 
 */

/**
 * @author Davina Golomingi
 *
 */
public class TestSpeed {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int hM1 = 2;
		int hM2 = 6;
		int bM1 = 2;
		int bM2 = 4;
		Matrix m1 = new Matrix(hM1, bM1, 1);
		Matrix m2 = new Matrix(hM2, bM2);
		
		System.out.println("Matrix 1:");
		for(int h1 = 0; h1 < hM1; h1++) {
			for(int b1 = 0; b1 < bM1; b1++) {
				System.out.print(m1.getValue(h1, b1) + " ; ");
			}
			System.out.println();
		}
		
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
//			for(int br = 0; br < bM2; br++) {
//				System.out.print(mr.getValue(hr, br) + " ; ");
//			}
//			System.out.println();
//		}
//
//		System.out.println("Matrix R2:");
//		Matrix mr2 = m1.multiplyNative(m1);
//
//		for(int hr = 0; hr < hM1; hr++) {
//			for(int br = 0; br < bM2; br++) {
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

	}

}
