package com.sky.service.impl;

import com.sky.context.BaseContext;
import com.sky.dto.ShoppingCartDTO;
import com.sky.entity.Dish;
import com.sky.entity.Setmeal;
import com.sky.entity.ShoppingCart;
import com.sky.mapper.DishMapper;
import com.sky.mapper.SetmealMapper;
import com.sky.mapper.ShoppingCartMapper;
import com.sky.service.ShoppingCartService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.util.List;

@Service
@Slf4j
public class ShoppingCartServiceImpl implements ShoppingCartService {

    @Autowired
    ShoppingCartMapper shoppingCartMapper;
    @Autowired
    DishMapper dishMapper;
    @Autowired
    SetmealMapper setmealMapper;

    @Override
    public void addShoppingCart(ShoppingCartDTO shoppingCartDTO) {
        // Judge if the item is already in the shopping cart
        ShoppingCart shoppingCart = new ShoppingCart();
        BeanUtils.copyProperties(shoppingCartDTO, shoppingCart);
        List<ShoppingCart> shoppingCartList = shoppingCartMapper.list(shoppingCart);
        // If it exists, increase the number
        if (shoppingCartList != null && !shoppingCartList.isEmpty()) {
            ShoppingCart existingItem = shoppingCartList.get(0);
            // Update the item in the database (not shown here)
            existingItem.setNumber(existingItem.getNumber() + 1);
            shoppingCartMapper.updateNumberById(existingItem);
        } else {
            // If it does not exist, add a new item to the cart
            shoppingCart.setNumber(1);
            shoppingCart.setUserId(BaseContext.getCurrentId());
            shoppingCart.setCreateTime(LocalDateTime.now());
            if (shoppingCart.getDishId() != null) {
                log.info("Adding dish to shopping cart: {}", shoppingCart);
                Dish dish = dishMapper.getById(shoppingCart.getDishId());
                shoppingCart.setName(dish.getName());
                shoppingCart.setImage(dish.getImage());
                shoppingCart.setAmount(dish.getPrice());
            } else {
                log.info("Adding setmeal to shopping cart: {}", shoppingCart);
                Setmeal setmeal = new Setmeal();
                setmeal = setmealMapper.getById(shoppingCart.getSetmealId());
                shoppingCart.setName(setmeal.getName());
                shoppingCart.setImage(setmeal.getImage());
                shoppingCart.setAmount(setmeal.getPrice());
            }
            shoppingCartMapper.insert(shoppingCart);
        }
    }

    @Override
    public List<ShoppingCart> list() {
        ShoppingCart shoppingCart = new ShoppingCart();
        shoppingCart.setUserId(BaseContext.getCurrentId());
        return shoppingCartMapper.list(shoppingCart);
    }

    @Override
    public void subShoppingCart(ShoppingCartDTO shoppingCartDTO) {
        ShoppingCart shoppingCart = new ShoppingCart();
        BeanUtils.copyProperties(shoppingCartDTO, shoppingCart);
        List<ShoppingCart> shoppingCartList = shoppingCartMapper.list(shoppingCart);
        if (shoppingCartList != null && !shoppingCartList.isEmpty()) {
            ShoppingCart existingItem = shoppingCartList.get(0);
            if (existingItem.getNumber() > 1) {
                existingItem.setNumber(existingItem.getNumber() - 1);
                shoppingCartMapper.updateNumberById(existingItem);
            } else {
                shoppingCartMapper.deleteById(existingItem.getId());
            }
        }
    }

    @Override
    public void cleanShoppingCart(Long userId) {
        shoppingCartMapper.clean(userId);
    }
}
