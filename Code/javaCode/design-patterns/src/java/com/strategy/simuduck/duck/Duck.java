package com.strategy.simuduck.duck;

import com.strategy.simuduck.fly.FlyBehavior;
import com.strategy.simuduck.quack.QuackBehavior;

public abstract class Duck {
    protected FlyBehavior flyBehavior;
    protected QuackBehavior quackBehavior;

    public Duck() {
    }

    public void swim() {
        System.out.println("All ducks float, even decoys!");
    }

    public abstract void diplay();

    public void performFly() {
        flyBehavior.fly();
    }

    public void performQuack() {
        quackBehavior.quack();
    }

    public void setFlyBehavior(FlyBehavior fb) {
        flyBehavior = fb;
    }

    public void setQuackBehavior(QuackBehavior qb) {
        quackBehavior = qb;
    }

}
