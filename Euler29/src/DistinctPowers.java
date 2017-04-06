import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * This is a bit brutish, as it uses the complete precision of the powered numbers.
 * I think there's a relationship that can be inveted to elimiate factors of bases that
 * were previously encountered.
 */
public class DistinctPowers {


    public static void main(String[] args) {

        List<BigInteger> arrayList = new ArrayList<>();

        for (int a = 2; a <= 100; a++) {

            BigInteger big = BigInteger.valueOf(a);

            for (int b = 2; b <= 100; b++) {
                BigInteger power = big.pow(b);

                arrayList.add(power);

            }
        }

        Collections.sort(arrayList);


        Integer last = null;
        int count = 0;
        for (int n = 0; n < arrayList.size(); n++) {
            if (last == null || !arrayList.get(n).equals(arrayList.get(last))) {

                count++;
                System.out.printf("%s\n", arrayList.get(n).toString());
                last = n;
            }
        }

        System.out.printf("Total is %d\n", count);

    }
}

