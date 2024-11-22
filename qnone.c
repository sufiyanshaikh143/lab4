#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_valid_float(const char*str) {
    char*endptr;
    strtof(str, &endptr);
    return*endptr == '\0'; 
}

void process_file(const char*input_file, const char*output_file) {
    FILE*src = fopen(input_file, "r");
    FILE*dest = fopen(output_file, "w");

    if (src == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    int invalid_count = 0;

    while (fscanf(src, "%99s", buffer) == 1) { 
        if (is_valid_float(buffer)) {
            fprintf(dest, "%s\n", buffer); 
        } else {
            invalid_count++; 
        }
    }

    if (ferror(src)) {
        perror("Error reading source file");
        fclose(src);
        fclose(dest);
        exit(EXIT_FAILURE);
    }

    fclose(src);
    fclose(dest);

    printf("Number of invalid float values: %d\n", invalid_count);
}

int main() {
    const char*input_file = "data.txt";
    const char*output_file = "cleaned_data.txt";

    process_file(input_file, output_file);

    return 0;
}