#include <unistd.h>
#include <stdexcept>

#include "pipe.h"
#include "utils.h"

PosixPipe::PosixPipe(int flags) {
    if (flags == 0) {
        ENSURE(pipe(fd));
    } else {
        ENSURE(pipe2(fd, flags));
    }
}

PosixPipe::~PosixPipe() {
    (void)close(fd[0]);
    (void)close(fd[1]);
}

int PosixPipe::operator[](int x) {
    if (x == 0) {
        return fd[0];
    } else if (x == 1) {
        return fd[1];
    } else {
        throw std::invalid_argument("Pipe file descriptor index number can't be greater than 1.");
    }
}
