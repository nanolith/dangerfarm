#include <dangerfarm/control.h>
#include <dangerfarm/directory.h>
#include <dangerfarm/status_codes.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int retval;
    (void)argc;
    (void)argv;

    printf("Creating directories...\n");
    TRY_OR_FAIL_MSG(make_site_directories(), fail, "creating directories");

    /* success. */
    return 0;

fail:
    return 1;
}
