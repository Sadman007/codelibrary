import java.math.*;
import java.util.*;

class Main {

	public static void main(String[] args) {

		final Scanner sc = new Scanner(System.in);

		int n;

		while (sc.hasNext()) {
			List<BigInteger> arr = new ArrayList<BigInteger>();

			while (sc.hasNext() && ((n = sc.nextInt()) != -999999))
				arr.add(BigInteger.valueOf(n));

				BigInteger res = arr.get(0);

				for (int i = 0, sz = arr.size(); i < sz; i++) {
					BigInteger cur = arr.get(i);
					res = res.max(cur);

					for (int j = i + 1; j < sz; j++) {
						cur = cur.multiply(arr.get(j));
						res = res.max(cur);
					}
				}
				System.out.println(res);
			}

		}

}
