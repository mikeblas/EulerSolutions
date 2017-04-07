import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/**
 * Created by mikeblas on 2017-04-06.
 */
public class LargestExponent {


    public static void main(String[] args) {

        try {
            BufferedReader br = new BufferedReader(new FileReader("p099_base_exp.txt"));

            double biggestD = 0;

            String line;
            int lineNumber = 0;
            int biggestLineNumber = 0;
            while (null != (line = br.readLine())) {
                // System.out.println(line);
                lineNumber++;

                // chop the line up
                String [] parts = line.split(",");
                int base = Integer.parseInt(parts[0]);
                int exponent = Integer.parseInt(parts[1]);

                // estimate the number of digits in the value of base ^ exponent
                double d = Math.log10(base) * exponent;
                if (d > biggestD) {
                    // biggest yet?
                    biggestD = d;
                    biggestLineNumber = lineNumber;
                }

                System.out.printf("%d, %d: %d, %d\n", lineNumber, biggestLineNumber, base, exponent);
            }

            System.out.printf("%d\n", biggestLineNumber);
        } catch (IOException e) {
            System.out.println(e);
        }

    }
}


