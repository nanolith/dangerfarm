#include <dangerfarm/boilerplate.h>
#include <dangerfarm/control.h>
#include <dangerfarm/file.h>
#include <dangerfarm/html.h>
#include <dangerfarm/page_context.h>
#include <dangerfarm/status_codes.h>
#include <stdio.h>

static int main_content(page_context* context, FILE* out);

/**
 * \brief Create the contact index page.
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
int contact_index(page_context* context, FILE* out)
{
    int retval;

    WRITE_FILE(done, "static-site/contact/index.html", {
        PAGE_TITLE(done, "danger.farm projects", {
            PAGE_URL(done, "https://danger.farm/contact/", {
                PAGE_SITE_NAME(done, "danger.farm", {
                    PAGE_SITE_DESCRIPTION(done,
                        "Contact Danger Farm.", {
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
        XTEXT(done, "Contact Danger Farm");
        XSUCCESS();
    });

    XP(done, {
        XTEXT(done,
            "Contact Form coming soon.");
        XSUCCESS();
    });

    XSUCCESS();
}
