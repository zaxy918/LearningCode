package com.strategy.simuduck.fly.impl;

import com.strategy.simuduck.fly.FlyBehavior;

public class FlyNoWay implements FlyBehavior {

    @Override
    public void fly() {
        System.out.println("I can't fly");
    }

}
