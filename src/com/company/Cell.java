package com.company;

public class Cell {
    int _i;
    int _j;

    public Cell(int i, int j) {
        _i = i;
        _j = j;
    }
    public boolean Right() {
        return _j < 3;
    }
    public boolean Left() {
        return _j > 0;
    }
    public boolean Up() {
        return _i > 0;
    }
    public boolean Down() {
        return _i < 3;
    }
    public void SetI(int i) { _i = i; }
    public void SetJ(int j) { _j = j; }
}
