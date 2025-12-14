package com.observer.lifechanging;

import javax.swing.JButton;
import javax.swing.JFrame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SwingObserserExample {
    JFrame frame;

    public static void main(String[] args) {
        new SwingObserserExample().go();
    }

    public void go() {
        frame = new JFrame();

        JButton button = new JButton("Should I do it?");
        button.addActionListener(event -> {
            System.out.println("Don't do it, you might regret it!");
        });
        button.addActionListener(event -> {
            System.out.println("Come on, do it!");
        });

        frame.getContentPane().add(button);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600, 600);
        frame.setVisible(true);
    }

}
