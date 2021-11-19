package com.company;

import java.awt.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class FileCode {
    Main mai;
    String FileName;
    String FileAddress;

    public FileCode(Main mai) {
        this.mai = mai;
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
}
