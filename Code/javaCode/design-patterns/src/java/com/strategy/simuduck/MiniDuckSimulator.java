package com.strategy.simuduck;

import com.strategy.simuduck.duck.Duck;
import com.strategy.simuduck.duck.sub.MallardDuck;
import com.strategy.simuduck.duck.sub.ModelDuck;
import com.strategy.simuduck.fly.impl.FlyRocketPowered;

public class MiniDuckSimulator {
    public static void main(String[] args) {
        Duck mallard = new MallardDuck();
        mallard.performQuack();
        mallard.performFly();

        Duck model = new ModelDuck();
        model.performFly();
        model.setFlyBehavior(new FlyRocketPowered());
        model.performFly();
    }
}
