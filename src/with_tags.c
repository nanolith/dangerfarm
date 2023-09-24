#include <dangerfarm/control.h>
#include <dangerfarm/html.h>
#include <dangerfarm/status_codes.h>

/**
 * \brief Write the given HTML begin tag, call the callback, then write the
 * given HTML end tag.
 *
 * \param out               The output file to which the tags should be written.
 * \param begin             The begin tag string.
 * \param end               The end tag string.
 * \param callback          The callback to call between begin and end tags.
 * \param context           The context to pass to the callback.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_tags(
    FILE* out, const char* begin, const char* end, callback_fn callback,
    page_context* context)
{
    int retval;

    /* emit the start tag. */
    fprintf(out, "%s\n", begin);

    /* call the callback. */
    TRY_OR_FAIL(callback(context, out), done);

    /* emit the end tag. */
    fprintf(out, "%s\n", end);

    /* success. */
    retval = STATUS_SUCCESS;

done:
    return retval;
}
