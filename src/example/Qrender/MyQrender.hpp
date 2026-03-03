#pragma once

#include <QWidget>


class MyQrender : public QWidget{
    Q_OBJECT
    public:
        MyDrawWidget(QWidget *parent = nullptr) : QWidget(parent) {
            // Устанавливаем заголовок окна
            setWindowTitle("Простой QWidget с отрисовкой");
            // Устанавливаем начальный размер
            resize(600, 400);
        }
    signals:
    
};