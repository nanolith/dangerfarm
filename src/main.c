#include <dangerfarm/boilerplate.h>
#include <dangerfarm/content.h>
#include <dangerfarm/control.h>
#include <dangerfarm/directory.h>
#include <dangerfarm/html.h>
#include <dangerfarm/page_context.h>
#include <dangerfarm/status_codes.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int retval;
    (void)argc;
    (void)argv;

    printf("Creating directories...\n");
    TRY_OR_FAIL_MSG(make_site_directories(), fail, "creating directories");

    TRY_OR_FAIL_MSG(
        with_default_page_context(main_index, NULL), fail,
        "creating main index");

    /* success. */
    return 0;

fail:
    return 1;
}
