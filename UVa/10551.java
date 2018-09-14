import java.io.*;
import java.util.*;
import java.math.*;
class Main{
  public static void main(String args[])
  {
	  Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	    while (true)
	    {
	      int base = in.nextInt();

	      if (base == 0) break;

	      String a = in.next();
	      String b = in.next();

	      BigInteger biga = new BigInteger(a, base);
	      BigInteger bigb = new BigInteger(b, base);
	      System.out.println(biga.mod(bigb).toString(base));
  }
  }
}
