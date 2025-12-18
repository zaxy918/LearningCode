package strategy.puzzle.weapon.impl;

import strategy.puzzle.weapon.WeaponBehavior;

public class AxeBehavior implements WeaponBehavior {

    @Override
    public void useWeapon() {
        System.out.println("Chopping with an axe");
    }

}