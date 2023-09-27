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

    /* create initial directories. */
    printf("Creating directories...\n");
    TRY_OR_FAIL_MSG(make_site_directories(), fail, "creating directories");

    printf("Creating content...\n");

    /* copy the CSS file to static-site. */
    TRY_OR_FAIL_MSG(
        with_default_page_context(css_file, NULL), fail,
        "creating CSS file");

    /* Create the main index. */
    TRY_OR_FAIL_MSG(
        with_default_page_context(main_index, NULL), fail,
        "creating main index");

    /* success. */
    printf("Success.\n");

    return 0;

fail:
    return 1;
}
