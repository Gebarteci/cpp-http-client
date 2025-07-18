#include <cpr/cpr.h>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Please provide a URL." << std::endl;
        std::cerr << "Usage: ./http_client <URL>" << std::endl;
        return 1;
    }

    cpr::Url url = cpr::Url{argv[1]};
    cpr::Response response = cpr::Get(url);

    // --- New Error Handling Block ---
    // Check for network errors (status_code 0) or HTTP errors (status_code >= 400)
    if (response.status_code == 0 || response.status_code >= 400) {
        std::cerr << "Error processing request." << std::endl;
        if (!response.error.message.empty()) {
            std::cerr << "Error Message: " << response.error.message << std::endl;
        } else {
            std::cerr << "HTTP Status Code: " << response.status_code << std::endl;
        }
        return 1;
    }
    // --- End of Error Handling ---

    std::cout << "--- HTTP Request Successful ---" << std::endl;
    std::cout << "Status code: " << response.status_code << std::endl;
    std::cout << "Response Text (first 200 chars): " << response.text.substr(0, 200) << "..." << std::endl;

    return 0;
}