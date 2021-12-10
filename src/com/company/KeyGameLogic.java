package com.company;

import javax.swing.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import static com.company.MouseGameLogic.SetButtonColor;

public class KeyGameLogic implements KeyListener {

    JButton[] _buttons = new JButton[16];
    Main _main;

    public KeyGameLogic(JButton[] buttons, Main main) {
        _main = main;
        for (int i = 0; i < 16; ++i) {
            _buttons[i] = buttons[i];
        }
        _main.Window.setFocusable(true);
    }


    @Override
    public void keyTyped(KeyEvent keyEvent) {

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
        if (keyEvent.getKeyCode() == KeyEvent.VK_UP && empty.Up()) {
            int new_i = empty_cell - 4;
            String name = _buttons[empty_cell].getText();
            String new_name = _buttons[new_i].getText();
            _buttons[empty_cell].setText(new_name);
            _buttons[new_i].setText(name);
        }
        if (keyEvent.getKeyCode() == KeyEvent.VK_DOWN && empty.Down()) {
            int new_i = empty_cell + 4;
            String name = _buttons[empty_cell].getText();
            String new_name = _buttons[new_i].getText();
            _buttons[empty_cell].setText(new_name);
            _buttons[new_i].setText(name);
        }
        if (keyEvent.getKeyCode() == KeyEvent.VK_LEFT && empty.Left()) {
            int new_i = empty_cell - 1;
            String name = _buttons[empty_cell].getText();
            String new_name = _buttons[new_i].getText();
            _buttons[empty_cell].setText(new_name);
            _buttons[new_i].setText(name);
        }
        if (keyEvent.getKeyCode() == KeyEvent.VK_RIGHT && empty.Right()) {
            int new_i = empty_cell + 1;
            String name = _buttons[empty_cell].getText();
            String new_name = _buttons[new_i].getText();
            _buttons[empty_cell].setText(new_name);
            _buttons[new_i].setText(name);
        }
        if (keyEvent.isControlDown()) {
            if (keyEvent.getKeyCode() == KeyEvent.VK_UP) {
                for (int i = 0; i < 16; ++i) {
                    if (_buttons[i].getText().equals("")) {
                        empty_cell = i;
                    }
                }
                int new_i;
                while (empty.Up()) {
                    new_i = empty_cell - 4;
                    String name = _buttons[empty_cell].getText();
                    String new_name = _buttons[new_i].getText();
                    _buttons[empty_cell].setText(new_name);
                    _buttons[new_i].setText(name);
                    empty_cell = new_i;
                    empty.SetI(new_i / 4);
                }
            }
            if (keyEvent.getKeyCode() == KeyEvent.VK_DOWN) {
                for (int i = 0; i < 16; ++i) {
                    if (_buttons[i].getText().equals("")) {
                        empty_cell = i;
                    }
                }
                int new_i;
                while (empty.Down()) {
                    new_i = empty_cell + 4;
                    String name = _buttons[empty_cell].getText();
                    String new_name = _buttons[new_i].getText();
                    _buttons[empty_cell].setText(new_name);
                    _buttons[new_i].setText(name);
                    empty_cell = new_i;
                    empty.SetI(new_i / 4);
                }
            }
            if (keyEvent.getKeyCode() == KeyEvent.VK_LEFT) {
                for (int i = 0; i < 16; ++i) {
                    if (_buttons[i].getText().equals("")) {
                        empty_cell = i;
                    }
                }
                int new_j;
                while (empty.Left()) {
                    new_j = empty_cell - 1;
                    String name = _buttons[empty_cell].getText();
                    String new_name = _buttons[new_j].getText();
                    _buttons[empty_cell].setText(new_name);
                    _buttons[new_j].setText(name);
                    empty_cell = new_j;
                    empty.SetJ(new_j % 4);
                }
            }
            if (keyEvent.getKeyCode() == KeyEvent.VK_RIGHT) {
                for (int i = 0; i < 16; ++i) {
                    if (_buttons[i].getText().equals("")) {
                        empty_cell = i;
                    }
                }
                int new_j;
                while (empty.Right()) {
                    new_j = empty_cell + 1;
                    String name = _buttons[empty_cell].getText();
                    String new_name = _buttons[new_j].getText();
                    _buttons[empty_cell].setText(new_name);
                    _buttons[new_j].setText(name);
                    empty_cell = new_j;
                    empty.SetJ(new_j % 4);
                }
            }
        }
        for (int i = 0; i < 16; ++i) {
            SetButtonColor(_buttons[i], i);
        }
    }

    @Override
    public void keyReleased(KeyEvent keyEvent) {

    }

}
