#include "Book.h"

// Book::Book(const std::string& new_line)
// {
 
// }

Book::Book(const std::string& cn, const std::string& ti, const std::string& su,
             const std::string& au, const std::string& de, const std::string& pu,
             const std::string& ci, const std::string& ye, const std::string& se,
             const std::string& no)
             : Media(cn,ti,su), author(au), description(de), publisher(pu), city(ci),
               year(ye), series(se), notes(no)
{

}

bool Book::got_other(const std::string& ot) const{
    if (description.find(ot) != std::string::npos || 
        notes.find(ot) != std::string::npos ||
        year.find(ot) != std::string::npos)
    {
        return true;
    } 
    return false;
}

void Book::display() const{

    std::cout << "==========================" << std::endl;
    std::cout << "========== BOOK ==========" << std::endl;
    std::cout << "==========================" << std::endl; 
    std::cout << "call number:  " << get_call_num() << std::endl;
    std::cout << "title:        " << get_title() << std::endl;
    std::cout << "subjects:     " << get_subjects() << std::endl;
    std::cout << "author:       " << author << std::endl;
    std::cout << "description:  " << description << std::endl;
    std::cout << "publisher:    " << publisher << std::endl;
    std::cout << "city:         " << city << std::endl;
    std::cout << "year:         " << year << std::endl;
    std::cout << "series:       " << series << std::endl;
    std::cout << "notes:        " << notes << std::endl;    
    
}
