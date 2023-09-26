#include <dangerfarm/control.h>
#include <dangerfarm/page_context.h>
#include <dangerfarm/status_codes.h>

/**
 * \brief Override the description in a page context, and call the callback with
 * the updated page context.
 *
 * \param description           The description to override.
 * \param context               The context to override.
 * \param callback              The callback to call with the context.
 * \param out                   The output file for this callback operation.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_page_description(
    const char* description, page_context* context, callback_fn callback,
    FILE* out)
{
    int retval;
    const char* old_description;

    /* preserve the old description. */
    old_description = context->description;

    /* set the new description. */
    context->description = description;

    /* call the callback. */
    TRY_OR_FAIL(callback(context, out), reset_old_description);

    /* success. */
    retval = STATUS_SUCCESS;
    goto reset_old_description;

reset_old_description:
    context->description = old_description;

done:
    return retval;
}
