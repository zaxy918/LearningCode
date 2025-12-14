package com.strategy.puzzle.character;

import com.strategy.puzzle.weapon.WeaponBehavior;

public abstract class MyCharacter {
    protected WeaponBehavior weapon;

    public abstract void fight();

    public void setWeapon(WeaponBehavior w) {
        this.weapon = w;
    }
}
