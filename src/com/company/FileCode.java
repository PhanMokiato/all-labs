package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class FileCode implements ActionListener {
    Main mai;
    String FileName;
    String FileAddress;

    JMenu file_bitton;
    JMenuItem NewFile, OpenFile, SaveFile, SaveAsFile;

    public FileCode(Main mai, JMenu file_bitton) {
        this.mai = mai;
        this.file_bitton = file_bitton;
        CreateFileMenu();
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

        file_bitton.add(NewFile);
        file_bitton.add(OpenFile);
        file_bitton.add(SaveFile);
        file_bitton.add(SaveAsFile);
    }


    public void New() {
        String t = mai.Text.getText();
        mai.Text.setText("");
        mai.Window.setTitle("New file");
        FileName = null;
        FileAddress = null;
    }
    public void Open() {
        FileDialog fileD = new FileDialog(mai.Window, "Open", FileDialog.LOAD);
        fileD.setVisible(true);
        if (fileD.getFile() != null) {
            FileName = fileD.getFile();
            FileAddress = fileD.getDirectory();
            mai.Window.setTitle(FileName);
        }
        try {
            BufferedReader Br = new BufferedReader(new FileReader(FileAddress + FileName));
            mai.Text.setText("");
            String Line = null;
            while ((Line = Br.readLine()) != null) {
                mai.Text.append(Line + "\n");
            }
            Br.close();
        } catch (Exception exception) {
            System.out.println("Sorry, we had problems with opening this file");
        }
    }
    public void Save() {
        if (FileName == null) {
            SaveAs();
        } else {
            try {
                FileWriter Fw = new FileWriter(FileAddress + FileName);
                Fw.write(mai.Text.getText());
                mai.Window.setTitle(FileName);
                Fw.close();
            } catch (Exception exception) {
                System.out.println("Sorry, we had problems with saving this file");
            }
        }
    }
    public void SaveAs() {
        FileDialog fd = new FileDialog(mai.Window, "Save", FileDialog.SAVE);
        fd.setVisible(true);
        if (fd.getFile() != null) {
            FileName = fd.getFile();
            FileAddress = fd.getDirectory();
            mai.Window.setTitle(FileName);
        }
        try {
            FileWriter Fw = new FileWriter(FileAddress + FileName);
            Fw.write(mai.Text.getText());
            Fw.close();
        } catch(Exception exception) {
            System.out.println("Sorry, we had problems with saving this file");
        }
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        String Command = actionEvent.getActionCommand();
        switch (Command) {
            case "New":
                New();
                break;
            case "Open":
                Open();
                break;
            case "Save":
                Save();
                break;
            case "SaveAs":
                SaveAs();
                break;
        }
    }
}
