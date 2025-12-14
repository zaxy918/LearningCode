package com.strategy.puzzle.character.sub;

import com.strategy.puzzle.character.MyCharacter;
import com.strategy.puzzle.weapon.impl.SwordBehavior;

public class King extends MyCharacter {

    public King() {
        weapon = new SwordBehavior();
    }

    @Override
    public void fight() {
        weapon.useWeapon();
    }

}
