//Chinmay Satpanthi
//CSCI 511
//Library Project
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

        Library();      //constructor that reads txt files and loads objs in card catalog vector

        std::vector<Media*> find_everything_with_call_number(const std::string& ss) const; //finds and returns results
        std::vector<Media*> find_everything_with_title(const std::string& ss) const;
        std::vector<Media*> find_everything_with_subject(const std::string& ss) const;
        std::vector<Media*> find_everything_with_other(const std::string& ss) const;        

        //std::vector<Media*> add_media(const string& med) const;
        ~Library();
        
    private:
        std::vector<Media*> card_catalog;   //vector list that will hold all the media obj files.
};

#endif