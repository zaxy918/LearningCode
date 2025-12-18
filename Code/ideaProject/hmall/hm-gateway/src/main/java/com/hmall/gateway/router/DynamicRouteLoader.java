package com.hmall.gateway.router;

import cn.hutool.json.JSONUtil;
import com.alibaba.cloud.nacos.NacosConfigManager;
import com.alibaba.nacos.api.config.listener.Listener;
import com.alibaba.nacos.api.exception.NacosException;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.cloud.gateway.route.RouteDefinition;
import org.springframework.cloud.gateway.route.RouteDefinitionWriter;
import org.springframework.stereotype.Component;
import reactor.core.publisher.Mono;

import javax.annotation.PostConstruct;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.concurrent.Executor;

@Slf4j
@Component
@RequiredArgsConstructor
public class DynamicRouteLoader {
    private final NacosConfigManager nacosConfigManager;
    private final RouteDefinitionWriter routeDefinitionWriter;
    private final Set<String> loadedRouteIds = new HashSet<>();

    private static final String ROUTE_DATA_ID = "gateway-routes.json";
    private static final String ROUTE_GROUP = "DEFAULT_GROUP";

    @PostConstruct
    public void initRouteConfigListener() throws NacosException {
        // 读取初始路由配置并添加监听器
        String configInfo = nacosConfigManager.getConfigService().getConfigAndSignListener(ROUTE_DATA_ID, ROUTE_GROUP, 3000, new Listener() {
            @Override
            public Executor getExecutor() {
                return null;
            }

            @Override
            public void receiveConfigInfo(String configInfo) {
                // 当配置发生变化时，更新路由
                log.info("Received updated route config: {}", configInfo);
                updateConfigInfo(configInfo);
            }
        });
        // 解析并加载初始路由配置
        updateConfigInfo(configInfo);
    }

    private void updateConfigInfo(String configInfo) {
        // 解析配置并更新路由逻辑
        List<RouteDefinition> routeDefinitions = JSONUtil.toList(configInfo, RouteDefinition.class);
        // 清除现有路由
        for (String routeId : loadedRouteIds) {
            routeDefinitionWriter.delete(Mono.just(routeId)).subscribe();
        }
        loadedRouteIds.clear();
        for (RouteDefinition definition : routeDefinitions) {
            // 保存新的路由定义并记录上次加载的路由ID
            routeDefinitionWriter.save(Mono.just(definition)).subscribe();
            loadedRouteIds.add(definition.getId());
        }
    }
}
