#include <dangerfarm/control.h>
#include <dangerfarm/page_context.h>
#include <dangerfarm/status_codes.h>

/**
 * \brief Override the url in a page context, and call the callback with the
 * updated page context.
 *
 * \param url                   The url to override.
 * \param context               The context to override.
 * \param callback              The callback to call with the context.
 * \param out                   The output file for this callback operation.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_page_url(
    const char* url, page_context* context, callback_fn callback, FILE* out)
{
    int retval;
    const char* old_url;

    /* preserve the old url. */
    old_url = context->url;

    /* set the new url. */
    context->url = url;

    /* call the callback. */
    TRY_OR_FAIL(callback(context, out), reset_old_url);

    /* success. */
    retval = STATUS_SUCCESS;
    goto reset_old_url;

reset_old_url:
    context->url = old_url;

done:
    return retval;
}
