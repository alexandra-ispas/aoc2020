import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Test {

    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader ( new FileReader ( "input.txt" ) );
            Map<Integer, String> input = new HashMap<> ();
            String line;
            int idx = 0;
            while((line = reader.readLine ()) != null){
                input.put ( idx++, line );
            }
            int acc = 0;
            ArrayList<Integer> visited = new ArrayList<> ();
            idx = 0;
            while(idx < input.size ()) {
                visited.add ( idx );
                Map.Entry<Integer, String> entry = Day8.getEntry ( input, idx );
                assert entry != null;
                String[] sArr = entry.getValue ().split ( " " );
                switch (sArr[0]) {
                    case "acc" -> {
                        acc += Integer.parseInt ( sArr[1] );
                        idx++;
                    }
                    case "nop" -> idx++;
                    case "jmp" -> {
                        int idx2 = idx + 1, acc2 = acc;
                        ArrayList<Integer> visited2 = new ArrayList<> ( visited );
                        int ok = 0;
                        while (ok == 0) {
                            if (visited2.contains ( idx2 ))
                                ok = 1; //loop
                            if (idx2 == input.size ()) { // reached the end
                                System.out.print ( "success at " + acc2 );
                                return;
                            }
                            visited2.add ( idx2 );
                            Map.Entry<Integer, String> entry2 = Day8.getEntry ( input, idx2 );
                            assert entry2 != null;
                            String[] sArr2 = entry2.getValue ().split ( " " );
                            switch (sArr2[0]) {
                                case "acc" -> {
                                    acc2 += Integer.parseInt ( sArr2[1] );
                                    idx2++;
                                }
                                case "nop" -> idx2++;
                                case "jmp" -> idx2 += Integer.parseInt ( sArr2[1] );
                            }
                        }
                        idx += Integer.parseInt ( sArr[1] );
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace ();
        }
    }
}
