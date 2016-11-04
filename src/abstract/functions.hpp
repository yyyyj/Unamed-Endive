#ifndef DEF_ABS_FUNC
#define DEF_ABS_FUNC

#include <vector>
#include <string>
#include <sstream>
#include <fstream>

template<typename T>
T pop(std::vector<T>* obj, int i) {
    T element {};

    if (0 <= i && i < obj->size())
    {
        element = (*obj)[i];
        obj->erase(obj->begin() + i);
    }
    else if (i < 0 && (-i) < obj->size())
    {
        element = (*obj)[obj->size() + i];
        obj->erase(obj->begin() + obj->size() + i);
    }

    return element;
}

template<typename T>
std::string to_string(const T& n)
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}

bool is_file_existing(const std::string& file)
{
    std::ifstream reader(file.c_str());
    return !reader.fail();
}

#endif // DEF_ABS_FUNC
