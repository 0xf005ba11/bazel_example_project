#include <time.h>

bool Foo()
{
    return time(nullptr) > 0;
}