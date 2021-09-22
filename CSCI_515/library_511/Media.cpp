//Chinmay Satpanthi
//CSCI 511
//Library Project

#include "Media.h"

using std::string;

//Destructor for all Media classes since its vitual
Media::~Media(){

}

//Initializes and sets the three common values in media obj
Media::Media(const std::string& cn, const std::string& ti, const std::string& su)
    :call_number(cn), title(ti), subjects(su)
{

}

//Checks if local data has specified call number
bool Media::got_call_number(const string & cn) const{
    if (call_number.find(cn) != string::npos){
        return true;
    }
    return false;
}

//Checks if local data has specified title
bool Media::got_title(const string& cn) const {
    if (title.find(cn) != string::npos){
        return true;
    }
    return false;
}

//Checks if local subjects has specified subjects
bool Media::got_subjects(const string& cn) const {
    if (subjects.find(cn) != string::npos){
        return true;
    }
    return false;
}

//returns Media call number
std::string Media::get_call_num() const{
    return call_number;
}

//returns Media title
std::string Media::get_title() const{
    return title;
}

//returns Media subjects
std::string Media::get_subjects() const{
    return subjects;
}


