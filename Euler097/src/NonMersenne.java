import java.math.BigInteger;

/**
 * Created by mikeblas on 2017-04-06.
 */
public class NonMersenne {

    public static void main(String[] args) {

        BigInteger base = BigInteger.valueOf(2);
        BigInteger exponent = base.pow(7830457);
        BigInteger product = exponent.multiply(BigInteger.valueOf(28433));
        BigInteger add = product.add(BigInteger.ONE);

        String result = add.toString();

        System.out.printf("%d\n", result.length());

        System.out.printf("%s\n", result.substring(result.length() - 10));


    }

}
