#include <dangerfarm/control.h>
#include <dangerfarm/html.h>
#include <dangerfarm/status_codes.h>

/**
 * \brief Write the following anchor href tag.
 *
 * \param out               The output file to which the tags should be written.
 * \param callback          The callback to call between begin and end tags.
 * \param context           The context to pass to the callback.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_anchor_href_tags(
    FILE* out, const char* href, callback_fn callback, page_context* context)
{
    int retval;

    /* emit the start tag. */
    fprintf(out, "<a href=\"%s\">\n", href);

    /* call the callback. */
    TRY_OR_FAIL(callback(context, out), done);

    /* emit the end tag. */
    fprintf(out, "</a>\n");

    /* success. */
    retval = STATUS_SUCCESS;

done:
    return retval;
}
