#include <dangerfarm/boilerplate.h>
#include <dangerfarm/control.h>
#include <dangerfarm/file.h>
#include <dangerfarm/html.h>
#include <dangerfarm/news_content.h>
#include <dangerfarm/page_context.h>
#include <dangerfarm/status_codes.h>
#include <stdio.h>

static int main_content(page_context* context, FILE* out);

/**
 * Website launch.
 */
int news_item_website_launch(page_context* context, FILE* out)
{
    int retval;

    WRITE_FILE(done, "static-site/news/2023/09/28/website_launch.html", {
        PAGE_TITLE(done, "danger.farm Website Launch", {
            PAGE_URL(done,
                "https://danger.farm/news/2023/09/28/website_launch.html", {
                PAGE_SITE_NAME(done, "danger.farm", {
                    PAGE_SITE_DESCRIPTION(done,
                        "[ 2023-09-28 ] - "
                        "Today I launched danger.farm's website.", {
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
        XTEXT(done, "[ 2023-09-28 ] Website Launch");
        XSUCCESS();
    });

    XP(done, {
        XTEXT(done,
            "Today I launched danger.farm. This website contains some of my "
            "projects. I'd like to write some technical articles about these "
            "projects, and this site is intended to allow me to do so.");
        XSUCCESS();
    });

    XP(done, {
        XTEXT(done,
            "I wrote a simple C based static content generator that generates "
            "all of the pages on this website. With all of the templating and "
            "SEO nonsense in a modern website, it's just not possible to write "
            "old school HTML by hand anymore. I cribbed this template from ");
        XA_HREF(done, "https://github.com/b2a3e8/jekyll-theme-console", {
            XTEXT(done, "jekyll-theme-console");
            XSUCCESS();
        });
        XTEXT(done,
            " and used it to skin my own content generator. I'll describe this "
            "content generator as an upcoming project if anyone is "
            "interested.");
        XSUCCESS();
    });

    XP(done, {
        XTEXT(done,
            "For the moment, most of the links on this site are stubbed out. "
            "In the coming weeks and months, I'll work on fleshing this out "
            "a bit more. For those wishing to contact me, I'm going to extract "
            "an HTTP server for the contact form from an abstract machine "
            "proof in Lean 4. Until then, stay tuned.");
        XSUCCESS();
    });

    XSUCCESS();
}
