#pragma once

// Base Cup class
#include <vector>
#include <memory>
#include "Course.h"

class Course; // <-- Forward declare

class Cup {
  public:
    int Id;
    char* NameId;
    const char* Name;
    u8* Thumbnail;
    size_t CursorPosition = 0; // Course index in cup
    std::vector<int> Courses;

    explicit Cup(const char* id, const char* name, std::vector<Course*> courses);

    virtual void ShuffleCourses();

    virtual void Next();
    virtual void Previous();
    virtual int GetCourseId();
    virtual void SetCourse(size_t position);
    virtual Course* GetCourse();
    virtual size_t GetSize();
};