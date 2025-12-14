package com.strategy.puzzle.character.sub;

import com.strategy.puzzle.character.MyCharacter;
import com.strategy.puzzle.weapon.impl.SwordBehavior;

public class Knight extends MyCharacter {

    public Knight() {
        weapon = new SwordBehavior();
    }

    @Override
    public void fight() {
        weapon.useWeapon();
    }

}
