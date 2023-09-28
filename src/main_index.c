#include <dangerfarm/boilerplate.h>
#include <dangerfarm/control.h>
#include <dangerfarm/file.h>
#include <dangerfarm/html.h>
#include <dangerfarm/news_content.h>
#include <dangerfarm/page_context.h>
#include <dangerfarm/status_codes.h>
#include <stdio.h>
#include <time.h>

static int main_content(page_context* context, FILE* out);

/**
 * \brief Create the main index page.
 *
 * \note This function assumes that a default page context is passed to it,
 * along with a NULL output file.
 *
 * \param context           The default page context.
 * \param out               NULL and ignored.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int main_index(page_context* context, FILE* out)
{
    int retval;

    WRITE_FILE(done, "static-site/index.html", {
        PAGE_TITLE(done, "danger.farm", {
            PAGE_URL(done, "https://danger.farm/", {
                PAGE_SITE_NAME(done, "danger.farm", {
                    PAGE_SITE_DESCRIPTION(done,
                        "Danger Farm: a personal project site.", {
                        WRAP_TEMPLATE(done, {
                            TRY_OR_FAIL(main_content(context, out), done);
                            XSUCCESS();
                        });
                        XSUCCESS();
                    });
                    XSUCCESS();
                });
                XSUCCESS();
            });
            XSUCCESS();
        });
        XSUCCESS();
    });

    XSUCCESS();
}

/**
 * \brief The main page content.
 *
 * \param context           The default page context.
 * \param out               NULL and ignored.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int main_content(page_context* context, FILE* out)
{
    int retval;

    XH1(done, {
        XTEXT(done, "Danger Farm");
        XSUCCESS();
    });

    XP(done, {
        XTEXT(done,
            "This is my personal project website, meant for deeper dives "
            "into projects. Really, I just like the name and thought it would "
            "make an amusing project blog.");
        XSUCCESS();
    });

    XH2(done, {
        XTEXT(done, "News");
        XSUCCESS();
    });

    XUL(done, {
        size_t count = news_item_count();
        for (size_t i = 0; i < count; ++i)
        {
            /* get the news item. */
            const char* title;
            const char* description;
            const char* url;
            time_t timestamp;
            callback_fn news_page;
            TRY_OR_FAIL(
                news_item_get(
                    i, &title, &description, &url, &timestamp, &news_page),
                    done);

            XLI(done, {
                /* output the date for the item. */
                struct tm tbuf;
                localtime_r(&timestamp, &tbuf);
                char desc[1024];
                strftime(desc, sizeof(desc), "[ %F ] ", &tbuf);
                XTEXT(done, desc);

                XA_HREF(done, url, {
                    XTEXT(done, title);
                    XSUCCESS();
                });
                XSUCCESS();
            });

            /* generate the news item page. */
            TRY_OR_FAIL(with_default_page_context(news_page, NULL), done);
        }
        XSUCCESS();
    });

    XSUCCESS();
}
