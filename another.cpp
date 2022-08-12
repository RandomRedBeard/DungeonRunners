
#include <mutex>

int main() {
    std::unique_ptr<char[]> buf = std::make_unique<char[]>(16);
    snprintf(buf.get(), 16, "this is a test\n");
    puts(buf.get());
    return 0;
}