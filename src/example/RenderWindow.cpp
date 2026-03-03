#include "RenderWindow.hpp"
#include "../parser/sd/ParserHtml.hpp" 
#include "../parser/sd/Tag.hpp"
#include <Color>
// RenderWindow::SimpleWindow(QWidget *parent) : QWidget(parent) {
//     // 1. Создаем центральный виджет (контейнер)
//     auto* centralWidget = new QWidget(this);
//     setCentralWidget(centralWidget);

//     // 2. Создаем компоновщик (вертикальный)
//     auto* layout = new QVBoxLayout(centralWidget);
//     QLabel *myLabel = new QLabel("Элемент в списке");
//     layout->addWidget(myLabel);
//     // 3. Добавляем поле ввода
//     m_lineEdit = new QLineEdit(this);
//     m_lineEdit->setPlaceholderText("Введите новый заголовок...");
//     layout->addWidget(m_lineEdit);

//     // 4. Добавляем кнопку
//     m_button = new QPushButton("Применить", this);
//     layout->addWidget(m_button);


//     // 5. МАГИЯ QT: Соединяем сигнал нажатия кнопки с нашим слотом
//    // connect(m_button, &QPushButton::clicked, this, &SimpleWindow::handleApplyText(layout,this));
//  connect(m_button, &QPushButton::clicked, [this, layout]() {
//         handleApplyText(layout, this); // Передаем указатель на текущее окно
//     });
//     resize(400, 200);
// }
enum class TypeText{
    p,
    h1,
    i,
    span,
    b,


};
struct TextConfig {
    int fontSize = 12;               // По дефолту обычный текст
    QColor color = Qt::black;        // Черный
    bool bold = false;
    int marginTop = 5; 
    bool cursiv = false; 
};

 class  HtmlTagRender
{
private:
    /* data */
    TextConfig textconf(std::string tag){
        TextConfig style;
        if (tag == "<h1>"){
            style.fontSize = 24;
            style.bold = true;
            style.marginTop = 20;
        }
        else if (tag == "<h2>")
        {
            style.fontSize = 24;
            style.bold = true;
            style.marginTop = 20;
        }
        else if (tag == "<b>" || tag == "<strong>") {
        style.bold = true;
    } 
    else if (tag == "<a>") {
        style.color = Qt::blue; 
    }
    
    return style;
        
    }
    void drawNode(QPainter &p, Tag *node, int &currentY) {
    TextConfig style = getStyleForTag(node->tag);
    
    // Если в парсере ВДРУГ нашелся цвет из CSS, перебиваем дефолт
    //if (node->hasCustomColor) style.color = node->customColor;

    p.setFont(QFont("Arial", style.fontSize, style.bold ? QFont::Bold : QFont::Normal));
    p.setPen(style.color);
    
    currentY += style.marginTop; // Добавляем отступ сверху
    p.drawText(10, currentY, node->text);
    currentY += style.fontSize + 5; // Смещаемся вниз для следующей строки
}
public:
    
    HtmlTagRender(/* args */);
    ~HtmlTagRender();
//мб сделать чтбы запоминало атрибуты 
  static void searchparse(Tag* node, QPainter& painter) {
        if (!node) return;

        // Вместо switch используем старый добрый if
        if (node->nameToken == "<body>") {
            painter.setBrush(QBrush(Qt::white)); 
            painter.setPen(Qt::black);
            painter.drawRect(0, 0, 800, 600);
            if (!node->text.empty()) {
               painter.drawText(20, 40, QString::fromStdString(node->text));
            }
             
        } 
        else if (node->nameToken == "<h1>") {
            // В h1 текст обычно больше, но пока просто рисуем белым
            painter.setPen(Qt::black); // Белым на белом не увидишь! Поставил черный
            painter.drawText(20, 40, QString::fromStdString(node->text));
        }

        // Рекурсия: вызываем СЕБЯ ЖЕ для каждого ребенка
        for (Tag* child : node->tokenChildren) {
            searchparse(child, painter);
        }
    }

    static void renderHtml(std::string htmlPage, QPainter& paint) {
        ParserHtml htmlpar;
        htmlpar.ParserHtmlstr(htmlPage); 
        // Передаем корень и малярную кисть
        searchparse(htmlpar.root, paint);
    }

};



RenderWindow::RenderWindow(QWidget* parent): QWidget(parent){
    setWindowTitle("Рендер");
    resize(800,600);
}
void RenderWindow::paintEvent(QPaintEvent *event)
    {
        QPainter painter;
        painter.begin(this);
        
        HtmlTagRender::renderHtml("<body><h1>привет мир</h1></body",painter);
        
        painter.end();
        
    }

// void RenderWindow::handleApplyText(QVBoxLayout* layout, QWidget* parent) {
//     QString text = m_lineEdit->text();

//     QString buff;
//     QString text2;

//     // Обработка текста
//     for (int i = 0; i < text.size(); ++i) {
//         if (text[i] == '<') {
//             while (i < text.size() && text[i] != '>') {
//                 buff += text[i];
//                 i++;
//             }
//             if (i < text.size()) { // Добавляем '>' только если он найден
//                 buff += '>'; 
//             }
//         } else {
//             text2 += text[i];
//         }
//     }

//     // Проверка на наличие подстроки "button"
//     if (text2.contains("button", Qt::CaseSensitive)) {
//         QPushButton *but = new QPushButton(text2, parent);
//         layout->addWidget(but);

//         qDebug() << "Добавлена кнопка с текстом:" << text2;
//     }
    
// }