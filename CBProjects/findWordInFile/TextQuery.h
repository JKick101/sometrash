#ifndef TEXTQUERY_H_INCLUDED
#define TEXTQUERY_H_INCLUDED

#include <iostream>
#include <memory>
using namespace std;

class QueryResult;

class TextQuery{
public:
    using line_no=std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string,
                std::shared_ptr<std:;set<line_no>>> wm;

};

#endif // TEXTQUERY_H_INCLUDED
