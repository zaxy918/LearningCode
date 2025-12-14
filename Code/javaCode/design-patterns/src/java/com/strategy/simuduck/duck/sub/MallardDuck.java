package com.strategy.simuduck.duck.sub;

import com.strategy.simuduck.duck.Duck;
import com.strategy.simuduck.fly.impl.FlyWithWings;
import com.strategy.simuduck.quack.impl.Quack;

public class MallardDuck extends Duck {

    public MallardDuck() {
        super();
        flyBehavior = new FlyWithWings();
        quackBehavior = new Quack();
    }

    @Override
    public void diplay() {
        System.out.println("I'm a Mallard Duck");
    }

}
