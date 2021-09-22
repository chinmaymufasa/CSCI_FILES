//File: Video.h
#include <iostream>
#include "Media.h"

#ifndef VIDEO_H
#define VIDEO_H



class Video : public Media {
    public:
        Video(const std::string& cn, const std::string& ti, const std::string& su,
             const std::string& de, const std::string& di, const std::string& no,
             const std::string& se, const std::string& lb);
        void display() const;
        bool got_other(const std::string& ot) const;
        //~Video();
    private:
        std::string description;
        std::string distributor;
        std::string series;
        std::string label;
        std::string notes;
};


#endif
