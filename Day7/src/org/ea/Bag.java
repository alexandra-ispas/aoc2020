package org.ea;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Bag {
    private final String color;
    private final Map<String, Integer> contains = new HashMap<>();

    public Bag(String rule) {
        String[] sArr = rule.split(" bags contain ");
        color = sArr[0];
        rule = sArr[1];

        Pattern p = Pattern.compile("(\\d+) (\\w+ \\w+)"); // one decimal and 2 words for rule

        for (String s : rule.split(",")) {
            s = s.replaceAll("bags*\\.*", "").trim();
            Matcher m = p.matcher(s);
            if (m.find()) {
                contains.put(m.group(2), Integer.parseInt(m.group(1)));
            }
        }
    }

    public boolean containsBag(String name) {
        return contains.containsKey(name);
    }

    public String getColor() {
        return color;
    }

    private Bag findBag(List<Bag> allBags, String color) {
        for (Bag b : allBags) {
            if (b.getColor ().equals(color)) {
                return b;
            }
        }
        return null;
    }

    public long nrOfBags(List<Bag> allBags) {
        long numOfBags = 1;
        for(Map.Entry<String, Integer> bag : contains.entrySet()) {
            Bag foundBag = findBag(allBags, bag.getKey());
            assert foundBag != null;
            numOfBags += bag.getValue() * foundBag.nrOfBags (allBags);
        }
        return numOfBags;
    }
}