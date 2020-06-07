import static org.junit.Assert.assertEquals;
 
import org.junit.Test;
 
public class improvedbinarysearch {
 
        public static int rank(char key, char[] a) {
        int mid = -1;
        int hi = a.length - 1;
        int lo = 0;
        while(lo <= hi) {
                System.out.print("Lo: " + lo + "\tHi: " + hi);
                mid = lo + (Math.max(hi, mid) - lo) / 2;
                System.out.println("\tMid: " + mid);
            if (key < a[mid]) {
                hi = mid - 1;
            }
            else if (key > a[mid]) {
                lo = mid + 1;
            }
            else return mid;
        }
        return -1;
    }
       
        @Test
        public void testimprovedbinarysearch() {
                char[] b = {'a','b','c','d','e'};
            assertEquals(1, rank('b',b));
            assertEquals(3, rank('d',b));
            assertEquals(4, rank('e',b));
            assertEquals(0, rank('a',b));
            assertEquals(-1, rank('0',b));
            assertEquals(-1, rank('f',b));
           
            char[] c = {};
            assertEquals(-1, rank('f',c));
 
            char[] d = {'a'};
            assertEquals(-1, rank('f',d));
            assertEquals(0, rank('a',d));
           
            char[] e = {'a', 'c', 'e', 'g', 'i', 'k', 'm', 'o'};
            assertEquals(-1, rank('d',e));
            assertEquals(2, rank('e',e));
            assertEquals(-1, rank('l',e));
            assertEquals(5, rank('k',e));
            assertEquals(-1, rank('f',e));
        }
       
        public static void main(String[] args) {
        char[] b = {'a','b','c','d','e'};
        System.out.println("Searching for " + 'b');
        int found = rank('b',b);
        System.out.println("\nFound at " + found + "\n");
        System.out.println("Searching for " + 'd');
        found = rank('d',b);
        System.out.println("\nFound at " + found + "\n");
    }
       
       
}