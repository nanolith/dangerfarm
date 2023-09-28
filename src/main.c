#include <dangerfarm/boilerplate.h>
#include <dangerfarm/content.h>
#include <dangerfarm/control.h>
#include <dangerfarm/directory.h>
#include <dangerfarm/html.h>
#include <dangerfarm/page_context.h>
#include <dangerfarm/status_codes.h>
#include <stdio.h>

static callback_fn root_pages[] = {
    css_file,
    main_index,
    project_index,
    about_index,
};

int main(int argc, char* argv[])
{
    int retval;
    (void)argc;
    (void)argv;

    /* create initial directories. */
    printf("Creating directories...\n");
    TRY_OR_FAIL_MSG(make_site_directories(), fail, "creating directories");

    printf("Creating content...\n");

    /* create root pages. */
    for (size_t i = 0; i < sizeof(root_pages) / sizeof(callback_fn); ++i)
    {
        /* generate page. */
        TRY_OR_FAIL_MSG(
            with_default_page_context(root_pages[i], NULL), fail,
            "creating page");
    }

    /* success. */
    printf("Success.\n");

    return 0;

fail:
    return 1;
}
