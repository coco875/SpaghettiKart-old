#include <vector>
#include <functional>

#include "Course.h"
#include "World.h"

int registryCourse(char* idName, std::function<Course*()> courseFunction) {
    int id = gWorldInstance.Courses.size();
    gWorldInstance.Courses.push_back(courseFunction());
    return id;
}

int registryCup(char* idName, std::function<Cup*()> cupFunction) {
    int id = gWorldInstance.Cups.size();
    gWorldInstance.Cups.push_back(cupFunction());
    return id;
}