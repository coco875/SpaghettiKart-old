#pragma once

#include <libultraship.h>
#include "GameObject.h"
#include "Cup.h"

extern "C" {
#include "camera.h"
#include "objects.h"
#include "engine/Engine.h"
};

class Cup; // <-- Forward declaration
class Course;

class World {
  public:
    // Actor actors;
    virtual ~World() = default;
    explicit World();

    // virtual Actor* SpawnActor(std::unique_ptr<GameActor> actor);

    virtual Object* SpawnObject(std::unique_ptr<GameObject> object);

    virtual CProperties* GetCourseProps();
    virtual void UpdateObjects();
    virtual void RenderObjects(Camera* camera);
    virtual void ExpiredObjects();
    virtual void DestroyObjects();
    virtual Object* GetObjectByIndex(size_t);

    Cup* AddCup(const char* name, std::vector<Course*> courses);
    Cup* GetCup();
    const char* GetCupName();
    virtual u32 GetCupIndex();
    virtual void SetCupIndex(int16_t courseId);
    virtual u32 NextCup();
    virtual u32 PreviousCup();
    void SetCourseFromCup();
    void SetCourseFromId(int id);
    void SetCup();

    World* GetWorld();

    // These are only for browsing through the course list
    void SetCourse(const char*);
    void NextCourse(void);
    void PreviousCourse(void);

    // Holds all available courses

    Course* CurrentCourse;
    Cup* CurrentCup;

    std::vector<Cup*> Cups;
    size_t CupIndex = 1;

    std::vector<std::unique_ptr<GameObject>> GameObjects;
    // std::vector<std::unique_ptr<GameActor>> GameActors;

    std::vector<Course*> Courses;
    size_t CourseIndex = 0; // For browsing courses.
  private:
};

extern World gWorldInstance;
uint64_t GetCurrentCourse();