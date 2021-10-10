#include "apue.h"
#include "fileIO.h"
#include "config.h"

int main(int argc, char *argv[])
{
#ifdef USE_APUE_API
    efficientIO();
#else
    printf("no use \n");
    printf("%s Version %d.%d\n", argv[0], APUE_VERSION_MAJOR, APUE_VERSION_MINOR);
#endif
    return 0;
}
