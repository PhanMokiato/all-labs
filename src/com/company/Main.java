package com.company;

import javax.swing.*;
import java.awt.*;

public class Main {

    JFrame Window;
    Buttons buttons = new Buttons();
    MouseGameLogic mlogic;
    KeyGameLogic klogic;

    public static void main(String[] args)  {
        new Main();
    }

    public Main() {
        CreateWindow();
        Window.setVisible(true);
    }

    public void CreateWindow() {

        Window = new JFrame("Fifteens");
        Window.setSize(450,400);
        Window.setLocation(400, 150);
        Window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Window.setLayout(new GridLayout(4,4));

        buttons.SetFirstButtons(Window);

        Window.setFocusable(true);
        Window.setFocusTraversalKeysEnabled(false);
        klogic = new KeyGameLogic(buttons.OurButtons, this);
        Window.setFocusable(true);

        mlogic = new MouseGameLogic(buttons.OurButtons, this, klogic);

    }
}
