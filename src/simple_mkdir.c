#include <dangerfarm/directory.h>
#include <dangerfarm/status_codes.h>
#include <sys/stat.h>

/**
 * \brief Build a directory with the given name and default permissions.
 *
 * \param dirname           The name of the directory to build.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int simple_mkdir(const char* dirname)
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
