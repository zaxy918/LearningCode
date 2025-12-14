package com.strategy.puzzle.character.sub;

import com.strategy.puzzle.character.MyCharacter;
import com.strategy.puzzle.weapon.impl.SwordBehavior;

public class Queen extends MyCharacter {

    public Queen() {
        weapon = new SwordBehavior();
    }

    @Override
    public void fight() {
        weapon.useWeapon();
    }
}
