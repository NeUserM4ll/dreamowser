#include <QApplication>
#include "RenderWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    RenderWindow window;
    window.show();
    return app.exec();
}