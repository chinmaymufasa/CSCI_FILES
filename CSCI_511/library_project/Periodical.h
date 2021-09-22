//File: Periodical.h

#ifndef PERIODICAL_H
#define PERIODICAL_H

#include <iostream>
#include "Media.h"

class Periodical : public Media{
    public:
        Periodical(const std::string& cn, const std::string& ti, const std::string& su,
             const std::string& au, const std::string& de, const std::string& pu,
             const std::string& ph, const std::string& se, const std::string& no,
             const std::string& rt, const std::string& of, const std::string& gd);

        //Book(const std::string& new_line);

        void display() const;
        bool got_other(const std::string& ot) const;
        //~Periodical();
    private:
        std::string author;
        std::string description;
        std::string publisher;
        std::string publishing_history;
        std::string series;
        std::string notes;
        std::string related_titles;
        std::string other_forms_of_title;
        std::string govt_doc_number;
};





#endif