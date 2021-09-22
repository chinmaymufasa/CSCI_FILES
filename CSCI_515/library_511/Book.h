//Chinmay Satpanthi
//CSCI 511
//Library Project

//File: Book.h

#ifndef BOOK_H
#define BOOK_H

#include "Media.h"

class Book : public Media{
    public:
        Book(const std::string& cn, const std::string& ti, const std::string& su,
             const std::string& au, const std::string& de, const std::string& pu,
             const std::string& ci, const std::string& ye, const std::string& se,
             const std::string& no);

        //call through the virtual function in Media
        void display() const;
        bool got_other(const std::string& ot) const;
    private:
        std::string author;
        std::string description;
        std::string publisher;
        std::string city;
        std::string year;
        std::string series;
        std::string notes;
};


#endif