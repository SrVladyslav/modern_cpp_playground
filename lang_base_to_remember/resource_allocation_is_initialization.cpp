#include <iostream>
#include <cstdio>
#include <cstring>
#include <system_error>

struct File
{
    File(const char *path, bool write)
    {
        auto file_mode = write ? "w" : "r";
        // If anything goes wrong, the pointer will be set to nullptr
        file_pointer = fopen(path, file_mode);
        if (!file_pointer)
            throw std::system_error(errno, std::system_category());
    }

    ~File()
    {
        fclose(file_pointer);
    }

    FILE *file_pointer;
};

int main()
{
    {
        File file("data/poc_file_raii.txt", true);
        const auto message = "Hello World!";

        fwrite(message, strlen(message), 1, file.file_pointer);
        // Here the file is closed since we are out of scope
    }

    {
        File file("data/poc_file_raii.txt", false);
        char read_message[12]{};
        fread(read_message, sizeof(read_message), 1, file.file_pointer);

        printf("Read last message: %s\n", read_message);
    }

    return 0;
}