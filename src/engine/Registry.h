#include "Course.h"

int registryCourse(char* idName, std::function<Course*()> courseFunction);
int registryCup(char* idName, std::function<Cup*()> cupFunction);