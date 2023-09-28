#include <dangerfarm/boilerplate.h>
#include <dangerfarm/content.h>
#include <dangerfarm/control.h>
#include <dangerfarm/file.h>
#include <dangerfarm/html.h>
#include <dangerfarm/page_context.h>
#include <dangerfarm/status_codes.h>
#include <stdio.h>

typedef struct
{
    const char* description;
    const char* url;
    callback_fn project_page;
} project_entry;

project_entry projects[] = {
    { .description = "jemu65c02 emulator",
      .url = "jemu65c02/",
      .project_page = project_jemu65c02_index },
};

static int main_content(page_context* context, FILE* out);

/**
 * \brief Create the project index page.
 *
 * \note This function assumes that a default page context is passed to it,
 * along with a NULL output file.
 *
 * \param context           The default page context.
 * \param out               NULL and ignored.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int project_index(page_context* context, FILE* out)
{
    int retval;

    WRITE_FILE(done, "static-site/projects/index.html", {
        PAGE_TITLE(done, "danger.farm projects", {
            PAGE_URL(done, "https://danger.farm/projects/", {
                PAGE_SITE_NAME(done, "danger.farm", {
                    PAGE_SITE_DESCRIPTION(done,
                        "Danger Farm: a list of personal projects.", {
                        WRAP_TEMPLATE(done, {
                            TRY_OR_FAIL(main_content(context, out), done);
                            XSUCCESS();
                        });
                        XSUCCESS();
                    });
                    XSUCCESS();
                });
                XSUCCESS();
            });
            XSUCCESS();
        });
        XSUCCESS();
    });

    XSUCCESS();
}

/**
 * \brief The main page content.
 *
 * \param context           The default page context.
 * \param out               NULL and ignored.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int main_content(page_context* context, FILE* out)
{
    int retval;

    XH1(done, {
        XTEXT(done, "Danger Farm Projects");
        XSUCCESS();
    });

    XP(done, {
        XTEXT(done, "These are the projects I've recently been working on.");
        XSUCCESS();
    });

    XUL(done, {
        for (size_t i = 0; i < sizeof(projects) / sizeof(project_entry); ++i)
        {
            /* generate the list item. */
            XLI(done, {
                XA_HREF(done, (projects[i].url), {
                    XTEXT(done, projects[i].description);
                    XSUCCESS();
                });
                XSUCCESS();
            });

            /* generate the page. */
            TRY_OR_FAIL(
                with_default_page_context(projects[i].project_page, NULL),
                done);
        }
        XSUCCESS();
    });

    XSUCCESS();
}
