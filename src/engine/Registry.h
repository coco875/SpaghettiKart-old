#include "Course.h"
#include "Cup.h"

template <typename T> struct infoRegister {
    char* nameId;
    std::function<T*()> f;
};

template <typename T> class Registry {
  public:
    std::vector<infoRegister<T>> types;
    Registry();
    int add(char* name, std::function<T*()>);
    T* getWithNameId(char* nameId);
    T* getWithId(int id);
};

int addCourse(char* nameId, Course* course);
int addCup(char* nameId, Cup* cup);