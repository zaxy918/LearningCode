package com.sky.websocket;

import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Component;

import javax.websocket.OnClose;
import javax.websocket.OnMessage;
import javax.websocket.OnOpen;
import javax.websocket.Session;
import javax.websocket.server.PathParam;
import javax.websocket.server.ServerEndpoint;
import java.util.HashMap;
import java.util.Map;

@Slf4j
@Component
@ServerEndpoint("/ws/{sid}")
public class WebSocketServer {

    private static Map<String, Session> sessionMap = new HashMap<>();

    public static void sendMessageToAll(String message) {
        sessionMap.forEach((sid, session) -> {
            try {
                session.getBasicRemote().sendText(message);
            } catch (Exception e) {
                log.error("发送消息失败：{}", e.getMessage());
            }
        });
    }

    @OnOpen
    public void onOpen(Session session, @PathParam("sid") String sid) {
        sessionMap.put(sid, session);
    }

    @OnMessage
    public void onMessage(Session session, @PathParam("sid") String sid, String message) {
        log.info("onMessage: {}", message);
    }

    @OnClose
    public void onClose(Session session, @PathParam("sid") String sid) {
        sessionMap.remove(sid);
    }
}
