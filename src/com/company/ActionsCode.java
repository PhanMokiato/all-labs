package com.company;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ActionsCode implements ActionListener {
    Main mai;
    JMenu actions_button;
    JMenuItem Search, Replace;

    public ActionsCode(Main mai, JMenu actions_button) {
        this.mai = mai;
        this.actions_button = actions_button;
        CreateActionsMenu();
    }
    public void CreateActionsMenu() {
        Search = new JMenuItem("Search");
        Search.addActionListener(this);
        Search.setActionCommand("search_pls");

        Replace = new JMenuItem("Replace");
        Replace.addActionListener(this);
        Replace.setActionCommand("replace_pls");

        actions_button.add(Search);
        actions_button.add(Replace);
    }
    public void Searching() {
        String substring = JOptionPane.showInputDialog("Enter the substring that you would like to find:");
        Pattern pat = Pattern.compile(substring);
        String TheText = mai.Text.getText();
        Matcher mat = pat.matcher(TheText);
        int n = 0;
        if (mat.find()) {
            ++n;
            mai.Text.select(mat.start(),mat.end());
            JOptionPane.showMessageDialog(mai.Window,"There is " + n +" substring(s) like that one!", "Success",JOptionPane.INFORMATION_MESSAGE);
            while (mat.find()) {
                ++n;
                mai.Text.select(mat.start(),mat.end());
                JOptionPane.showMessageDialog(mai.Window,"There are " + n +" substring(s) like that one!", "Success",JOptionPane.INFORMATION_MESSAGE);
            }
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
            mai.Text.select(mat2.start(),mat2.end());
        } else {
            JOptionPane.showMessageDialog(mai.Window,"Eh, I can't actually replace something that isn't there", "Failure",JOptionPane.ERROR_MESSAGE);
        }
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        String Command = actionEvent.getActionCommand();
        switch (Command) {
            case "search_pls":
                Searching();
                break;
            case "replace_pls":
                Replacing();
                break;
        }
    }
}
