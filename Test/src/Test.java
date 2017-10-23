
public class Test {

	static {
		System.loadLibrary("NativeFunctions");
	}
	
	public static native void display();
	public static native int increment(int value);

	

	public static void main(String[] args) {
		
//		String path = System.getProperty("java.library.path");
//		System.out.println(path);
		display();
		System.out.println(increment(3));
		
	}
}