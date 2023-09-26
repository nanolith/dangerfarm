#include <dangerfarm/control.h>
#include <dangerfarm/page_context.h>
#include <dangerfarm/status_codes.h>

/**
 * \brief Override the site name in a page context, and call the callback with
 * the updated page context.
 *
 * \param site_name             The site name to override.
 * \param context               The context to override.
 * \param callback              The callback to call with the context.
 * \param out                   The output file for this callback operation.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_page_site_name(
    const char* site_name, page_context* context, callback_fn callback,
    FILE* out)
{
    int retval;
    const char* old_site_name;

    /* preserve the old site name. */
    old_site_name = context->site_name;

    /* set the new site name. */
    context->site_name = site_name;

    /* call the callback. */
    TRY_OR_FAIL(callback(context, out), reset_old_site_name);

    /* success. */
    retval = STATUS_SUCCESS;
    goto reset_old_site_name;

reset_old_site_name:
    context->site_name = old_site_name;

done:
    return retval;
}
