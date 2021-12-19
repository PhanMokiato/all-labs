package com.company;
import javax.swing.*;


public class Main{
    JFrame Window;
    JTextArea Text;
    JScrollPane Scroll;
    JMenuBar Menu;
    JMenu FileButton = new JMenu("File");
    JMenu ActionsButton = new JMenu("Actions");
    FileCode file;
    ActionsCode Actions;
    KeyCode keyCode;

    public Main() {
        CreateWindow();
        CreateTextArea();
        CreateMenuBar();
        keyCode = new KeyCode(this);
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
        Menu.add(FileButton);
        file = new FileCode(this, FileButton);
        Menu.add(ActionsButton);
        Actions = new ActionsCode(this, ActionsButton);
        Window.setJMenuBar(Menu);
    }
}
