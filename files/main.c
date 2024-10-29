#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    FILE *fp;
    fp = fopen("C:\\Users\\User\\Downloads\\C-Explorations\\files\\file_test.c", "w");

    if (fp) {
        fwrite("#include <stdio.h>\n\nint main(int argc, char **argv) {\n\tprintf(\"Hello world!\\n\");\n\treturn 0;\n}", 1, 93, fp);
    }

    fclose(fp);
    return 0;
}