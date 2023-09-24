#include <dangerfarm/control.h>
#include <dangerfarm/page_context.h>
#include <dangerfarm/status_codes.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Create a default page context and pass it to the given callback.
 *
 * \param callback              The callback to call with the context.
 * \param out                   The output file for this callback operation.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_default_page_context(callback_fn callback, FILE* out)
{
    int retval;
    page_context* context;

    /* allocate memory for the page context. */
    context = (page_context*)malloc(sizeof(*context));
    if (NULL == context)
    {
        retval = ERROR_DANGERFARM_MEMORY;
        goto done;
    }

    /* clear context. */
    memset(context, 0, sizeof(*context));

    /* set defaults. */
    context->title = "danger.farm";
    context->url = "https://danger.farm";
    context->site_name = "danger.farm";
    context->description = "Danger Farm";

    /* call the callback. */
    TRY_OR_FAIL(callback(context, out), cleanup_context);

    /* success. */
    retval = STATUS_SUCCESS;
    goto cleanup_context;

cleanup_context:
    memset(context, 0, sizeof(*context));
    free(context);

done:
    return retval;
}
