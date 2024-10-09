#include <vector>
#include <functional>

#include "Registry.h"
#include "Course.h"
#include "World.h"

template <typename T> Registry<T>::Registry() {
}

template <typename T> int Registry<T>::add(char* nameId, std::function<T*()> fun) {
    int id = types.size();
    types.push_back({ nameId, fun });
    return id;
}

template <typename T> T* Registry<T>::getWithNameId(char* nameId) {
    for (infoRegister<T> r : types) {
        if (strcmp(r.nameId, nameId) != 0) {
            return r.f();
        }
    }
}

template <typename T> T* Registry<T>::getWithId(int id) {
    return types[id].f();
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