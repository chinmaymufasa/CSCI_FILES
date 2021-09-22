//File: Media.h

#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>

class Media {

    public:
        Media(const std::string& cn, const std::string& ti, const std::string& su);
        bool got_call_number(const std::string& cn) const;
        bool got_title(const std::string& ti) const;
        bool got_subjects(const std::string& su) const;

        std::string get_call_num() const;
        std::string get_title() const;
        std::string get_subjects() const;

        virtual void display() const = 0;
        virtual bool got_other(const std::string& ot) const=0;
        virtual ~Media();
    private:
        std::string call_number;
        std::string title;
        std::string subjects;
};

#endif