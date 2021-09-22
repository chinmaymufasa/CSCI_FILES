//Chinmay Satpanthi
//CSCI 511
//Library Project

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Library.h"

Library::Library(){

    std::ifstream inFile;

    inFile.open("book.txt");        //read book.txt file
    std::string new_line;
    int end = 0;
    int start = 0;
    std::vector<std::string> values;
    std::string delimiter = "|";    //will use | (pipe) for splitting the file lines

    while(getline(inFile, new_line)){
       
       size_t pos = 0;
       while ((pos = new_line.find(delimiter)) != std::string::npos) {      //finds all strings within the delimiter and adds to temp vector
          values.push_back(new_line.substr(0, pos));
          new_line.erase(0, pos + delimiter.length());
       }
        values.push_back(new_line);

        Book *mp = new Book(values[0],values[1], values[2], values[3],
                             values[4],values[5], values[6], values[7],
                             values[8],values[9]);                          //initializes the values from files into the obj

        card_catalog.push_back(mp);                                         //pushes obj to card catalog

        values.clear();
    }
    
    inFile.close();

    //Film.txt file read and load to card catalog
    
    inFile.open("film.txt");
    end = 0;
    start = 0;
    while(getline(inFile, new_line)){
       size_t pos = 0;
       while ((pos = new_line.find(delimiter)) != std::string::npos) {
          values.push_back(new_line.substr(0, pos));
          new_line.erase(0, pos + delimiter.length());
       }
       values.push_back(new_line);
        Media *mp = new Film(values[0],values[1], values[2], values[3],
                             values[4],values[5]);
        card_catalog.push_back(mp);
        values.clear();
    }

    inFile.close();

    //Video.txt file read and load to card catalog

    inFile.open("video.txt");
    end = 0;
    start = 0;
    while(getline(inFile, new_line)){
       size_t pos = 0;
       while ((pos = new_line.find(delimiter)) != std::string::npos) {
          values.push_back(new_line.substr(0, pos));
          new_line.erase(0, pos + delimiter.length());
       }
       values.push_back(new_line);
        Media *mp = new Video(values[0],values[1], values[2], values[3],
                             values[4],values[5], values[6], values[7]);
        card_catalog.push_back(mp);
        values.clear();
    }

    inFile.close();

    //Periodic.txt file read and load to card catalog 

    inFile.open("periodic.txt");
    end = 0;
    start = 0;
    while(getline(inFile, new_line)){
       size_t pos = 0;
       while ((pos = new_line.find(delimiter)) != std::string::npos) {
          values.push_back(new_line.substr(0, pos));
          new_line.erase(0, pos + delimiter.length());
       }
       values.push_back(new_line);
        Media *mp = new Periodical(values[0],values[1], values[2], values[3],
                              values[4],values[5], values[6], values[7],
                              values[8],values[9], values[10], values[11]);
        card_catalog.push_back(mp);
        values.clear();
    }

    inFile.close();
}

//looks for the call number, provided string in the card catalog at each obj
std::vector<Media*> Library::find_everything_with_call_number(const std::string& ss) const {
    std::vector<Media*> results;
    unsigned int i;
    for (i = 0; i < card_catalog.size(); i++){
        if (card_catalog[i]->got_call_number(ss)){
            results.push_back(card_catalog[i]);
        }
    }
    return results;
}

//looks for the title, provided string in the card catalog at each obj
std::vector<Media*> Library::find_everything_with_title(const std::string& ss) const {
    std::vector<Media*> results;
    unsigned int i;
    for (i = 0; i < card_catalog.size(); i++){
        if (card_catalog[i]->got_title(ss)){
            results.push_back(card_catalog[i]);
        }
    }
    return results;
}

//looks for the subjects, provided string in the card catalog at each obj
std::vector<Media*> Library::find_everything_with_subject(const std::string& ss) const {
    std::vector<Media*> results;
    unsigned int i;
    for (i = 0; i < card_catalog.size(); i++){
        if (card_catalog[i]->got_subjects(ss)){
            results.push_back(card_catalog[i]);
        }
    }
    return results;
}

//looks for the other, provided string in the card catalog at each obj
std::vector<Media*> Library::find_everything_with_other(const std::string& ss) const {
    std::vector<Media*> results;
    unsigned int i;
    for (i = 0; i < card_catalog.size(); i++){
        if (card_catalog[i]->got_other(ss)){
            results.push_back(card_catalog[i]);
        }
    }
    return results;
}

//Library destructor and clears off the card catalog memory.
Library::~Library(){

    for (int i = 0; i < card_catalog.size(); i++){
        delete card_catalog[i];
    }
   
}
