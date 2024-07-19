#include "server.h"
#include <fstream>
#include <sstream>
#include <iostream>

Server::Server() {
}

void Server::startServer() {
    configureRoutes();
    app.port(8080).multithreaded().run();
}

void Server::configureRoutes() {
    CROW_ROUTE(app, "/")([](){
        return "Hola papu";
    });

    CROW_ROUTE(app, "/papu")([](){
        return "Prueba";
    });

    CROW_ROUTE(app, "/static/<string>")([](const crow::request& req, const std::string& filename) {
        std::string path = "C:/Users/HP/Desktop/Sistema/Sistema-de-Emolientes/static/" + filename;
        std::ifstream file(path);
        if (!file.is_open()) {
            return crow::response(404, "File not found");
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        return crow::response(buffer.str());
    });
}
