#include <curl/curl.h>
#include <stdio.h>

int main (int argc, char *argv[]) 
{
	char* jsonObj = "{ \"id\" : \"1211\",\"eventId\" : \"dummy\", \"date\" : \"10-02-2018\" , \"active\" : \"false\" }";


	CURL *curl = curl_easy_init();
	CURLcode res;
	
	struct curl_slist *headers = NULL;
	headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "charsets: utf-8");

	curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:8080/api/eventclicked");
	//curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"id\" : 1211}");
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonObj);
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	
    
	res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return res;
}
