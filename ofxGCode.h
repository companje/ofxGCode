//
//  ofxGCode.h
//
//  Created by Rick Companje on 10/19/11.
//  Copyright (c) 2011 Globe4D. All rights reserved.
//

#pragma once

#include "ofMain.h"


class ofxGCode {
public:
    
    void add(string s);
    void addCommand(string cmd, string comment);
    void addCommandWithParams(const char* format, ...);
    void addComment(string s);
    
    void draw();
    
    //files
    void load(string filename, bool clear=true);
    void insert(string filename);
    void save(string filename);
   
    vector<string> lines;
};
