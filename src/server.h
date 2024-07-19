#pragma once
#include "crow.h"

class Server {
public:
    Server();
    void startServer();
private:
    void configureRoutes();
    crow::SimpleApp app;
};
