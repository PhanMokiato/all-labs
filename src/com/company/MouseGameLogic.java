package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MouseGameLogic implements ActionListener {

    JButton[] _buttons = new JButton[16];
    Main _main;
    KeyGameLogic _klogic;

    public MouseGameLogic(JButton[] buttons, Main main, KeyGameLogic klogic) {
        _klogic = klogic;
        _main = main;
        for (int i = 0; i < 16; ++i) {
            _buttons[i] = buttons[i];
            _buttons[i].addActionListener(this);
            SetButtonColor(_buttons[i], i);
        }
        CheckForWinning();
        _main.Window.addKeyListener(klogic);
        _main.Window.setFocusable(true);
    }

    public int CheckTheClick(int index) {
        int i = index / 4;
        int j = index % 4;
        String neighbor;
        Cell check_cell = new Cell(i, j);
        if (check_cell.Right()) {
            neighbor = _buttons[index + 1].getText();
            if (neighbor.equals("")) {
                return index + 1;
            }
        }
        if (check_cell.Left()) {
            neighbor = _buttons[index - 1].getText();
            if (neighbor.equals("")) {
                return index - 1;
            }
        }
        if (check_cell.Up()) {
            neighbor = _buttons[index - 4].getText();
            if (neighbor.equals("")) {
                return index - 4;
            }
        }
        if (check_cell.Down()) {
            neighbor = _buttons[index + 4].getText();
            if (neighbor.equals("")) {
                return index + 4;
            }
        }
        return 16;
    }

    public void CheckForWinning() {
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

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        for (int i = 0; i < 16; ++i) {
            if (actionEvent.getSource() == _buttons[i]) {
                if (CheckTheClick(i) != 16) {
                    int new_i = CheckTheClick(i);
                    String name = _buttons[i].getText();
                    String new_name = _buttons[new_i].getText();
                    _buttons[i].setText(new_name);
                    _buttons[new_i].setText(name);
                    SetButtonColor(_buttons[i], i);
                    SetButtonColor(_buttons[new_i], new_i);
                    break;
                }
            }
        }
        CheckForWinning();
        _main.Window.setFocusable(true);
        _main.Window.requestFocus();
        _main.Window.setFocusable(true);
    }
}
