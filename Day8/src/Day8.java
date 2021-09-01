import java.util.Map;
import java.util.Objects;

public class Day8 {
    public static Map.Entry<Integer, String> getEntry(Map<Integer, String> input, Integer idx) {
        for(Map.Entry<Integer, String> entry : input.entrySet ()){
            if(Objects.equals ( entry.getKey (), idx )){
                return entry;
            }
        }
        return null;
    }
}
