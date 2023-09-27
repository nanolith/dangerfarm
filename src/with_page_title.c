#include <dangerfarm/control.h>
#include <dangerfarm/page_context.h>
#include <dangerfarm/status_codes.h>

/**
 * \brief Override the title in a page context, and call the callback with the
 * updated page context.
 *
 * \param title                 The title to override.
 * \param context               The context to override.
 * \param callback              The callback to call with the context.
 * \param out                   The output file for this callback operation.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_page_title(
    const char* title, page_context* context, callback_fn callback, FILE* out)
{
    int retval;
    const char* old_title;

    /* preserve the old title. */
    old_title = context->title;

    /* set the new title. */
    context->title = title;

    /* call the callback. */
    TRY_OR_FAIL(callback(context, out), reset_old_title);

    /* success. */
    retval = STATUS_SUCCESS;
    goto reset_old_title;

reset_old_title:
    context->title = old_title;

done:
    return retval;
}
