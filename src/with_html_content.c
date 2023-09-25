#include <dangerfarm/boilerplate.h>
#include <dangerfarm/html.h>
#include <dangerfarm/page_context.h>
#include <dangerfarm/status_codes.h>

static int content_security_policy(page_context* context, FILE* out);
static int xss_protection(page_context* context, FILE* out);
static int referrer_policy(page_context* context, FILE* out);
static int charset(page_context* context, FILE* out);
static int ie_user_agent(page_context* context, FILE* out);
static int viewport(page_context* context, FILE* out);
static int title(page_context* context, FILE* out);
static int locale(page_context* context, FILE* out);
static int description(page_context* context, FILE* out);
static int url(page_context* context, FILE* out);
static int site_name(page_context* context, FILE* out);
static int twitter_card(page_context* context, FILE* out);
static int linking_data(page_context* context, FILE* out);
static int stylesheet(page_context* context, FILE* out);

/**
 * \brief Write the header boilerplate for an HTML file, then call the
 * callback at the start of the content, then write the footer boilerplate.
 *
 * \param out                       The output file to which the boilerplate
 *                                  should be written.
 * \param callback                  The callback to call to generate HTML
 *                                  content between boilerplate.
 * \param context                   The context to pass the callback.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_html_content(FILE* out, callback_fn callback, page_context* context)
{
    int retval;

    XHTML(done, {
        XHEAD(done, {
            TRY_OR_FAIL(content_security_policy(context, out), done);
            TRY_OR_FAIL(xss_protection(context, out), done);
            TRY_OR_FAIL(referrer_policy(context, out), done);
            TRY_OR_FAIL(charset(context, out), done);
            TRY_OR_FAIL(ie_user_agent(context, out), done);
            TRY_OR_FAIL(viewport(context, out), done);
            TRY_OR_FAIL(title(context, out), done);
            TRY_OR_FAIL(locale(context, out), done);
            TRY_OR_FAIL(description(context, out), done);
            TRY_OR_FAIL(url(context, out), done);
            TRY_OR_FAIL(site_name(context, out), done);
            TRY_OR_FAIL(twitter_card(context, out), done);
            TRY_OR_FAIL(linking_data(context, out), done);
            TRY_OR_FAIL(stylesheet(context, out), done);
            XSUCCESS(); });
        XBODY(done, {
            XMAIN(done, {
                TRY_OR_FAIL(callback(context, out), done);
                XSUCCESS();
            });
            XSUCCESS();
        });
        XSUCCESS();
    });

    /* success. */
    retval = STATUS_SUCCESS;

done:
    return retval;
}

