//Chinmay Satpanthi
//CSCI 511
//Library Project
#include "Periodical.h"

//Constructor initializing/setting values
Periodical::Periodical(const std::string& cn, const std::string& ti, const std::string& su,
                       const std::string& au, const std::string& de, const std::string& pu,
                       const std::string& ph, const std::string& se, const std::string& no,
                       const std::string& rt, const std::string& of, const std::string& gd)
                       : Media(cn, ti, su), author(au), description(de), publisher(pu),
                         publishing_history(ph), series(se), notes(no), related_titles(rt),
                         other_forms_of_title(of), govt_doc_number(gd)
{

}

//Checks if other specified string is in catalog
bool Periodical::got_other(const std::string& ot) const{
    if (description.find(ot) != std::string::npos || 
        notes.find(ot) != std::string::npos ||
        series.find(ot) != std::string::npos ||
        related_titles.find(ot) != std::string::npos)
    {
        return true;
    } 
    return false;
}

//Display function
void Periodical::display() const{

    std::cout << "==========================" << std::endl;
    std::cout << "======= PERIODICAL =======" << std::endl;
    std::cout << "==========================" << std::endl; 
    std::cout << "call number:          " << get_call_num() << std::endl;
    std::cout << "title:                " << get_title() << std::endl;
    std::cout << "subjects:             " << get_subjects() << std::endl;
    std::cout << "author:               " << author << std::endl;
    std::cout << "description:          " << description << std::endl;
    std::cout << "publisher:            " << publisher << std::endl;
    std::cout << "publishing history:   " << publishing_history << std::endl;
    std::cout << "series:               " << series << std::endl;
    std::cout << "notes:                " << notes << std::endl;
    std::cout << "related titles:       " << related_titles << std::endl;
    std::cout << "other forms of title: " << other_forms_of_title << std::endl;
    std::cout << "Govt doc number:      " << govt_doc_number << std::endl;      
}
