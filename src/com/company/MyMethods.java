package com.company;

import javax.swing.*;
import java.awt.*;

public class MyMethods {
    public static void CheckForWinning(Main _main, JButton[] _buttons) {
        boolean win = true;
        for (int i = 0; i < 16; ++i) {
            if (_buttons[i].getBackground() == Color.red) {
                win = false;
            }
        }
        if (win) {
            JOptionPane.showMessageDialog(_main.Window, "Oh my gosh, you WON!!!", "Congratulations", JOptionPane.INFORMATION_MESSAGE);
        }
        _main.Window.setFocusable(true);
    }

    public static void SetButtonColor(JButton button, int number) {
        String ButtonName = button.getText();
        int name = 0;
        if (!ButtonName.equals("")) {
            name = Integer.parseInt(ButtonName);
        }
        if (name == (number + 1) || (ButtonName.equals("") && number == 15)) {
            button.setBackground(Color.green);
        } else {
            button.setBackground(Color.red);
        }
    }

    public static void SwapButtons(int i, int new_i, JButton[] _buttons) {
        String name = _buttons[i].getText();
        String new_name = _buttons[new_i].getText();
        _buttons[i].setText(new_name);
        _buttons[new_i].setText(name);
        SetButtonColor(_buttons[i], i);
        SetButtonColor(_buttons[new_i], new_i);
    }
}
