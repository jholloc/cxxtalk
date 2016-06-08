//
// Created by Jonathan Hollocombe on 07/06/2016.
//

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

struct File {
    File(const std::string& file_name) : fid_(fopen(file_name.c_str(), "w")) {}
    ~File() { fclose(fid_); }

    // Move constructor
    File(File&& other) {
        fid_ = other.fid_;
        other.fid_ = nullptr;
    }

    // Make this non-copyable
    File(const File&) = delete;
    File& operator=(const File&) = delete;

    FILE* fid() { return fid_; }

private:
    FILE* fid_ = nullptr;
};

int main()
{
    File file{ "myfile.txt" };
    // File new_file = file;
    File new_file = std::move(file);

    std::cout << file.fid() << std::endl;
    std::cout << new_file.fid() << std::endl;

    std::vector<File> files;
    files.emplace_back("myfile.txt");
    files.push_back(File{"myfile.txt"});

    return 0;
}