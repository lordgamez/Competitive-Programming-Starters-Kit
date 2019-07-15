/**
 *   Copyright 2019 Rajdeep Roy Chowdhury <rrajdeeproychowdhury@gmail.com>
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */
#include "SourceFile.h"
#include "BaseException.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

#define MAX 100000

void cpsk::SourceFile::commonUtils() {
    this->ensureExtension();
}

cpsk::SourceFile::SourceFile(const string &file_name) {
    this->file_name = file_name;
    comments_enabled = true;
    this->commonUtils();
}

cpsk::SourceFile::SourceFile(const char *file_name) {
    this->file_name = string(file_name);
    comments_enabled = true;
    this->commonUtils();
}

void cpsk::SourceFile::toggleComments() {
    this->comments_enabled ^= true;
}

void cpsk::SourceFile::enableComments() {
    this->comments_enabled = true;
}

void cpsk::SourceFile::disableComments() {
    this->comments_enabled = false;
}

string cpsk::SourceFile::getFileName() const {
    return file_name;
}

bool cpsk::SourceFile::getCommentStatus() const {
    return comments_enabled;
}

bool cpsk::SourceFile::produceSource() const {
    std::fstream template_file;
    std::fstream output_file;
    try {
        std::string file_name = "TEMPLATE";
        std::string file_name_path = getenv("HOME");
        file_name_path += "/.cpsk/";
        file_name_path += file_name;
        template_file.open(file_name_path, std::ios::in);
        output_file.open(this->file_name, std::ios::trunc | std::ios::out);
        char buffer[MAX];
        if (!template_file) {
            throw new cpsk::exceptions::FileNameException();
        }
        while (!template_file.eof()) {
            template_file.getline(buffer, MAX);
            output_file << buffer;
            output_file << std::endl;
        }
        template_file.close();
        output_file.close();
        std::cout << file_name << " successfully created." << std::endl;
        return true;

    } catch (exception e) {
        std::cerr << e.what() << std::endl;
        template_file.close();
        output_file.close();
        return false;
    } catch (...) {
        std::cerr << "Error occured" << std::endl;
        template_file.close();
        output_file.close();
        return false;
    }
    template_file.close();
    output_file.close();
    return true;
}

bool cpsk::SourceFile::ensureExtension() {
    int file_name_length = this->file_name.size();
    string match(".cpp");
    if (this->file_name.size() > 4) {
        if (this->file_name.substr(file_name_length - 4, file_name_length) != match) {
            this->file_name += ".cpp";
            return true;
        }
    } else {
        this->file_name += ".cpp";
        return true;
    }
    return false;
}
