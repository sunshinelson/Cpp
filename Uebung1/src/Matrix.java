
/*
 * @ Author: Davina Golomingi
 * Matrixklasse für Uebung 1 prcpp HS17
 */

public class Matrix {
	private double[][] matrix;
	private int hoehe, breite;
	
	/**
	 * 1. Konstruktor initilisiert Matrix mit angegebene Höhe und Breite mit Zufallswerte
	 * @param breite
	 * @param hoehe
	 */
	public Matrix(int hoehe, int breite) {
		this.hoehe = hoehe;
		this.breite = breite;
		this.matrix = new double[hoehe][breite];
		fillRandom();
	}
	
	/**
	 * 2. Konstruktor initilisiert Matrix mit angegebene Höhe und Breite mit initWert
	 * @param breite
	 * @param hoehe
	 * @param initWert
	 */
	public Matrix( int hoehe, int breite, double initWert) {
		this.hoehe = hoehe;
		this.breite = breite;
		this.matrix = new double[hoehe][breite];
		fillValue(initWert);
	}
	

	/**
	 * 3. Konstruktor initilisiert Matrix mit angegebene Höhe und Breite unt init Array
	 * @param breite
	 * @param hoehe
	 * @param initMatrix
	 */
	public Matrix( int hoehe, int breite, double[][] initMatrix) {
		this.hoehe = hoehe;
		this.breite = breite;
		this.matrix = initMatrix;
	}	
	
	/**
	 * @param m
	 * @return das Resultat der Multiplikation als neue Matrix
	 */
	public Matrix multiply(Matrix m) {
		//Resultat
		Matrix r = new Matrix(hoehe, m.getBreite(), 0);
		//Multiplikation ist nur möglich wenn Breite der 1. Matrix == Höhe der 2. ist
		if(breite == m.getHoehe()){
			//Matrix A (This)
			double[][] a = this.matrix;
			int breiteA = breite;
			//Matrix B (m)
			double[][] b = m.getMatrix();
			//Matrix r (Result)
			int hoeheR = hoehe;
			int breiteR = m.getBreite();
			
			for(int rh=0; rh < hoeheR; rh++) {
				for(int rb=0; rb < breiteR; rb++){
					double res = 0;
					for(int i = 0; i < breiteA; i++) {
						res = res + (a[rh][i] * b[i][rb]);
					}
					r.setValue(rh, rb, res);
				}
			}	
		}
		return r;
	}
	
	/**
	 * @param m
	 * @return true, wenn beide Matrizen gleich sind
	 */
	public boolean equals(Matrix m) {
		//wenn beide Matrizen nicht gleich gross sind, können sie nicht gleich sein ->Abbruch return false
		if(hoehe == m.getHoehe() && breite == m.getBreite()) {
			for(int h = 0; h < hoehe; h++) {
				for(int b = 0; b < breite; b++) {
					//falls ein Wert nicht übereinstimmt können Matrizen nicht gleich sein -> Abbruch retur false
					if(this.matrix[h][b] != m.getMatrix()[h][b]) {
						return false;
					}
				}
			}
		}else {
			return false;
		}
		return true;
	}
	
	/**
	 * C++ Implementation
	 * @param m
	 * @return das Resultat der Multiplikation als neue Matrix
	 */
	public Matrix multiplyNative(Matrix m) {
		double[] a = transform2To1Array(this.matrix, this.hoehe, this.breite);
		double[] b = transform2To1Array(m.getMatrix(), m.getHoehe(), m.getBreite());
		double[] r = new double[this.hoehe * m.getBreite()];
		int i = this.hoehe;
		int j = m.getBreite();
		int k = this.breite;
		multiplyC(a, b, r, i, j, k);	
		double[][] r2 = transform1To2Array(r, m.getBreite());
		Matrix res = new Matrix(i, j, r2);
		return res;
	}
	
	private double[][] transform1To2Array(double[] a1, int step){
		int h = a1.length / step;
		int b = step;
		double[][] a2 = new double[h][b];
		boolean validA1 = (a1.length % step) == 0;
		int a = 0;
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < b; j++) {
				if( validA1) {
					a2[i][j] = a1[a];
					a++;
				}else {
					a2[i][j] = 0;
				}
			}
		}
		return a2;
	}
	
	private double[] transform2To1Array(double[][] a2, int h, int b){
		double[] a1 = new double[h*b];
		int a = 0;
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < b; j++) {
				a1[a] = a2[i][j];
				a++;
			}
		}
		return a1;
	}
	
	private Matrix fillRandom() {
		for(int h = 0; h < hoehe; h++) {
			for(int b = 0; b < breite; b++) {
				matrix[h][b] = Math.random();
			}
		}
		return this;
		
	}
	
	private Matrix fillValue(double init) {
		for(int h = 0; h < hoehe; h++) {
			for(int b = 0; b< breite; b++) {
				this.matrix[h][b] = init;
			}
		}
		return this;
	}
	
	private void setValue(int hoehe, int breite, double wert) {
		this.matrix[hoehe][breite] = wert;
	}
	
	/**
	 * @param a Matrix als double Array 
	 * @param b Matrix als double Array
	 * @param r Matrix (Resultat) als double Array
	 * @param i Höhe Matrix a
	 * @param j Breite Matrix b
	 * @param k Breite Matric a == Höhe Matrix b
	 */
	native void multiplyC(double[] a, double[] b, double[] r, int i, int j, int k);
	
	static {
		System.loadLibrary("NativeMatrixFunctions");
	}

	//getters
	public int getHoehe() {
		return hoehe;
	}

	public int getBreite() {
		return breite;
	}

	public double[][] getMatrix() {
		return matrix;
	}
	
	public double getValue(int hoehe, int breite) {
		return this.matrix[hoehe][breite];
	}
	
}
