#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPainter>



class RenderWindow : public QWidget {
    Q_OBJECT
public:
    explicit RenderWindow(QWidget *parent = nullptr);

    virtual ~RenderWindow()=default;
private:
    void paintEvent(QPaintEvent *event);
       

};