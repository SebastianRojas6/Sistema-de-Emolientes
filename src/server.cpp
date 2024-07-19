#include "server.h"

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
}
