#include "curl/curl.h"
#include "stdio.h"
#include "time.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define BLUE "\033[34m"
#define BG_BLUE "\033[44m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// storage request
struct string {
  char *ptr;
  size_t len;
};

void init_string(struct string *s) {
  s->len = 0;
  s->ptr = malloc(s->len + 1);
  if (s->ptr == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  s->ptr[0] = '\0';
}
size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s) {
  size_t new_len = s->len + size * nmemb;
  s->ptr = realloc(s->ptr, new_len + 1);
  if (s->ptr == NULL) {
    fprintf(stderr, "realloc() failed\n");
    exit(EXIT_FAILURE);
  }
  memcpy(s->ptr + s->len, ptr, size * nmemb);
  s->ptr[new_len] = '\0';
  s->len = new_len;

  return size * nmemb;
}

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
  printf("Hora: %02d:%02d:%02d", local->tm_hour, local->tm_min, local->tm_sec);
}

void Citation() { printf("\nEm busca do que é Significativo!"); }

void UserInterface() {
  printf("%s%s", BLUE, BOLD);
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
/*
void getWeather(char *city) {
  CURL *curl;
  CURLcode res;
  struct string s;

  init_string(&s);
  curl = curl_easy_init();
  if (curl) {
    char url[256];
    snprintf(url, sizeof(url),
             "http://api.weatherapi.com/v1/current.json?key=YOUR_API_KEY&q=%s",
             city);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    } else {
      printf("Weather data for %s: %s\n", city, s.ptr);
    }
    curl_easy_cleanup(curl);
  }
  free(s.ptr);
}
*/
int main() { UserInterface(); }
