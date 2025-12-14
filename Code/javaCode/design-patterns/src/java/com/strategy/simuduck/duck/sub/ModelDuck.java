package com.strategy.simuduck.duck.sub;

import com.strategy.simuduck.duck.Duck;
import com.strategy.simuduck.fly.impl.FlyNoWay;
import com.strategy.simuduck.quack.impl.Quack;

public class ModelDuck extends Duck {

    public ModelDuck() {
        super();
        flyBehavior = new FlyNoWay();
        quackBehavior = new Quack();
    }

    @Override
    public void diplay() {
        System.out.println("I'm a Model Duck");
    }

}
