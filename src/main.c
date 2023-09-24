#include <dangerfarm/directory.h>
#include <dangerfarm/status_codes.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int retval;
    (void)argc;
    (void)argv;

    printf("Creating directories...\n");

    retval = make_site_directories();
    if (STATUS_SUCCESS != retval)
    {
        fprintf(stderr, "Error creating directories.\n");
        goto fail;
    }

    return 0;

fail:
    return 1;
}
