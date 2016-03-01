/*
 *   Copyright (C) 2016 NikitaProAndroid, Quarx2
*/

package randomator;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Random;

public class Main {

    public static void main(String[] args) throws java.io.IOException {
        long counter = 0, startTime = System.currentTimeMillis();
        BufferedReader input = new BufferedReader(new FileReader("input.txt"));
        PrintWriter output = new PrintWriter(new FileWriter("output.txt"));

        String str = input.readLine();
        input.close();
        StringBuilder originalString = new StringBuilder(str);
        StringBuilder currentString = new StringBuilder(str);
        char tmp;

        Random rand = new Random(System.currentTimeMillis());
        int randomVal1, randomVal2, length = originalString.length();

        do {
            randomVal1 = rand.nextInt(length);
            randomVal2 = rand.nextInt(length);
            tmp = currentString.charAt(randomVal1);
            currentString.setCharAt(randomVal1, currentString.charAt(randomVal2));
            currentString.setCharAt(randomVal2, tmp);
            counter++;
        } while (!originalString.toString().equals(currentString.toString()));
        if (counter > 1) {
            output.println("SUCCESSFULLY FINISHED! Final string: " +
                    currentString + " Attemps: " + counter + " Time(ms): " + (System.currentTimeMillis() - startTime));
        } else {
            output.println("You are lucky, selected positions for replacing symbols are the same in first attemp!");
        }
        output.close();
    }
}
