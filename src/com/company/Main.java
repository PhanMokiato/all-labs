package com.company;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class Main implements ActionListener{

    JFrame Window;
    JTextArea Text;
    JScrollPane Scroll;
    JMenuBar Menu;
    JMenu FileButton, ActionsButton;
    JMenuItem NewFile, OpenFile, SaveFile, SaveAsFile;
    JMenuItem Search, Replace;

    FileCode file = new FileCode(this);
    ActionsCode Actions = new ActionsCode(this);

    public Main() {
        CreateWindow();
        CreateTextArea();
        CreateMenuBar();
        CreateFileMenu();
        CreateActionsMenu();
        Window.setVisible(true);
    }

    public static void main(String[] args)  {
        new Main();
    }
    public void CreateWindow() {
        Window = new JFrame("My Notepad :)");
        Window.setSize(600,400);
        Window.setLocation(400, 150);
        Window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public void CreateTextArea() {
        Text = new JTextArea();
        Scroll = new JScrollPane(Text, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        Window.add(Scroll);
    }
    public void CreateMenuBar() {
        Menu = new JMenuBar();
        FileButton = new JMenu("File");
        ActionsButton = new JMenu("Actions");
        Menu.add(FileButton);
        Menu.add(ActionsButton);
        Window.setJMenuBar(Menu);
    }
    public void CreateFileMenu() {
        NewFile = new JMenuItem("New");
        NewFile.addActionListener(this);
        NewFile.setActionCommand("New");

        OpenFile = new JMenuItem("Open");
        OpenFile.addActionListener(this);
        OpenFile.setActionCommand("Open");

        SaveFile = new JMenuItem("Save");
        SaveFile.addActionListener(this);
        SaveFile.setActionCommand("Save");

        SaveAsFile = new JMenuItem("Save As");
        SaveAsFile.addActionListener(this);
        SaveAsFile.setActionCommand("SaveAs");

        FileButton.add(NewFile);
        FileButton.add(OpenFile);
        FileButton.add(SaveFile);
        FileButton.add(SaveAsFile);
    }
    public void CreateActionsMenu() {
        Search = new JMenuItem("Search");
        Search.addActionListener(this);
        Search.setActionCommand("search_pls");

        Replace = new JMenuItem("Replace");
        Replace.addActionListener(this);
        Replace.setActionCommand("replace_pls");

        ActionsButton.add(Search);
        ActionsButton.add(Replace);
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        String Command = actionEvent.getActionCommand();
        switch (Command) {
            case "New":
                file.New();
                break;
            case "Open":
                file.Open();
                break;
            case "Save":
                file.Save();
                break;
            case "SaveAs":
                file.SaveAs();
                break;
            case "search_pls":
                Actions.Searching();
                break;
            case "replace_pls":
                Actions.Replacing();
                break;
        }
    }


}
