#include "position.h"
#include <stdlib.h>
#include <time.h>

void random_point(Position *position, int max) {

    srand(time(NULL));
    position->x = (double)(rand() % max);
    position->y = (double)(rand() % max);

}