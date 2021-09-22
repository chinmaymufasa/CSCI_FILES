#include "Media.h"

using std::string;
//using std::string::npos;

Media::~Media(){

}

Media::Media(const std::string& cn, const std::string& ti, const std::string& su)
    :call_number(cn), title(ti), subjects(su)
{

}

bool Media::got_call_number(const string & cn) const{
    if (call_number.find(cn) != string::npos){
        return true;
    }
    return false;
}

bool Media::got_title(const string& cn) const {
    if (title.find(cn) != string::npos){
        return true;
    }
    return false;
}

bool Media::got_subjects(const string& cn) const {
    if (subjects.find(cn) != string::npos){
        return true;
    }
    return false;
}

std::string Media::get_call_num() const{
    return call_number;
}

std::string Media::get_title() const{
    return title;
}

std::string Media::get_subjects() const{
    return subjects;
}


