#include "actor_types.h"
#include "camera.h"

typedef void (*ActorConstructor)(struct Actor*);

void new_render_actor(Camera* camera, Mat4 arg1);
void new_update_actor();
void init_new_actor();