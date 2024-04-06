#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

size_t write_callback(char *ptr, size_t size, size_t nmemb, char *data) {
    printf("%s", ptr);
    return size * nmemb;
}

int main() {
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error initializing curl.\n");
        return 1;
    }

		const char *url = "https://api.adviceslip.com/advice";

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        return 1;
    }

    curl_easy_cleanup(curl);

    return 0;
}

