#include <fstream>

#include "File.h"

File::File()
{
    readGrid("right.txt", rightGrid_);
    readGrid("test.txt", testGrid_);
}

void File::readGrid (const char* filename, Grid & grid )
{
    std::ifstream fin (filename);
    std::vector <std::string> strVec;
    if (!fin.is_open())
    {
        std::cout << "Error : file is not opened " << std::endl;
    }
    std::string str;
    while (getline(fin, str))
    {
        if (str[str.length()])
        {
            str.erase(str.length()-1,str.length()-1);
        }
        strVec.push_back(str);
    }
    fin.close();
    std::vector<int> intVec;
    for(int i = 0; i < strVec.size(); i++)
    {
        for (int j = 0; j < strVec[0].size(); ++j)
        {
            if (strVec[i][j] != ' ') intVec.push_back((strVec[i][j] == '1') ? 1 : 0);
        }
        grid.push_back(intVec);
        intVec.clear();
    }
}

const Grid & File::getRightGrid() const
{
    return rightGrid_;
}

void File::showGrid()
{

    for (int i = 0; i < rightGrid_.size(); ++i)
    {
        for (int j = 0; j < rightGrid_[0].size(); ++j)
        {
            std::cout << rightGrid_[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


const Grid & File::getTestGrid() const
{
    return testGrid_;
}
