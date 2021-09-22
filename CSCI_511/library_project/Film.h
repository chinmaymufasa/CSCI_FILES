//File: Film.h

#ifndef FILM_H
#define FILM_H

#include <iostream>
#include "Media.h"

class Film : public Media {
    public:
        Film(const std::string& cn, const std::string& ti, const std::string& su,
             const std::string& de, const std::string& no, const std::string& ye);
        void display() const;
        bool got_other(const std::string& ot) const;
        //~Film();
    private:
        std::string director;
        std::string year;
        std::string notes;
};


#endif