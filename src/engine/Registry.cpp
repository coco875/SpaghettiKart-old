#include <vector>
#include <functional>

#include "Registry.h"
#include "Course.h"
#include "World.h"

template <class T> Registry<T>::Registry() {
}

template <class T> int Registry<T>::add(char* nameId, std::function<T*()> fun) {
    int id = types.size();
    types.push_back({ nameId, fun });
    return id;
}

template <class T> T* Registry<T>::getWithNameId(char* nameId) {
    for (infoRegister<T> r : types) {
        if (strcmp(r.nameId, nameId) == 0) {
            return r.f();
        }
    }
}

template <class T> T* Registry<T>::getWithId(int id) {
    return types[id].f();
}

template <class T> int Registry<T>::fromNameIdGetId(char* nameId) {
    for (int i = 0; i < types.size(); i++) {
        if (strcmp(types[i].nameId, nameId) == 0) {
            return i;
        }
    }
}

Registry<Course> registryCourse;
Registry<Cup> registrycup;

int addCourse(char* nameId, Course* course) {
    int id = registryCourse.add(nameId, [course]() { return course; });
    gWorldInstance.Courses.push_back(registryCourse.getWithId(id));
    return id;
}

int addCup(char* nameId, Cup* cup) {
    int id = registrycup.add(nameId, [cup]() { return cup; });
    gWorldInstance.Cups.push_back(registrycup.getWithId(id));
    return id;
}

template class Registry<Course>; // really dumb
template class Registry<Cup>;