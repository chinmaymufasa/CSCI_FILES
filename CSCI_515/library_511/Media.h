//Chinmay Satpanthi
//CSCI 511
//Library Project
//File: Media.h

#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>

class Media {

    public:
        Media(const std::string& cn, const std::string& ti, const std::string& su); //sets the call number, title and subject values when new media obj created
        
        //checks catalogs if string specified exists
        bool got_call_number(const std::string& cn) const;
        bool got_title(const std::string& ti) const;
        bool got_subjects(const std::string& su) const;

        //returns the private values for display functions
        std::string get_call_num() const;
        std::string get_title() const;
        std::string get_subjects() const;

        //virtual function for the media classes
        virtual void display() const = 0;
        virtual bool got_other(const std::string& ot) const=0;

        //Destructor
        virtual ~Media();
    private:
        std::string call_number;
        std::string title;
        std::string subjects;
};

#endif