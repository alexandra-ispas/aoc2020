package org.ea;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.*;

public class Day7 {
    /**
     * get all the bags which contain the given bag
     * @param bags a list of bags we look through
     * @param name given bag
     * @return a list with all the colors of the bags required
     */
    public static List<String> getAllBagsThatContains(List<Bag> bags, String name) {
        List<String> colors = new ArrayList<>();
        for(Bag bag : bags) {
            if(bag.containsBag(name)) {
                colors.add(bag.getColor ());
            }
        }
        return colors;
    }

    public static void main(String[] args) {
        String exception = "";
        try {
            BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
            List<Bag> allBags = new ArrayList<>();
            String line;
            while ((line = reader.readLine()) != null) {
                exception = line;
                allBags.add(new Bag(line));
            }

            Set<String> bags = new HashSet<>();
            bags.add("shiny gold");
            int nrOfBags = 0;
            while(true) {
                nrOfBags = bags.size();
                Set<String> newBags = new HashSet<>();
                for(String name : bags) {
                    newBags.addAll(getAllBagsThatContains(allBags, name));
                }
                int oldSize = bags.size ();
                bags.addAll(newBags);
                if(oldSize == bags.size ())
                    break;
            }
            System.out.println(nrOfBags - 1); //removing the shiny gold bag

            for (Bag b : allBags) {
                if (b.getColor ().equals("shiny gold")) {
                    System.out.println(b.nrOfBags (allBags) - 1);
                    break;
                }
            }

        } catch (Exception e) {
            System.out.println("Exception: " + exception);
            e.printStackTrace();
        }
    }
}