//
// Created by Jonathan Hollocombe on 06/06/2016.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <memory>
#include <string>
#include <exception>

struct File {
    File(const std::string& file_name) : fid_(fopen(file_name.c_str(), "w")) {}
    ~File() { fclose(fid_); }
    bool is_open() { return fid_ != nullptr; }

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

int main()
{
    File* file1 = new File{ "test1.txt" };

    if (!file1->is_open()) {
        throw std::logic_error("something went wrong");
    }

    std::unique_ptr<File> file2{ new File{ "test2.txt" } };             // C++11
    std::unique_ptr<File> file3 = std::make_unique<File>("test3.txt");  // C++14

    delete file1;

    SmartPointers pointers{ "test4.txt" };
    std::shared_ptr<File> shared = pointers.share_ownership();
    std::unique_ptr<File> unique = pointers.transfer_ownership();

    return 0;
}
