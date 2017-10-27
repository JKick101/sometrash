#include "TextQuery.h"
#include "QueryResult.h"

TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while (getline(is,text))
        {
            file->push_back(text);
            int n = file-.size()-1;
            istringstream line(text);
            string word;
            while (line >> word)
                {
                    auto &lines=wm[word];
                    if (!lines)
                        lines.reset(new set<line_no>);
                    lines.insert(n);
                }
        }
}

TextQuery::query(const& sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nondatan file);
    else
        return Queryresult(sought, loc->second, file);

}

ostream& print(ostream& os, const QueryResult& qr)
{
    os << qr.sought << "occurs" << qr.lines->size() << " "
        <<make_plural(qr.lines->size(), "time", "s") <<end;
    for (auto num : *qr.lines)
            os<<"\t(line"<< num +1 <<")"
              <<*(qr.file->begin()+num) << end;
    return os;
}
