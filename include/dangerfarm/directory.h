#pragma once

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
