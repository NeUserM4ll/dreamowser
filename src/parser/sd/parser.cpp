#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <memory>
enum class TagType{
    DOCTYPE,START_TAG,END_TAG,TEXT,ATRIBUTE
};

struct Tag{
    public:
        unsigned int tagId;
        TagType type;
        std::string nameToken;
        std::string text;
        std::map<std::string,std::string> atribute;

        Tag *tokenParent = nullptr;
        std::vector<Tag*> tokenChildren;
        Tag(TagType types,std::string nametoken) : type(types),nameToken(nametoken){

        };
    
        int getId(std::string nameClass){
            return ;
        }
};
class ParserHtml{
    public:
    
    void ParserHtmlsrt(std::string strhtml) {
    std::stack<Tag*> stackTokens;

    for (int i = 0; i < strhtml.size(); i++) {
      
        if (strhtml[i] == '<') {
            std::string buff;
            while (i < strhtml.size() && strhtml[i] != '>') {
                buff += strhtml[i];
                i++;
            }
            buff += '>'; 

            
            if (buff.find("</") != std::string::npos) {
            
                if (!stackTokens.empty()) {
                    stackTokens.pop(); 
                    
                  
                    if (!stackTokens.empty()) {
                        root = stackTokens.top();
                    }
                }
            } else {
               
                Tag *token = new Tag(TagType::START_TAG, buff);
                
                if (root != nullptr) {
                    root->tokenChildren.push_back(token);
                    token->tokenParent = root;
                } else {
//если у рута тоже null нужно очто-то придумать ну что жесделаешь если это вайбкод

                }
                
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
    Tag *root = nullptr;
void BID(Tag* node, int depth = 0) {
    if (node == nullptr) return;

    // 1. Создаем отступ для визуализации глубины
    std::string indent(depth * 2, ' ');

    // 2. Выводим имя тега и его текст
    std::cout << indent << "Node: " << node->nameToken;
    if (!node->text.empty()) {
        // Очистим текст от лишних переносов строк для красоты вывода
        std::cout << " [Text: " << node->text << "]";
    }
    std::cout << " (Children: " << node->tokenChildren.size() << ")" << std::endl;

    // 3. Рекурсивно идем по ВСЕМ детям (независимо от их количества)
    for (int i = 0; i < node->tokenChildren.size(); i++) {
        BID(node->tokenChildren[i], depth + 1); 
    }
}
void n(){
    BID(root);
}
    

    
};
int main(){
    std::string html = "<htmldfgdfg><h1>sdf</h1></html>";
    ParserHtml h;
    h.ParserHtmlsrt(html);
    h.n();
}