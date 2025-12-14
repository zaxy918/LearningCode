package com.hmall.gateway.filter;

import com.hmall.common.exception.UnauthorizedException;
import com.hmall.gateway.config.AuthProperties;
import com.hmall.gateway.utils.JwtTool;
import lombok.RequiredArgsConstructor;
import org.springframework.cloud.gateway.filter.GatewayFilterChain;
import org.springframework.cloud.gateway.filter.GlobalFilter;
import org.springframework.core.Ordered;
import org.springframework.http.HttpStatus;
import org.springframework.http.server.reactive.ServerHttpRequest;
import org.springframework.http.server.reactive.ServerHttpResponse;
import org.springframework.stereotype.Component;
import org.springframework.util.AntPathMatcher;
import org.springframework.web.server.ServerWebExchange;
import reactor.core.publisher.Mono;

import java.util.List;

@Component
@RequiredArgsConstructor
public class AuthGlobalFilter implements GlobalFilter, Ordered {

    private final AuthProperties authProperties;

    private final JwtTool jwtTool;

    private final AntPathMatcher antPathMatcher = new AntPathMatcher();

    @Override
    public Mono<Void> filter(ServerWebExchange exchange, GatewayFilterChain chain) {
        // 获取请求对象
        ServerHttpRequest request = exchange.getRequest();
        // 排除不需要认证的路径
        if (isExclude(request.getURI().getPath())) {
            return chain.filter(exchange);
        }
        // 获取请求头中的token
        List<String> authorization = request.getHeaders().get("authorization");
        String token = null;
        if (authorization != null && !authorization.isEmpty()) {
            token = authorization.get(0);
        }
        // 解析token
        Long userId;
        try {
            userId = jwtTool.parseToken(token);
        } catch (UnauthorizedException e) {
            ServerHttpResponse response = exchange.getResponse();
            response.setStatusCode(HttpStatus.UNAUTHORIZED);
            // 401 未授权 终止请求
            return response.setComplete();
        }
        // TODO 将用户信息传递给下游服务
        ServerWebExchange swe = exchange.mutate().request(builder -> {
            builder.header("user-info", String.valueOf(userId));
        }).build();
        return chain.filter(swe);
    }

    @Override
    public int getOrder() {
        return 0;
    }

    private boolean isExclude(String path) {
        List<String> excludePaths = authProperties.getExcludePaths();
        if (excludePaths != null) {
            for (String excludePath : excludePaths) {
                if (antPathMatcher.match(excludePath, path)) {
                    return true;
                }
            }
        }
        return false;
    }
}
