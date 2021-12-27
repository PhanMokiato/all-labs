package com.company;

import javax.swing.*;
import java.util.Random;

public class Buttons {
    JButton[] OurButtons = new JButton[16];
    int[] numbers = new int[16];

    public void SetFirstButtons(JFrame window) {
        Random first_numbers = new Random();
        int number;
        for (int i = 0; i < 16; ++i) {
            boolean different = true;
            number = first_numbers.nextInt(16);
            numbers[i] = number;
            for (; ;) {
                for (int l = 0; l < i; ++l) {
                   if (numbers[l] == numbers[i]) {
                       different = false;
                   }
                }
                if (different) {
                    break;
                } else {
                    number = first_numbers.nextInt(16);
                    numbers[i] = number;
                    different = true;
                }
            }
            if (number != 0) {
                OurButtons[i] = new JButton(String.valueOf(number));
            } else {
                OurButtons[i] = new JButton("");
            }
            window.add(OurButtons[i]);
        }
    }
}
