#include <dangerfarm/control.h>
#include <dangerfarm/directory.h>
#include <dangerfarm/status_codes.h>

/**
 * \brief Create the given directory, then call the given callback.
 *
 * \note that the out parameter will be NULL in the callback.
 *
 * \param dirname               The directory name to create.
 * \param callback              The callback function to call.
 * \param context               The context to pass to the callback.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_mkdir(const char* dirname, callback_fn callback, void* context)
{
    int retval;

    /* attempt to create the directory. */
    TRY_OR_FAIL(simple_mkdir(dirname), done);

    /* call the callback. */
    TRY_OR_FAIL(callback(context, NULL), done);

    /* success. */
    retval = STATUS_SUCCESS;

done:
    return retval;
}
