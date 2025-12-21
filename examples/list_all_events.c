#include <stdio.h>
#include <stdlib.h>
#include "perf_counter.h"

int main(int argc, char* argv[])
{
    FILE* fp = stdout;
    if (argc > 1)
    {
        fp = fopen(argv[1], "w");
        if (!fp)
        {
            perror("fopen");
            return EXIT_FAILURE;
        }
    }

#ifdef PERF_COUNTER_WITH_LIBPFM
    perf_counter_print_available_events(fp);
#else
    fprintf(stderr, "Error: perf_counter library was built without libpfm support.\n");
    fprintf(stderr, "       Please rebuild with -DPERF_COUNTER_WITH_LIBPFM\n");
#endif

    if (fp != stdout)
    {
        fclose(fp);
    }

    return EXIT_SUCCESS;
}
