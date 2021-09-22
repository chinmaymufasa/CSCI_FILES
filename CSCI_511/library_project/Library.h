//File: Library.h

#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Media.h"
#include "Book.h"
#include "Film.h"
#include "Video.h"
#include "Periodical.h"

class Library {
    
    public:
        Library();
        std::vector<Media*> find_everything_with_call_number(const std::string& ss) const;
        std::vector<Media*> find_everything_with_title(const std::string& ss) const;
        std::vector<Media*> find_everything_with_subject(const std::string& ss) const;
        std::vector<Media*> find_everything_with_other(const std::string& ss) const;        

        //std::vector<Media*> add_media(const string& med) const;
        ~Library();
    private:
        std::vector<Media*> card_catalog;
};

#endif