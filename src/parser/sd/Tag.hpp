#pragma once
#include <iostream>
#include <vector>
#include <map>


class Tag
{
public:

    //сделать приватными переменные
    static unsigned int counter;
    unsigned int id;
    std::string nameToken;
    std::string text;
    std::map<std::string,std::string> atribute;
    std::string className;
    std::string idName;
    

    Tag *tokenParent = nullptr;
    std::vector<Tag*> tokenChildren;
    //это public но мне похуй
    Tag(std::string name_token);
 
    ~Tag();
};


