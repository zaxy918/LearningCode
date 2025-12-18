package strategy.puzzle.character;

import strategy.puzzle.weapon.WeaponBehavior;

public abstract class MyCharacter {
    protected WeaponBehavior weapon;

    public abstract void fight();

    public void setWeapon(WeaponBehavior w) {
        this.weapon = w;
    }
}
