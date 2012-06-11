#include "ofxGCode.h"


void ofxGCode::add(string s) {
    lines.push_back(s);
}

void ofxGCode::addCommand(string cmd, string comment) {
    add(cmd + comment!="" ? " (" + comment + ")" : "");
}

void ofxGCode::addCommandWithParams(const char* format, ...) {
    va_list args;
    va_start(args, format);
    add(ofVAArgsToString(format,args));
    va_end(args);
}

void ofxGCode::addComment(string s) {
    add("(**** "+s+" ****)");
}

void ofxGCode::save(string filename) {
    ofstream fileOutput(ofToDataPath(filename).c_str(),ios::out);
    for (int i=0; i<lines.size(); i++) fileOutput << lines[i] << endl;
    fileOutput.close();
}

void ofxGCode::load(string filename, bool clear) {
    ifstream f(ofToDataPath(filename).c_str(),ios::in);
    if (clear) lines.clear();
    string line;
    while (getline(f,line)) lines.push_back(line);
    f.close();
//    return lines;
}

void ofxGCode::insert(string filename) {
    load(filename,false);
}
