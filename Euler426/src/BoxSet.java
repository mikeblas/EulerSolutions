/**
 * Created by mikeblas on 2017-04-09.
 */
public class BoxSet {

    private boolean [] boxes;

    private boolean noisy = true;

    void setNoisy(boolean noisy) {
        this.noisy = noisy;
    }

    int size() {
        return boxes.length;
    }

    static BoxSet initialize(PairList list) {

        BoxSet bs = new BoxSet();

        int boxCount = list.getTotalLength();
        bs.boxes = new boolean[boxCount];
        System.out.printf("total size is %d, index is %d\n", boxCount, list.size());

        int walker = 0;
        for (int index = 0; index < list.size(); index++) {

            for (int worker = 0; worker < list.getOccupied(index); worker++) {
                bs.boxes[walker++] = true;
            }
            for (int worker = 0; worker < list.getEmpty(index); worker++) {
                bs.boxes[walker++] = false;
            }
        }

        return bs;
    }


    String getBoxString() {

        return getBoxString(boxes);
    }

    static String getBoxString(boolean [] boxes) {
        StringBuilder builder = new StringBuilder();

        for (int n = 0; n < boxes.length; n++) {
            builder.append( boxes[n] ? '*' : '-');
        }

        return builder.toString();
    }

    String getStateString() {

        StringBuilder builder = new StringBuilder("{ ");

        boolean occupied = true;
        int count = 0;
        boolean first = true;
        for (int n = 0; n < boxes.length; n++ ) {
            if (occupied) {
                if (boxes[n]) {
                    count++;
                } else {
                    occupied = false;
                    if (!first) builder.append(", ");
                    first = false;
                    builder.append(String.format("%d ", count));
                    count = 1;
                }
            } else {
                if (!boxes[n]) {
                    count++;
                } else {
                    occupied = true;
                    builder.append(String.format(", %d ", count));
                    count = 1;
                }
            }
        }

        builder.append(String.format(", %d}", count));
        return builder.toString();
    }

    String getConciseStateString() {

        StringBuilder builder = new StringBuilder("{ ");

        boolean occupied = true;
        int count = 0;
        boolean first = true;
        for (int n = 0; n < boxes.length; n++ ) {
            if (occupied) {
                if (boxes[n]) {
                    count++;
                } else {
                    occupied = false;
                    if (!first) builder.append(", ");
                    first = false;
                    builder.append(String.format("%d ", count));
                    count = 1;
                }
            } else {
                if (!boxes[n]) {
                    count++;
                } else {
                    occupied = true;
                    count = 1;
                }
            }
        }

        builder.append(String.format(", %d}", count));
        return builder.toString();
    }


    boolean iterate() {

        boolean[] newBoxes = new boolean[boxes.length * 2 + 2];
        int maxUsed = -1;
        int minUsed = Integer.MAX_VALUE;

        for (int n = 0; n < boxes.length; n++) {
            if (boxes[n]) {
                for (int m = n; ; m++) {
                    if (!newBoxes[m] && (m >= boxes.length || !boxes[m])) {
                        newBoxes[m] = true;
                        maxUsed = m;
                        minUsed = Math.min(m, minUsed);
                        break;
                    }
                }
            }
        }


        if (noisy) {
            System.out.printf("before: %s\n", BoxSet.getBoxString(boxes));
            System.out.printf("after : %s\n", BoxSet.getBoxString(newBoxes));
        }

        boolean [] trimmedBoxes = new boolean[maxUsed - minUsed + 1];
        System.arraycopy(newBoxes, minUsed, trimmedBoxes, 0, trimmedBoxes.length);

        if (noisy) {
            System.out.printf("copied: %s\n", BoxSet.getBoxString(trimmedBoxes));
        }

        boolean shouldContinue = shouldIterate2(boxes, trimmedBoxes);

        if (!boxes[0]) throw new IllegalStateException("boxes didn't begin with a ball");
        if (!trimmedBoxes[0]) throw new IllegalStateException("trimmed boxes didn't begin with a ball");


        boxes = trimmedBoxes;
        return shouldContinue;
    }


    boolean shouldIterate(boolean [] boxes, boolean [] trimmedBoxes) {

        boolean shouldContinue = false;

        int n = 1;
        int m = 1;
        boolean inBalls = true;
        while (n < boxes.length && m < trimmedBoxes.length) {

            if (inBalls) {
                int nBalls = 1;
                while (boxes[n++] && n < boxes.length) {
                    nBalls++;
                }

                int mBalls = 1;
                while (trimmedBoxes[m++] && m < trimmedBoxes.length) {
                    mBalls++;
                }

                if (mBalls != nBalls) {
                    shouldContinue = true;
                    break;
                }
                inBalls = false;
            } else {
                while (!boxes[n++] && n < boxes.length) {
                }

                while (!trimmedBoxes[m++] && m < trimmedBoxes.length) {
                }

                inBalls = true;
            }
        }

        return shouldContinue;
    }

    boolean shouldIterate2(boolean [] boxes, boolean [] trimmedBoxes) {

        boolean shouldContinue = false;

        int n = 1;
        int m = 1;
        boolean inBalls = true;
        int lastNBalls = -1;
        while (n < boxes.length && m < trimmedBoxes.length) {

            if (inBalls) {
                int nBalls = 1;
                while (boxes[n++] && n < boxes.length) {
                    nBalls++;
                }

                int mBalls = 1;
                while (trimmedBoxes[m++] && m < trimmedBoxes.length) {
                    mBalls++;
                }

                if (mBalls != nBalls) {
                    shouldContinue = true;
                    break;
                }

                if (lastNBalls > nBalls) {
                    shouldContinue = true;
                    break;
                }
                lastNBalls = nBalls;

                inBalls = false;
            } else {
                while (!boxes[n++] && n < boxes.length) {
                }

                while (!trimmedBoxes[m++] && m < trimmedBoxes.length) {
                }

                inBalls = true;
            }
        }

        return shouldContinue;
    }

}
