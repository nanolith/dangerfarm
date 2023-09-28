#pragma once

#include <dangerfarm/callback.h>
#include <dangerfarm/control.h>
#include <dangerfarm/lambda.h>

/**
 * \brief Write the given HTML begin tag, call the callback, then write the
 * given HTML end tag.
 *
 * \param out               The output file to which the tags should be written.
 * \param begin             The begin tag string.
 * \param end               The end tag string.
 * \param callback          The callback to call between begin and end tags.
 * \param context           The context to pass to the callback.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_tags(
    FILE* out, const char* begin, const char* end, callback_fn callback,
    page_context* context);

/**
 * \brief Write the following anchor href tag.
 *
 * \param out               The output file to which the tags should be written.
 * \param callback          The callback to call between begin and end tags.
 * \param context           The context to pass to the callback.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_anchor_href_tags(
    FILE* out, const char* href, callback_fn callback, page_context* context);

/* end of tag body. */
#define XSUCCESS() \
    retval = STATUS_SUCCESS; \
    done: return retval

/* html tag. */
#define XHTML(fail_label, body) \
    TRY_OR_FAIL(\
        with_tags(out, "<html>", "</html>", \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* head tag. */
#define XHEAD(fail_label, body) \
    TRY_OR_FAIL(\
        with_tags(out, "<head>", "</head>", \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* body tag. */
#define XBODY(fail_label, body) \
    TRY_OR_FAIL(\
        with_tags(out, "<body>", "</body>", \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* meta http equiv tag. */
#define XMETA_HTTP_EQUIV(fail_label, equiv, content) \
    fprintf( \
        out, "<meta http-equiv=\"%s\" content=\"%s\" />\n", (equiv), (content))

/* meta charset tag. */
#define XMETA_CHARSET(fail_label, charset) \
    fprintf(out, "<meta charset=\"%s\" />\n", (charset))

/* meta name tag. */
#define XMETA_NAME(fail_label, name, content) \
    fprintf(out, "<meta name=\"%s\" content=\"%s\" />\n", (name), (content))

/* meta viewport tag. */
#define XMETA_VIEWPORT(fail_label, viewport) \
    XMETA_NAME(fail_label, "viewport", viewport)

/* meta property tag. */
#define XMETA_PROPERTY(fail_label, property, content) \
    fprintf( \
        out, "<meta property=\"%s\" content=\"%s\" />\n", (property), \
        (content))

/* title tag. */
#define XTITLE(fail_label, body) \
    TRY_OR_FAIL(\
        with_tags(out, "<title>", "</title>", \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* link rel tag. */
#define XLINK_REL(fail_label, rel, href) \
    fprintf(out, "<link rel=\"%s\" href=\"%s\" />\n", (rel), (href))

/* script with type tag. */
#define XSCRIPT_TYPE(fail_label, type, body) \
    TRY_OR_FAIL(\
        with_tags(out, "<script type=\"" type "\">", "</script>", \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* link rel type tag. */
#define XLINK_REL_TYPE(fail_label, rel, type, href) \
    fprintf( \
        out, "<link rel=\"%s\" type=\"%s\" href=\"%s\" />\n", \
        (rel), (type), (href))

/* main tag. */
#define XMAIN(fail_label, body) \
    TRY_OR_FAIL(\
        with_tags(out, "<main>", "</main>", \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* header tag. */
#define XHEADER(fail_label, body) \
    TRY_OR_FAIL(\
        with_tags(out, "<header>", "</header>", \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* footer tag. */
#define XFOOTER(fail_label, body) \
    TRY_OR_FAIL(\
        with_tags(out, "<footer>", "</footer>", \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* div class tag. */
#define XDIV_CLASS(fail_label, clazz, body) \
    TRY_OR_FAIL(\
        with_tags(out, "<div class=\"" clazz "\">", "</div>", \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* ul tag. */
#define XUL(fail_label, body) \
    TRY_OR_FAIL(\
        with_tags(out, "<ul>", "</ul>", \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* li tag. */
#define XLI(fail_label, body) \
    TRY_OR_FAIL(\
        with_tags(out, "<li>", "</li>", \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* a href tag. */
#define XA_HREF(fail_label, href, body) \
    TRY_OR_FAIL(\
        with_anchor_href_tags(out, (href), \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* h1 tag. */
#define XH1(fail_label, body) \
    TRY_OR_FAIL(\
        with_tags(out, "<h1>", "</h1>", \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* h2 tag. */
#define XH2(fail_label, body) \
    TRY_OR_FAIL(\
        with_tags(out, "<h2>", "</h2>", \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* p tag. */
#define XP(fail_label, body) \
    TRY_OR_FAIL(\
        with_tags(out, "<p>", "</p>", \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)

/* emit text. */
#define XTEXT(fail_label, text) \
    fprintf(out, "%s", (text))
