#include <cpr/cpr.h>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void print_response(const cpr::Response& response) {
    if (response.status_code == 0 || response.status_code >= 400) {
        std::cerr << "Error processing request." << std::endl;
        if (!response.error.message.empty()) {
            std::cerr << "Error Message: " << response.error.message << std::endl;
        } else {
            std::cerr << "HTTP Status Code: " << response.status_code << std::endl;
        }
        exit(1);
    }

    std::cout << "--- HTTP Request Successful ---" << std::endl;
    std::cout << "Status code: " << response.status_code << std::endl;
    std::cout << "URL: " << response.url << std::endl;

    // --- THIS BLOCK IS THE FIX ---
    std::string content_type;
    auto it = response.header.find("content-type");
    if (it != response.header.end()) {
        content_type = it->second; // it->second is the value from the map
    }
    // --- END FIX ---

    if (content_type.find("application/json") != std::string::npos) {
        try {
            json parsed_json = json::parse(response.text);
            std::cout << "Response JSON:\n" << parsed_json.dump(4) << std::endl;
        } catch (const json::parse_error& e) {
            std::cerr << "JSON Parse Error: " << e.what() << std::endl;
            std::cerr << "Printing raw text instead." << std::endl;
            std::cout << "Response Text:\n" << response.text << std::endl;
        }
    } else {
        std::cout << "Response Text:\n" << response.text << std::endl;
    }
}

int main(int argc, char* argv[]) {
    cpr::Response response;

    if (argc == 2) {
        response = cpr::Get(cpr::Url{argv[1]});
    } 
    else if (argc == 4 && std::string(argv[1]) == "POST") {
        std::string url_str = argv[2];
        std::string data_payload = argv[3];
        response = cpr::Post(cpr::Url{url_str}, 
                               cpr::Body{data_payload},
                               cpr::Header{{"Content-Type", "text/plain"}});
    } 
    else {
        std::cerr << "Invalid arguments." << std::endl;
        std::cerr << "Usage for GET: ./http_client <URL>" << std::endl;
        std::cerr << "Usage for POST: ./http_client POST <URL> \"<DATA>\"" << std::endl;
        return 1;
    }

    print_response(response);
    return 0;
}