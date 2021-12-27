package com.company;

import javax.swing.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import static com.company.MyMethods.*;

public class KeyGameLogic extends KeyAdapter {

    JButton[] _buttons = new JButton[16];
    Main _main;

    public KeyGameLogic(JButton[] buttons, Main main) {
        _main = main;
        System.arraycopy(buttons, 0, _buttons, 0, 16);
        _main.Window.setFocusable(true);
    }

    @Override
    public void keyPressed(KeyEvent keyEvent) {
        int empty_cell = 0;
        for (int i = 0; i < 16; ++i) {
            if (_buttons[i].getText().equals("")) {
                empty_cell = i;
            }
        }
        int i_empty = empty_cell / 4;
        int j_empty = empty_cell % 4;
        Cell empty = new Cell(i_empty, j_empty);
        if (keyEvent.isControlDown()) {
            if (keyEvent.getKeyCode() == KeyEvent.VK_UP) {
                int new_i;
                while (empty.Up()) {
                    new_i = empty_cell - 4;
                    SwapButtons(empty_cell, new_i, _buttons);
                    empty_cell = new_i;
                    empty.SetI(new_i / 4);
                }
            }
            if (keyEvent.getKeyCode() == KeyEvent.VK_DOWN) {
                int new_i;
                while (empty.Down()) {
                    new_i = empty_cell + 4;
                    SwapButtons(empty_cell, new_i, _buttons);
                    empty_cell = new_i;
                    empty.SetI(new_i / 4);
                }
            }
            if (keyEvent.getKeyCode() == KeyEvent.VK_LEFT) {
                int new_j;
                while (empty.Left()) {
                    new_j = empty_cell - 1;
                    SwapButtons(empty_cell, new_j, _buttons);
                    empty_cell = new_j;
                    empty.SetJ(new_j % 4);
                }
            }
            if (keyEvent.getKeyCode() == KeyEvent.VK_RIGHT) {
                int new_j;
                while (empty.Right()) {
                    new_j = empty_cell + 1;
                    SwapButtons(empty_cell, new_j, _buttons);
                    empty_cell = new_j;
                    empty.SetJ(new_j % 4);
                }
            }
        }
        if (keyEvent.getKeyCode() == KeyEvent.VK_UP && empty.Up()) {
            int new_i = empty_cell - 4;
            SwapButtons(empty_cell, new_i, _buttons);
        }
        if (keyEvent.getKeyCode() == KeyEvent.VK_DOWN && empty.Down()) {
            int new_i = empty_cell + 4;
            SwapButtons(empty_cell, new_i, _buttons);
        }
        if (keyEvent.getKeyCode() == KeyEvent.VK_LEFT && empty.Left()) {
            int new_i = empty_cell - 1;
            SwapButtons(empty_cell, new_i, _buttons);
        }
        if (keyEvent.getKeyCode() == KeyEvent.VK_RIGHT && empty.Right()) {
            int new_i = empty_cell + 1;
            SwapButtons(empty_cell, new_i, _buttons);
        }
        CheckForWinning(_main, _buttons);
    }
}
