import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Comparator;

public class Day9 {

    public static void main(String[] args)  {
        int N = 25;
        try {
            BufferedReader reader = new BufferedReader ( new FileReader ( "input.txt" ) );
            ArrayList<Integer> array = new ArrayList<> ();
            ArrayList<Integer> input = new ArrayList<> ();
            /* part 1 */
            String line;
            for(int i = 0; i < N; i++){
                line = reader.readLine ();
                array.add (Integer.parseInt ( line ));
                input.add ( Integer.parseInt ( line ) );
            }
            int nr = 0;
            while((line = reader.readLine ()) != null) {
                nr = Integer.parseInt ( line );
                input.add ( nr );
                int ok = 0;
                for(int i = 0; i < N - 1 && ok == 0; i++) {
                    for(int j = i + 1; j < N; j++) {
                        if (array.get ( i ) + array.get ( j ) == nr) {
                            ok = 1;
                            break;
                        }
                    }
                }
                if(ok == 0){
                    System.out.println ( "number is = " + nr );
                    break;
                }

                array.remove ( 0 );
                array.add ( nr );
            }
            reader.close ();
            /* part 2*/
            array.clear ();
            for(int i = 0; i < input.size () - 1; i++) {
                int sum = input.get(i);
                array.add ( input.get ( i ) );

                for(int j = i + 1; j < input.size (); j++) {
                    sum += input.get ( j );
                    array.add ( input.get ( j ) );
                    if(sum == nr) {
                        array.sort ( Comparator.comparingInt ( o -> o ) );
                        System.out.println ("second part: " +
                                (array.get ( array.size () - 1 ) +
                                                        array.get ( 0 )));
                        return;
                    }
                    if(sum > nr){
                        array.clear ();
                        break;
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace ();
        }

    }
}
