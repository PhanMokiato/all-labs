package com.company;

import javax.swing.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class KeyCode implements KeyListener {

    Main _mai;

    public KeyCode(Main mai) {
        _mai = mai;
        _mai.Text.addKeyListener(this);
        _mai.Window.setFocusable(true);
    }


    @Override
    public void keyTyped(KeyEvent keyEvent) {
    }

    @Override
    public void keyPressed(KeyEvent keyEvent) {

        int caret = _mai.Text.getCaretPosition();
        String the_text = _mai.Text.getText();
        int current_string_start = 0;
        int current_string_end = 0;
        boolean caret_is_here = false;
        for (int i = 0; i < the_text.length(); ++i) {
            if (i == caret) {
                caret_is_here = true;
            }
            if (i == the_text.length() - 1) {
                if (caret == the_text.length()) {
                    caret_is_here = true;
                }
            }
            if (the_text.charAt(i) == '\n' || i == the_text.length() - 1) {
                if (caret_is_here) {
                    if (i == the_text.length() - 1) {
                        current_string_end = i;
                    } else {
                        current_string_end = i - 1;
                    }
                    break;
                } else {
                    current_string_start = i + 1;
                }
            }
        }


        if (keyEvent.isControlDown()) {
            if (keyEvent.getKeyCode() == KeyEvent.VK_D) {
                String copy_string = the_text.substring(current_string_start, current_string_end + 1);
                String new_text;
                if (current_string_end == the_text.length() - 1) {
                    new_text = the_text + "\n" + copy_string;
                } else {
                    String first_part = the_text.substring(0, current_string_end + 1);
                    String second_part = the_text.substring(current_string_end + 1);
                    new_text = first_part + "\n" + copy_string + second_part;
                }
                _mai.Text.setText(new_text);
            }
            if (keyEvent.getKeyCode() == KeyEvent.VK_X) {
                String first_part;
                if (current_string_start == 0) {
                    first_part = "";
                } else {
                    first_part = the_text.substring(0, current_string_start - 1);
                }
                String new_text;
                if (current_string_end == the_text.length() - 1) {
                    new_text = first_part;
                } else {
                    String second_part = the_text.substring(current_string_end + 1);
                    new_text = first_part + second_part;
                }
                _mai.Text.setText(new_text);
            }
        }


        if (keyEvent.isControlDown() && keyEvent.isShiftDown()) {

            if (keyEvent.getKeyCode() == KeyEvent.VK_UP && current_string_start != 0) {
                int upper_string_start = 0;
                for (int i = current_string_start - 2; i > 0; --i) {
                    if (the_text.charAt(i - 1) == '\n') {
                        upper_string_start = i;
                        break;
                    }
                }
                int upper_string_end = current_string_start - 1;
                String first_part = the_text.substring(0, upper_string_start);
                String the_changed_strings = the_text.substring(current_string_start, current_string_end + 1) + "\n" + the_text.substring(upper_string_start, upper_string_end);
                String second_part;
                if (current_string_end != the_text.length() - 1) {
                    second_part = the_text.substring(current_string_end + 1);
                } else {
                    second_part = "";
                }
                String new_text = first_part + the_changed_strings + second_part;
                _mai.Text.setText(new_text);
            }

            if (keyEvent.getKeyCode() == KeyEvent.VK_DOWN && current_string_end != the_text.length() - 1) {
                int lower_string_start = current_string_end + 2;
                int lower_string_end = 0;
                for (int i = current_string_end + 2; i < the_text.length(); ++i) {
                    if (the_text.charAt(i) == '\n') {
                        lower_string_end = i - 1;
                        break;
                    }
                    if (i == the_text.length() - 1) {
                        lower_string_end = i;
                    }
                }
                String first_part;
                if (current_string_start == 0) {
                    first_part = "";
                } else {
                    first_part = the_text.substring(0, current_string_start);
                }
                String new_upper_string;
                if (lower_string_end == the_text.length() - 1) {
                    new_upper_string = the_text.substring(lower_string_start);
                } else {
                    new_upper_string = the_text.substring(lower_string_start, lower_string_end + 1);
                }
                String new_lower_string = the_text.substring(current_string_start, current_string_end + 1);
                String second_part;
                if (lower_string_end == the_text.length() - 1) {
                    second_part = "";
                } else {
                    second_part = the_text.substring(lower_string_end + 2);
                }
                String new_text = first_part + new_upper_string + "\n" + new_lower_string + "\n" + second_part;
                _mai.Text.setText(new_text);
            }
        }
    }

    @Override
    public void keyReleased(KeyEvent keyEvent) {
    }
}
