#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assets/test.h>

#define IMPORT_FUNC(return_type, name) __attribute__((import_name(#name))) return_type name

IMPORT_FUNC(int, call_extern_function)(char* module, char* function_name, int argc, int* argv);
IMPORT_FUNC(void, hook_render)(void());
IMPORT_FUNC(void, gSPDisplayList)(char*);
IMPORT_FUNC(void, load_debug_font)();
IMPORT_FUNC(void, post_debug_print)();
IMPORT_FUNC(void, debug_print_str2)(int x, int y, char*);

int fib(int n) {
    // call_extern_function("test", "testfunc", 0, NULL);
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

void testfunc() {
    printf("call testfunc with the function test\n");
}

IMPORT_FUNC(uint64_t, GetCurrentCourse)();
IMPORT_FUNC(uint64_t, Course_get_ptr_from_id_name)(char*);

uint64_t test_course_id;

IMPORT_FUNC(int, GetCurrentCourseId)();
IMPORT_FUNC(int, Course_get_id_from_id_name)(char*);

void some_render() {
    load_debug_font();
    if (GetCurrentCourseId() == Course_get_id_from_id_name("mk64:test_course")) {
        debug_print_str2(0, 0, "it's a debug course");
    } else {
        debug_print_str2(0, 0, "it's a regular course");
    }
    post_debug_print();
    gSPDisplayList(mario_Plane_001_mesh);
}

int main() {
    printf("init test\n");
    test_course_id = Course_get_id_from_id_name("mk64:test_course");
    hook_render(some_render);
    printf("end init\n");
    return 0;
}