/**
 * \brief Output the content security policy.
 *
 * \param context           The context for this call.
 * \param out               The output file stream for this call.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int content_security_policy(page_context* context, FILE* out)
{
    int retval;

    XMETA_HTTP_EQUIV(
        done, "Content-Security-Policy",
        "default-src 'none'; "
        "script-src 'self'; "
        "style-src 'self' https://fonts.googleapis.com; "
        "img-src 'self'; "
        "font-src 'self' https://fonts.gstatic.com; "
        "connect-src 'self'; "
        "media-src 'self'; "
        "object-src 'self'; "
        "child-src 'self'; "
        "form-action 'none'; "
        "base-uri 'self'");
    XSUCCESS();
}

/**
 * \brief Output the XSS protection policy.
 *
 * \param context           The context for this call.
 * \param out               The output file stream for this call.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int xss_protection(page_context* context, FILE* out)
{
    int retval;

    XMETA_HTTP_EQUIV(done, "X-XSS-Protection", "1; mode=block");
    XSUCCESS();
}

/**
 * \brief Output the referrer policy.
 *
 * \param context           The context for this call.
 * \param out               The output file stream for this call.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int referrer_policy(page_context* context, FILE* out)
{
    int retval;

    XMETA_HTTP_EQUIV(
        done,
        "Referrer-Policy", "no-referrer, strict-origin-when-cross-origin");
    XSUCCESS();
}

/**
 * \brief Output the charset.
 *
 * \param context           The context for this call.
 * \param out               The output file stream for this call.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int charset(page_context* context, FILE* out)
{
    int retval;

    XMETA_CHARSET(done, "utf-8");
    XSUCCESS();
}

/**
 * \brief Output the IE user agent tag.
 *
 * \param context           The context for this call.
 * \param out               The output file stream for this call.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int ie_user_agent(page_context* context, FILE* out)
{
    int retval;

    XMETA_HTTP_EQUIV(done, "X-UA-Compatible", "IE=edge");
    XSUCCESS();
}

/**
 * \brief Set the viewport.
 *
 * \param context           The context for this call.
 * \param out               The output file stream for this call.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int viewport(page_context* context, FILE* out)
{
    int retval;

    XMETA_VIEWPORT(
        done, "width=device-width, initial-scale=1.0, maximum-scale=1.0, "
              "user-scalable=no");
    XSUCCESS();
}

/**
 * \brief Set the title.
 *
 * \param context           The context for this call.
 * \param out               The output file stream for this call.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int title(page_context* context, FILE* out)
{
    int retval;

    XTITLE(done, {
        fprintf(out, "%s", context->title);
        XSUCCESS();
    });
    XMETA_PROPERTY(done, "og:title", context->title);
    XMETA_PROPERTY(done, "twitter:title", context->title);

    XSUCCESS();
}

/**
 * \brief Set the locale.
 *
 * \param context           The context for this call.
 * \param out               The output file stream for this call.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int locale(page_context* context, FILE* out)
{
    int retval;

    XMETA_PROPERTY(done, "og:locale", "en_us");

    XSUCCESS();
}

/**
 * \brief Set the description.
 *
 * \param context           The context for this call.
 * \param out               The output file stream for this call.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int description(page_context* context, FILE* out)
{
    int retval;

    XMETA_NAME(done, "description", context->description);
    XMETA_PROPERTY(done, "og:description", context->description);

    XSUCCESS();
}

/**
 * \brief Set the URL.
 *
 * \param context           The context for this call.
 * \param out               The output file stream for this call.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int url(page_context* context, FILE* out)
{
    int retval;

    XLINK_REL(done, "canonical", context->url);
    XMETA_PROPERTY(done, "og:url", context->url);

    XSUCCESS();
}

/**
 * \brief Set the site name.
 *
 * \param context           The context for this call.
 * \param out               The output file stream for this call.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int site_name(page_context* context, FILE* out)
{
    int retval;

    XMETA_PROPERTY(done, "og:site_name", context->site_name);

    XSUCCESS();
}

/**
 * \brief Set the Twitter card.
 *
 * \param context           The context for this call.
 * \param out               The output file stream for this call.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int twitter_card(page_context* context, FILE* out)
{
    int retval;

    XMETA_NAME(done, "twitter:card", "summary");

    XSUCCESS();
}

/**
 * \brief Set the linking data.
 *
 * \param context           The context for this call.
 * \param out               The output file stream for this call.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int linking_data(page_context* context, FILE* out)
{
    int retval;

    XSCRIPT_TYPE(done, "application/ld+json", {
        fprintf(
            out,
            "{\"description\":\"%s\","
            "\"url\":\"%s\","
            "\"@type\":\"WebSite\","
            "\"headline\":\"%s\","
            "\"name\":\"%s\","
            "\"@context\":\"https://schema.org\"}",
            context->description, context->url, context->title,
            context->site_name);
        XSUCCESS();
    });

    XSUCCESS();
}

/**
 * \brief Set the stylesheet.
 *
 * \param context           The context for this call.
 * \param out               The output file stream for this call.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
static int stylesheet(page_context* context, FILE* out)
{
    int retval;

    XLINK_REL_TYPE(done, "stylesheet", "text/css", "css/main.css");

    XSUCCESS();
}
