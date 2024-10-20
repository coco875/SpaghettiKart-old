#include "Course.h"
#include "Cup.h"
#include <unordered_map>

template <class T> class Registry {
  public:
    std::vector<std::function<T*()>> constructor;
    std::unordered_map<std::string, int> types;
    Registry();
    int add(char* name, std::function<T*()>);
    T* getWithNameId(char* nameId);
    T* getWithId(int id);
    int fromNameIdGetId(char* nameId);
};

int addCourse(char* nameId, Course* course);
int addCup(char* nameId, Cup* cup);

extern Registry<Course> registryCourse;
extern Registry<Cup> registrycup;
