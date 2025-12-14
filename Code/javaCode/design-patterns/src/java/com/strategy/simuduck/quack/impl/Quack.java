package com.strategy.simuduck.quack.impl;

import com.strategy.simuduck.quack.QuackBehavior;

public class Quack implements QuackBehavior {

    @Override
    public void quack() {
        System.out.println("Quack");
    }

}
