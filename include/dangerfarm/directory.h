#pragma once

#include <dangerfarm/callback.h>

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
int make_site_directories();

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
int with_mkdir(const char dirname, callback_fn callback, void* context);

/**
 * \brief Build a directory with the given name and default permissions.
 *
 * \param dirname           The name of the directory to build.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int simple_mkdir(const char* dirname);
