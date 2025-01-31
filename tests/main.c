#define CTEST_MAIN

#include "../src/fstring.h"
#include "ctest.h"

int main(int argc, char **argv)
{
    ctest_main(argc, (const char **)argv);
    return 0;
}

CTEST_DATA(fstring) { fstring_t s; };

CTEST_SETUP(fstring) { fstring_init(&data->s, 0); };

CTEST_TEARDOWN(fstring)
{
    if (data->s.value)
        fstring_free(&data->s);
};

CTEST2(fstring, add_char)
{

    fstring_add_char(&data->s, 'A');
    ASSERT_STR("A", fstring_get(&data->s));
};

CTEST2(fstring, add_string)
{
    fstring_add_string(&data->s, "some string");
    ASSERT_STR("some string", fstring_get(&data->s));
};