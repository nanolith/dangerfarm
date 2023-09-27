#include <dangerfarm/file.h>
#include <dangerfarm/status_codes.h>
#include <stdint.h>

/**
 * \brief Copy a file to the output stream.
 *
 * \param filename              The name of the file to copy.
 * \param context               The page context.
 * \param out                   The output stream.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int copy_file(
    const char* filename, page_context* context, FILE* out)
{
    int retval;
    FILE* in = NULL;
    uint8_t buffer[4096];

    /* open the input file for reading. */
    in = fopen(filename, "r");
    if (NULL == in)
    {
        retval = ERROR_DANGERFARM_FOPEN;
        goto done;
    }

    /* iterate over the entire file. */
    while (!feof(in))
    {
        /* read data from the buffer. */
        size_t read_len = fread(buffer, 1, sizeof(buffer), in);
        if (feof(in))
        {
            retval = STATUS_SUCCESS;
            goto cleanup_in;
        }

        /* write the data to the output file. */
        fwrite(buffer, 1, read_len, out);
    }

    /* success. */
    retval = STATUS_SUCCESS;
    goto cleanup_in;

cleanup_in:
    fclose(in);

done:
    return retval;
}
