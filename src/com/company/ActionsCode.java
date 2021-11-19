package com.company;

import javax.swing.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ActionsCode {
    Main mai;

    public ActionsCode(Main mai) {
        this.mai = mai;
    }

    public void Searching() {
        String substring = JOptionPane.showInputDialog("Enter the substring that you would like to find:");
        Pattern pat = Pattern.compile(substring);
        String TheText = mai.Text.getText();
        Matcher mat = pat.matcher(TheText);
        int n = 0;
        if (mat.find()) {
            while (mat.find()) {
                ++n;
                mai.Text.select(mat.start(),mat.end());
                JOptionPane.showMessageDialog(mai.Window,"There are " + n +" substring(s) like that one!", "Success",JOptionPane.INFORMATION_MESSAGE);
            }
            mai.Text.select(mat.start(),mat.end());
            JOptionPane.showMessageDialog(mai.Window,"There are substring(s) like that one!", "Success",JOptionPane.INFORMATION_MESSAGE);
        } else {
            JOptionPane.showMessageDialog(mai.Window,"There are no substrings like that one(", "Failure",JOptionPane.WARNING_MESSAGE);
        }
    }

    public void Replacing() {
        String substring = JOptionPane.showInputDialog("Enter the substring that you would like to replace:");
        String new_substring = JOptionPane.showInputDialog("Now enter the new substring:");
        Pattern pat = Pattern.compile(substring);
        String TheText = mai.Text.getText();
        Matcher mat = pat.matcher(TheText);
        if (mat.find()) {
            String NewText = mat.replaceAll(new_substring);
            mai.Text.setText(NewText);
            Pattern pat2 = Pattern.compile(new_substring);
            Matcher mat2 = pat2.matcher(NewText);
            boolean ok = mat2.find();
            mai.Text.select(mat2.start(),mat2.end());
        } else {
            JOptionPane.showMessageDialog(mai.Window,"Eh, I can't actually replace something that isn't there", "Failure",JOptionPane.ERROR_MESSAGE);
        }
    }
}
