package strategy.simuduck.fly.impl;

import strategy.simuduck.fly.FlyBehavior;

public class FlyRocketPowered implements FlyBehavior {

    @Override
    public void fly() {
        System.out.println("I'm flying with a rocket!");
    }

}
