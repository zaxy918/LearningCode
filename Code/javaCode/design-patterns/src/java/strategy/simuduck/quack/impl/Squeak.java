package strategy.simuduck.quack.impl;

import strategy.simuduck.quack.QuackBehavior;

public class Squeak implements QuackBehavior {

    @Override
    public void quack() {
        System.out.println("Squeak");
    }

}
