#include <dangerfarm/boilerplate.h>
#include <dangerfarm/content.h>
#include <dangerfarm/control.h>
#include <dangerfarm/file.h>
#include <dangerfarm/html.h>
#include <dangerfarm/page_context.h>
#include <dangerfarm/status_codes.h>

static int main_content(page_context* context, FILE* out);

/**
 * \brief Create the jemu65c02 page.
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
int project_jemu65c02_index(page_context* context, FILE* output)
{
    int retval;

    WRITE_FILE(done, "static-site/projects/jemu65c02/index.html", {
        PAGE_TITLE(done, "danger.farm jemu65c02 project", {
            PAGE_URL(done, "https://danger.farm/projects/jemu65c02/", {
                PAGE_SITE_NAME(done, "danger.farm", {
                    PAGE_SITE_DESCRIPTION(done,
                        "The jemu65c02 emulator project.", {
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
        XTEXT(done, "The jemu65c02 Emulator");
        XSUCCESS();
    });

    XP(done, {
        XTEXT(done,
            "Coming soon.");
        XSUCCESS();
    });

    XSUCCESS();
}
