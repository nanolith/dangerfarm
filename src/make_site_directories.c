#include <dangerfarm/directory.h>
#include <dangerfarm/status_codes.h>
#include <sys/stat.h>

static int build_dir(const char* dirname);

/**
 * \brief Attempts to create the static-site directory structure.
 *
 * \note This function will not overwrite an existing static-site directory
 * structure and will instead return an error if an attempt is made to overwrite
 * existing data. This is a safety measure.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int make_site_directories()
{
    int retval;

    /* create the static-site base directory. */
    retval = build_dir("static-site");
    if (STATUS_SUCCESS != retval)
    {
        goto done;
    }

done:
    return retval;
}

/**
 * \brief Build a directory with the given name and default permissions.
 *
 * \param dirname           The name of the directory to build.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int build_dir(const char* dirname)
{
    int retval;

    retval =
        mkdir(dirname, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
    if (STATUS_SUCCESS != retval)
    {
        return ERROR_DANGERFARM_MKDIR;
    }

    return STATUS_SUCCESS;
}
