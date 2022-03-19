 /* dquote.c - Print inspiring life quotes everytime your
  * software crashes.
  *
  * The author disclaims copyright to this source code.
  * In place of a legal notice, here is a blessing:
  * 
  *    May you do good and not evil.
  *
  *    May you find forgiveness for yourself and forgive others.
  *
  *    May you share freely, never taking more than you give.
  *
  **/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

const uint32_t nb_quotes = 346;

typedef struct quote_t quote_t;
struct quote_t {
  char *quote;
};
static const quote_t quotes[] = {
  #include "quotes.txt"
};
static uint32_t i = 0;
static void print_quote(int sig, siginfo_t *info, void *ucontext) {
  write(2, "Segmentation fault\n", 19);
  write(2, quotes[i].quote, strlen(quotes[i].quote));
  _exit(1);
}

void register_deadquote(void){
  srand(time(NULL));
  i = (uint32_t)rand() % nb_quotes;
  struct sigaction sa = {0};
  sa.sa_sigaction = &print_quote;
  sa.sa_flags = SA_SIGINFO;
  sigaction(SIGSEGV, &sa, NULL);
}
