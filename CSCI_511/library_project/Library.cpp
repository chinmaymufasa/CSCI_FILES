#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Library.h"



Library::Library(){
    std::ifstream inFile;

    inFile.open("book.txt");
    std::string new_line;
    int end = 0;
    int start = 0;
    std::vector<std::string> values;
    std::string delimiter = "|";

    while(getline(inFile, new_line)){
       
       size_t pos = 0;
       while ((pos = new_line.find(delimiter)) != std::string::npos) {
          values.push_back(new_line.substr(0, pos));
          new_line.erase(0, pos + delimiter.length());
       }
        values.push_back(new_line);
        Book *mp = new Book(values[0],values[1], values[2], values[3],
                             values[4],values[5], values[6], values[7],
                             values[8],values[9]);
        card_catalog.push_back(mp);

        values.clear();
    }
    
    inFile.close();

    
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

Library::~Library(){
    
    for (int i = 0; i < card_catalog.size(); i++){
        delete card_catalog[i];
    }
   
}
