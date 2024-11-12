#include <stdio.h>
#include <curl/curl.h>

int main() {
    CURL *curl;
    CURLcode res;

    // Initialize the CURL session
    curl = curl_easy_init();

    if(curl) {
        // Set the URL of your Firebase Realtime Database endpoint
        const char *url = "https://try1-d5cd2-default-rtdb.asia-southeast1.firebasedatabase.app/sensor_data.json";

        // JSON data to send (temperature and humidity in this case)
        const char *json_data = "{\"temperature\": 23.5, \"humidity\": 60}";

        // Set CURL options
        curl_easy_setopt(curl, CURLOPT_URL, url);                // Set URL
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data);   // Set JSON data as the POST request body
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");    // Set HTTP method to PUT (Firebase uses PUT to update data)

        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);

        // Check for errors
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        else
            printf("Data sent to Firebase successfully!\n");

        // Cleanup
        curl_easy_cleanup(curl);
    }

    return 0;
}
