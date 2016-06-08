//
// Created by Jonathan Hollocombe on 06/06/2016.
//

#ifndef CXXTALK_SMART_POINTERS_H
#define CXXTALK_SMART_POINTERS_H

#include <string>
#include <memory>

namespace cxxtalk {

struct File {
    File(const std::string& file_name) : fid_(fopen(file_name.c_str(), "w")) {}
    ~File() { fclose(fid_); }

private:
    FILE* fid_;
};

struct SmartPointers {
    SmartPointers(const std::string& file_name)
    {
        unique_file_ = std::make_unique<File>(file_name);
        shared_file_ = std::make_shared<File>(file_name);
    }

    std::unique_ptr<File> transfer_ownership()
    {
        return std::move(unique_file_);
    }

    std::shared_ptr<File> share_ownership()
    {
        return shared_file_;
    }

private:
    std::unique_ptr<File> unique_file_;
    std::shared_ptr<File> shared_file_;
};

}

#endif //CXXTALK_SMART_POINTERS_H
