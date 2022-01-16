package com.company;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import static com.company.MyMethods.*;

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
        CheckForWinning(_main, _buttons);
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



    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        for (int i = 0; i < 16; ++i) {
            if (actionEvent.getSource() == _buttons[i]) {
                if (CheckTheClick(i) != 16) {
                    int new_i = CheckTheClick(i);
                    SwapButtons(i, new_i, _buttons);
                    break;
                }
            }
        }
        CheckForWinning(_main, _buttons);
        _main.Window.requestFocus();
    }
}
