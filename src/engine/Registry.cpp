#include <vector>
#include <functional>
#include <iostream>
#include <map>

#include "Registry.h"
#include "Course.h"
#include "port/Game.h"

template <class T> Registry<T>::Registry() {
}

template <class T> int Registry<T>::add(char* nameId, std::function<T*()> fun) {
    int id = constructor.size();
    types[nameId] = id;
    constructor.push_back(fun);
    return id;
}

template <class T> T* Registry<T>::getWithNameId(char* nameId) {
    return constructor[types[nameId]]();
}

template <class T> T* Registry<T>::getWithId(int id) {
    return constructor[id]();
}

template <class T> int Registry<T>::fromNameIdGetId(char* nameId) {
    int id = types[nameId];
    // printf("%s: %d\n", nameId, id);
    // for (auto it = types.begin(); it != types.end(); ++it) {
    //     std::cout << "\t" << it->first << " " << it->second << "\n";
    // }
    return id;
}

Registry<Course> registryCourse;
Registry<Cup> registrycup;

int addCourse(char* nameId, Course* course) {
    int id = registryCourse.add(nameId, [course]() { return course; });
    course->Props.Id = id;
    course->Props.NameId = nameId;
    gWorldInstance.Courses.push_back(registryCourse.getWithId(id));
    return id;
}

int addCup(char* nameId, Cup* cup) {
    int id = registrycup.add(nameId, [cup]() { return cup; });
    cup->Id = id;
    cup->NameId = nameId;
    gWorldInstance.Cups.push_back(registrycup.getWithId(id));
    return id;
}

template class Registry<Course>; // really dumb
template class Registry<Cup>;
