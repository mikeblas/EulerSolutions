import java.math.BigInteger;

/**
 * Created by mikeblas on 2017-04-08.
 */
public class Generator {

    private BigInteger s = BigInteger.valueOf(290797L);
    private static final BigInteger SIXTY_FOUR = BigInteger.valueOf(64L);
    private static final BigInteger MODULO = BigInteger.valueOf(50515093L);

    Generator() {
    }

    int getNext() {

        int ret = (int) (1L + s.mod(SIXTY_FOUR).longValueExact());

        s = s.multiply(s).mod(MODULO);

        return ret;

    }

}
