#include "App.h"

int main(int argc, char** argv) {
    GlutApp* app = new App(argc, argv, 1000, 500, "CSE 165 Ferocious Flappers TEAM P.A.K.");

    app->run();
}
