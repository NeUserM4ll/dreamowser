#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <memory>
#include "Tag.hpp"
#include "ParserHtml.hpp"

//структура тэга hml. Стоит ли добавлять тип тэга типа текст, 
// секция , или другая хуйня ... или головной тэг наподобии боди хэд или 
//html....

// struct Tag{
//     public:
//        static unsigned int tagId;
//         TagType type;
//         std::string nameToken;
//         std::string text;
//         std::map<std::string,std::string> atribute;

//         Tag *tokenParent = nullptr;
//         std::vector<Tag*> tokenChildren;
//         Tag(TagType types,std::string nametoken) : type(types),nameToken(nametoken){

//         };
// };

//ID для статического числа



// //если у рута тоже null нужно очто-то придумать ну что жесделаешь если это вайбкод

unsigned int Tag::counter = 0;
class ParseCss
{
private:
     std::map<std::string,std::map<std::string,std::string>> selector;
public:
    
    ~ParseCss() = default;
    void parser_Css(std::string cssText);
    void BID();
    //get property
    //get value;
    //get 

    
};
void ParseCss::BID(){
        std::cout << selector[".tag"]["background-color"];
    }
void ParseCss::parser_Css(std::string cssText){
        std::string selectBuffer;
        std::string buffer;
        std::string atributes1 ;
        unsigned int stage = 0;
        
        for (char c :cssText){

            if (c=='{'){
                selectBuffer = buffer;
                buffer.clear();
                stage = 1;
                
            }else if (c==':' && stage == 1){
                atributes1 = buffer;
                buffer.clear();
                stage = 2;

            }else if (c == ';' && stage == 2){
                selector[selectBuffer][atributes1] = buffer;
                buffer.clear();
                stage = 0;
            }else if (c != ' ' && c != '\n') {
                buffer += c;
            }
            
        }
}
Tag::Tag(std::string name_token){
    id = counter++;
    nameToken = name_token;
}
//unsigned int Tag::tagId = 0;
Tag::~Tag(){
    for (Tag* child:tokenChildren){
        delete child;
    }
    tokenChildren.clear();
}



ParserHtml::ParserHtml(){
    root = nullptr;
}
void ParserHtml::ParserHtmlstr(std::string strhtml){
    std::stack<Tag*> stackTokens;

    for (size_t i = 0; i < strhtml.size(); i++) {
      
        if (strhtml[i] == '<') {
            
            std::string buff;
            while (i < strhtml.size() && strhtml[i] != '>') {
                //buff += strhtml[i];
                buff += strhtml[i];
                i++;
            }
            buff += '>'; 

            //нужно сравнить что начальный тег равен последнему иначе получится 
            //несостыковка
            if (buff.find("</") != std::string::npos) {
            
                if (!stackTokens.empty()) {
                    stackTokens.pop(); 
                    
                  
                    if (!stackTokens.empty()) {
                        root = stackTokens.top();
                    }
                }
            } else {
               
                Tag *token = new Tag(buff);
                
                if (root != nullptr) {
                    root->tokenChildren.push_back(token);
                    token->tokenParent = root;
                } 
//если у рута тоже null нужно очто-то придумать ну что жесделаешь если это вайбкод

                
                
                stackTokens.push(token);
                root = token; 
            }
        } 
        
        else {
            if (root != nullptr) {
                root->text += strhtml[i];
            }
        }
    }
}
void ParserHtml::BID(Tag* node, int depth){
    
        if (node == nullptr) return;

        // 1. Создаем отступ для визуализации глубины
        std::string indent(depth * 2, ' ');

        // 2. Выводим имя тега и его текст
        std::cout << indent << "Node: " << node->nameToken;
        if (!node->text.empty()) {
            // Очистим текст от лишних переносов строк для красоты вывода
            std::cout << " [Text: " << node->text << "]";
        }
        std::cout << " ID: "<<node->id << " ";
        std::cout << " (Children: " << node->tokenChildren.size() << ")" << std::endl;

        // 3. Рекурсивно идем по ВСЕМ детям (независимо от их количества)
        for (int i = 0; i < node->tokenChildren.size(); i++) {
            BID(node->tokenChildren[i], depth + 1); 
        }
    

}
void ParserHtml::n(){
    BID(root);
}
void recursive(int b){
    if (b==1){
        return;
    }
    std::cout << b<<"\n";
    recursive(b-1);
    std::cout<<"bez recurcii\n";

}
// int main(){
//     std::string html = "<html><h1>sdf</h1></html>";
//     ParserHtml h;
//     h.ParserHtmlstr(html);
//     h.n();
//     //recursive(5);
// }