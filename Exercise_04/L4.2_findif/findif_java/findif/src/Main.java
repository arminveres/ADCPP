import java.text.DecimalFormat;
import java.util.Collection;
import java.util.Vector;

public class Main {

    private static <E> void startFinder(Collection<E> collection, Matcher<E> matcher) {
        long start = System.nanoTime();
        E elem = Finder.findIf(collection.iterator(), matcher);
        long stop = System.nanoTime();

        double time = (stop - start)/1000000000.0;
        DecimalFormat f = new DecimalFormat("0.00");

        if (elem != null) {
            System.out.println("Found match in " + f.format(time) + " seconds.");
        }
    }

    public static void main(String[] args) {

        int size = 200000001;

        Vector<Integer> collection = new Vector<>();

        for (int i = 0; i < size; i++) {
            collection.add(i);
        }

        for (int i = 0; i < 10; i++) {
            startFinder(collection, elem -> elem == 200000000);
        }
    }
}
