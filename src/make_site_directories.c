#include <dangerfarm/control.h>
#include <dangerfarm/directory.h>
#include <dangerfarm/status_codes.h>

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
    TRY_OR_FAIL(simple_mkdir("static-site"), done);
    /* create the css directory. */
    TRY_OR_FAIL(simple_mkdir("static-site/css"), done);
    /* create the js directory. */
    TRY_OR_FAIL(simple_mkdir("static-site/js"), done);
    /* create the img directory. */
    TRY_OR_FAIL(simple_mkdir("static-site/img"), done);

    /* content directories. */
    TRY_OR_FAIL(simple_mkdir("static-site/projects"), done);
    TRY_OR_FAIL(simple_mkdir("static-site/about"), done);
    TRY_OR_FAIL(simple_mkdir("static-site/contact"), done);

done:
    return retval;
}
