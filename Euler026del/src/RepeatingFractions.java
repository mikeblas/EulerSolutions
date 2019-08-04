import java.math.BigDecimal;
import java.math.RoundingMode;

/**
 * This brute-forces the problem by using BigDecimal to convert the reciprocal to
 * a decimal representation, then finding repeating characters in that representation.
 *
 * For me, the surprise was finding unique repeated digits. For example, when 1/7
 * repeats it causes 142857 to repeat again and again; care must be taken to consider
 * only "142857" and not "142857142857" for double the length.
 *
 * Intuitively, the answer must be a prime number -- and very close to the problem's
 * limit of 1000. Funny thing is, it's not the closest prime to 1000. Why is that?
 *
 */
public class RepeatingFractions {

    static final int SCALE = 3000;

    public static void main(String [] args) {

        int maxRepeatN = -1;
        int maxRepeatOut = -1;

        for (int n = 7; n <= 999; n++) {

            BigDecimal number = BigDecimal.ONE.divide(BigDecimal.valueOf(n), SCALE, RoundingMode.HALF_UP);

            String str = number.toString();
            // System.out.printf("%d: %s\n", n, str);


            int start = 2;
            int maxRepeat = -1;
            for (int second = 1; second < SCALE/2; second++) {
                if (str.charAt(start) == str.charAt(second+start)) {

                    boolean completed = true;
                    for (int check = start; check < second ; check++) {
                        if (str.charAt(check) != str.charAt(second + check)) {
                            completed = false;
                        }
                    }

                    if (completed) {
                        int repeat = second-start + 2;
                        // System.out.printf("repeat %d from %d to %d\n", repeat, start, start+second);
                        if (repeat == 2*maxRepeat) {
                            break;
                        }
                        if (repeat > maxRepeat) {
                            maxRepeat = repeat;
                        }
                    }
                }
            }

            // System.out.printf("n = %d, maxRepeat = %d\n", n, maxRepeat);

            if (maxRepeatOut < maxRepeat) {
                maxRepeatOut = maxRepeat;
                maxRepeatN = n;
            }
        }

        System.out.printf("maxRepeatN = %d, maxRepeatOut = %d\n", maxRepeatN, maxRepeatOut);
        BigDecimal number2 = BigDecimal.ONE.divide(BigDecimal.valueOf(maxRepeatN), 1000, RoundingMode.HALF_UP);
        System.out.printf(number2.toString());
    }
}

