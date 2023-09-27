#include <dangerfarm/content.h>
#include <dangerfarm/file.h>
#include <dangerfarm/html.h>
#include <dangerfarm/status_codes.h>

/**
 * \brief Create the CSS file.
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
int css_file(page_context* context, FILE* out)
{
    int retval;

    WRITE_FILE(done, "static-site/css/main.css", {
        COPY_FILE(done, "../css/main.css");
        XSUCCESS();
    });

    XSUCCESS();
}
