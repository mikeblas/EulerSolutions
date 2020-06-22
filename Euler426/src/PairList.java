import java.util.LinkedList;
import java.util.List;

/**
 * Created by mikeblas on 2017-04-09.
 */
public class PairList {

    private static final class Pair {
        int occupied;
        int empty;
    }

    final private List<Pair> list = new LinkedList<>();

    PairList() {
    }

    static PairList fromGenerator(Generator gen, int n) {

        PairList list = new PairList();

        for (int count = 0; count < n / 2; count++) {
            int occupied = gen.getNext();
            int empty = gen.getNext();
            list.add(occupied, empty);
            // System.out.printf("%d, %d\n", occupied, empty);
        }

        int lastOccupied = gen.getNext();
        list.add(lastOccupied, 0);
        // System.out.printf("%d, -\n", lastOccupied);
        return list;
    }

    void add(int occupied, int empty) {
        Pair p = new Pair();
        p.occupied = occupied;
        p.empty = empty;
        list.add(p);
    }
    int getTotalLength() {
        int total = 0;
        for (Pair p : list) {
            total += p.empty;
            total += p.occupied;
            // System.out.printf("%d: %d, %d\n", total, p.occupied, p.empty);
        }
        return total;
    }

    int size() {
        return list.size();
    }

    int getOccupied(int index) {
        return list.get(index).occupied;
    }

    int getEmpty(int index) {
        return list.get(index).empty;
    }
}
