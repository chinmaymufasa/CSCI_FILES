#include <iostream>
#include "Film.h"

Film::Film(const std::string& cn, const std::string& ti, const std::string& su,
           const std::string& de, const std::string& no, const std::string& ye)
           : Media(cn,ti,su), director(de), notes(no), year(ye)
{

}

bool Film::got_other(const std::string& ot) const{
    if (notes.find(ot) != std::string::npos || 
        director.find(ot) != std::string::npos ||
        year.find(ot) != std::string::npos)
    {
        return true;
    } 
    return false;
}

void Film::display() const{

    std::cout << "==========================" << std::endl;
    std::cout << "========== FILM ==========" << std::endl;
    std::cout << "==========================" << std::endl; 
    std::cout << "call number:  " << get_call_num() << std::endl;
    std::cout << "title:        " << get_title() << std::endl;
    std::cout << "subjects:     " << get_subjects() << std::endl;
    std::cout << "director:     " << director << std::endl;
    std::cout << "notes:        " << notes << std::endl;
    std::cout << "year:         " << year << std::endl;
        
    
}


