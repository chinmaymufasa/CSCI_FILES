//Chinmay Satpanthi
//CSCI 511
//Library Project

#include <iostream>
#include "Video.h"

//Constructor initializing/setting values
Video::Video(const std::string& cn, const std::string& ti, const std::string& su,
             const std::string& de, const std::string& di, const std::string& no,
             const std::string& se, const std::string& lb)
             : Media(cn,ti,su), description(de), distributor(di), notes(no), series(se),
               label(lb)
{

}

//Checks if other string specified is found
bool Video::got_other(const std::string& ot) const{
    if (description.find(ot) != std::string::npos || 
        notes.find(ot) != std::string::npos ||
        distributor.find(ot) != std::string::npos)
    {
        return true;
    } 
    return false;
}

//Display function
void Video::display() const{

    std::cout << "==========================" << std::endl;
    std::cout << "========== VIDEO =========" << std::endl;
    std::cout << "==========================" << std::endl; 
    std::cout << "call number:          " << get_call_num() << std::endl;
    std::cout << "title:                " << get_title() << std::endl;
    std::cout << "subjects:             " << get_subjects() << std::endl;
    std::cout << "description:          " << description << std::endl;
    std::cout << "distributor:          " << distributor << std::endl;
    std::cout << "notes:                " << notes << std::endl;
    std::cout << "series:               " << series << std::endl;
    std::cout << "label:                " << label << std::endl;    
}
