#ifndef OBJECT_H
#define OBJECT_H
#include <string.h> 
class Object
{
public:
   virtual bool validateObject(const std::string &input, Object &object);
};

#endif