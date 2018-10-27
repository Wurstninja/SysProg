#define bwuah(expr) bwuah_msg(expr, NULL)

#define bwuah_msg(expr, msg) \
    if (!(expr)) \
        __assertion_failed__(__FILE__, __LINE__, msg)

#define bwuah_warn(expr, msg) if(!(expr))fprintf(stderr, "BWUARN: %s\n", msg)

void __assertion_failed__(char* file, int line, char* msg)
{
    fprintf(stderr, "BWUASSERTION: %s : %i\n", file, line);
    if(msg) fprintf(stderr, "     MESSAGE: %s\n", msg);
    exit(EXIT_FAILURE);
}