import java.util.*;
import java.math.*;
public class Main{
	
	public static void main(String args[]) {
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		BigInteger ans[]=new BigInteger[10];
		ans[1]=BigInteger.valueOf(1);
		ans[2]=BigInteger.valueOf(5);
		ans[3]=BigInteger.valueOf(16);
		for (int i=4;i<=n;i++) {
			ans[4]=ans[3].multiply(BigInteger.valueOf(3));
			ans[4]=ans[4].subtract(ans[2]);
			ans[4]=ans[4].add(BigInteger.valueOf(2));
			for (int j=1;j<=3;j++) ans[j]=ans[j+1];
		}
		if (n<=3) System.out.println(ans[n]);
		else System.out.println(ans[4]);
		cin.close();
	}
}