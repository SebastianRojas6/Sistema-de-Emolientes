#include "crow.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([]() {
        return "Hola papu";
        });

    CROW_ROUTE(app, "/papu")([](){
        return "Prueba";
    });

    app.port(8080).multithreaded().run();
}