#include <iostream>
#include <vector>
#include <thread>
#include <winsock2.h>
#include <mutex>

#pragma comment(lib, "ws2_32.lib")

std::vector<SOCKET> clients;
std::mutex clients_mutex;

void handleClient(SOCKET clientSock) {
    char buffer[1024];
    int recvSize;

    std::cout << "客户端已连接!" << std::endl;

    while (true) {
        recvSize = recv(clientSock, buffer, sizeof(buffer) - 1, 0);
        if (recvSize <= 0) {
            std::cout << "客户端已断开连接." << std::endl;
            break;
        }

        buffer[recvSize] = '\0';
        std::cout << "已收到: " << buffer << std::endl;

        // 广播消息给所有客户端
        std::lock_guard<std::mutex> lock(clients_mutex);
        for (SOCKET otherClient : clients) {
            if (otherClient != clientSock) {
                send(otherClient, buffer, recvSize, 0);
            }
        }
    }

    // 客户端断开，从列表中移除
    std::lock_guard<std::mutex> lock(clients_mutex);
    auto it = std::find(clients.begin(), clients.end(), clientSock);
    if (it != clients.end()) {
        clients.erase(it);
    }
    closesocket(clientSock);
}

int main() {
    // 初始化Winsock
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 创建服务器Socket
    SOCKET serverSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // 绑定地址和端口
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8888);

    bind(serverSock, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSock, 5);

    std::cout << "聊天服务器已在端口 8888 启动..." << std::endl;
    std::cout << "等待连接..." << std::endl;

    while (true) {
        SOCKET clientSock = accept(serverSock, (sockaddr*)&serverAddr, NULL);
        if (clientSock != INVALID_SOCKET) {
            std::lock_guard<std::mutex> lock(clients_mutex);
            clients.push_back(clientSock);
            std::thread(handleClient, clientSock).detach();
        }
    }

    closesocket(serverSock);
    WSACleanup();
    return 0;
}