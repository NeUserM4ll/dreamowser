//htmlParser.hpp
#pragma once
#include "Tag.hpp"
class ParserHtml{

    public:
        void ParserHtmlstr(std::string strhtml);
        
        void BID(Tag* node, int depth = 0);
        void n();
        ParserHtml();
    
        Tag *root;
};
