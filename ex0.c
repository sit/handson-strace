#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle(int sig) {
  if (sig == SIGTERM) {
    exit(0);
  }
  exit(1);
}

int main(int argc, char *argv[]) {
  struct sigaction sa;
  sa.sa_handler = &handle;
  sigset_t s;
  sigemptyset(&s);
  sigaddset(&s, SIGINT);
  sigaddset(&s, SIGTERM);
  sa.sa_mask = s;
  sa.sa_flags = 0;

  sigaction(SIGINT, &sa, NULL);
  sigaction(SIGTERM, &sa, NULL);
  sleep(86400);
}
