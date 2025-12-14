package com.strategy.puzzle.weapon.impl;

import com.strategy.puzzle.weapon.WeaponBehavior;

public class AxeBehavior implements WeaponBehavior {

    @Override
    public void useWeapon() {
        System.out.println("Chopping with an axe");
    }

}