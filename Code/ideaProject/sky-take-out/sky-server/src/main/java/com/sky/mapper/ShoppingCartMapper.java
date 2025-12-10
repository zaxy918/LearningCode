package com.sky.mapper;

import com.sky.entity.ShoppingCart;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Update;

import java.util.List;

@Mapper
public interface ShoppingCartMapper {

    public List<ShoppingCart> list(ShoppingCart shoppingCart);

    @Update("update sky_take_out.shopping_cart set number = #{number} where id = #{id}")
    void updateNumberById(ShoppingCart item);

    void insert(ShoppingCart shoppingCart);

    @Delete("delete from sky_take_out.shopping_cart where id = #{id}")
    void deleteById(Long id);

    @Delete("delete from sky_take_out.shopping_cart where user_id = #{userId}")
    void clean(Long userId);
}
