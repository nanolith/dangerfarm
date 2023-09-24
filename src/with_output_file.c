#include <dangerfarm/control.h>
#include <dangerfarm/file.h>
#include <dangerfarm/status_codes.h>

/**
 * \brief Attempts to open the given file for writing, passing it to the
 * provided callback function along with the provided context.
 *
 * \note The file is closed when the callback function returns.
 *
 * \param filename              The name of the file to open for writing.
 * \param callback              The callback function to call when this file is
 *                              opened for writing.
 * \param context               The context value to pass to the callback
 *                              function.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - non-zero error code on failure.
 */
int with_output_file(
    const char* filename, callback_fn callback, page_context* context)
{
    int retval, release_retval;
    FILE* out = NULL;

    /* create the output file. */
    out = fopen(filename, "w");
    if (NULL == out)
    {
        retval = ERROR_DANGERFARM_FOPEN;
        goto done;
    }

    /* call the callback. */
    TRY_OR_FAIL(callback(context, out), cleanup_out);

    /* success. */
    retval = STATUS_SUCCESS;
    goto cleanup_out;

cleanup_out:
    release_retval = fclose(out);
    if (STATUS_SUCCESS != release_retval)
    {
        retval = release_retval;
    }

done:
    return retval;
}
