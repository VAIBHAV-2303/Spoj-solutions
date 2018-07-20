    import java.util.Scanner;
    import java.math.BigInteger;
    class Myclass{
    	
    	static BigInteger power(int a, int b, BigInteger m){
    		if(b==0){
    			return BigInteger.ONE.mod(m);
    		}
    		BigInteger half = power(a, b >> 1, m);
    		half = half.multiply(half);
    		if(b % 2 == 1){
    			half = half.multiply(BigInteger.valueOf(a));
    		}
    		return half.mod(m);
    	}
     
    	public static void main(String[] args){
    		Scanner sc = new Scanner(System.in);
    		int t = sc.nextInt();
    		while(t>=1){
    			int a = sc.nextInt();
    			int b = sc.nextInt();
    			BigInteger m = sc.nextBigInteger();
    			System.out.println(power(a, b, m));
    			t--;
    		}
    	}
    } 
