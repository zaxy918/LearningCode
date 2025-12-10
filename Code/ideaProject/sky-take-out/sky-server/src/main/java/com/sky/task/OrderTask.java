package com.sky.task;

import com.sky.entity.Orders;
import com.sky.mapper.OrderMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

import java.time.LocalDateTime;
import java.util.List;

@Component
public class OrderTask {

    @Autowired
    OrderMapper orderMapper;

    @Scheduled(cron = "0 * * * * ?")
    public void deleteOrderTask() {
        // 定时删除订单的任务逻辑
        List<Orders> OutOfDateOrders = orderMapper.getOutOfTimeOrder(Orders.UN_PAID, LocalDateTime.now().minusMinutes(15));
        if (OutOfDateOrders == null || OutOfDateOrders.isEmpty()) {
            return;
        }
        OutOfDateOrders.forEach(order -> {
            order.setStatus(Orders.CANCELLED);
            orderMapper.update(order);
        });
    }
}
