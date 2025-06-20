#include "curl/curl.h"
#include "stdio.h"
#include "time.h"

#define BLUE "\033[34m"
#define BG_BLUE "\033[44m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// config file to save username and city
struct User {
  char name[50];
  char city[20];
};

void SaveUserToFile(struct User user) {
  FILE *file = fopen("user.txt", "w");
  if (file == NULL) {
    printf("Erro ao abrir o arquivo. \n");
    return;
  }
}

void TimeAndDate() {
  time_t now;
  time(&now);
  struct tm *local = localtime(&now);
  printf("Data: %02d/%02d/%02d | ", local->tm_mday, local->tm_mon + 1,
         local->tm_year + 1900);
  printf("Hora: %02d:%02d:%02d\n", local->tm_hour, local->tm_min,
         local->tm_sec);
}

void Citation() { printf("\nEm busca do que é Significativo!"); }

void UserInterface() {
  printf(BLUE, BOLD);
  printf("Alpha \n");
  // printf("░█░░▒█▒██▀░█▒░░█▒░░█▒░▒██▀▒█▀▄░█▄▒▄█\n░▀▄▀▄▀░█▄▄▒█▄▄▒█▄▄▒█▄▄░█▄▄░█▀▄░█▒▀▒█");
  printf("█   █ ██▀ █   █   ██▀ █▀▄ █▄ ▄█\n▀▄▀▄▀ █▄▄ █▄▄ █▄▄ █▄▄ █▀▄ █ ▀ "
         "█\n---------------------------->");
  printf(RESET);

  struct User user = {"Marcos", "abc"};
  printf("%s \nBem Vindo, %s! \n", BOLD, user.name);
  printf(GREEN);
  TimeAndDate();
  Citation();
  // Weather();
  // Animation();

  // Menu
  // go-to some project
  //
}
int main() { UserInterface(); }
