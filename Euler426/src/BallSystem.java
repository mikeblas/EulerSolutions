

/**
 * Created by mikeblas on 2017-04-08.
 */
public class BallSystem {

    static void test1() {
        Generator gen = new Generator();
        PairList list = PairList.fromGenerator(gen, 10);
        BoxSet set = BoxSet.initialize(list);

        String stateString = set.getStateString();
        System.out.println(stateString);

        while (set.iterate()) {
            ;
        }

        System.out.println(set.getConciseStateString());

        /*
        for (int n = 0; n < 25; n++) {
            set.iterate();
        }
        */
    }


    static void test2() {
        Generator gen = new Generator();
        PairList list = new PairList();
        list.add(2, 2);
        list.add(2, 1);
        list.add(2, 0);

        BoxSet set = BoxSet.initialize(list);

        System.out.println(set.getBoxString());

        while (set.iterate()) {
            ;
        }

    }

    static void test3() {
        Generator gen = new Generator();
        PairList list = PairList.fromGenerator(gen, 1000000);
        BoxSet set = BoxSet.initialize(list);

        set.setNoisy(false);
        System.out.println("Initialized");

        int iteration = 0;
        while (set.iterate()) {
            System.out.printf("iteration %d, size is %d\n", set.size());
        }

        System.out.println(set.getConciseStateString());
    }

    public static void main(String [] args) {

        test3();


    }

}
