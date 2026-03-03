#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

//нужно добавить тип данных типа struct для хранение атрибута
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


