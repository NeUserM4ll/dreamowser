#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

class ruleCss{
    public:

    std::string selector;
    std::map<std::string,std::string> atributes; 

};
class parseCss{
    public:
        
        std::map<std::string,std::map<std::string,std::string>> selector;
    void parse(std::string cssText){
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
    void BID(){
        std::cout << selector[".tag"]["background-color"];
    }
};
std::string readFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << fileName << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf(); // Считываем всё содержимое файла в буфер
    return buffer.str();
}

int main(int argc, char* argv[]){
    
    parseCss n ;
    std::string mm = readFile(argv[1]);
    n.parse(mm);
    n.BID();
    
    return 0;
}
