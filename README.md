# C++ Command-Line HTTP Client

A simple, command-line HTTP client written in C++ for making `GET` and `POST` requests. This tool automatically parses and pretty-prints JSON responses for easy readability.

-----

## Features

  * Perform **HTTP GET** requests to any URL.
  * Perform **HTTP POST** requests with a raw text body.
  * Automatically detects and pretty-prints **JSON** responses.
  * Handles basic network and HTTP status code errors.
  * Built using modern C++ and CMake.

-----

## Prerequisites

Before building, ensure you have the following tools installed.

On Debian-based systems (like Debian, Ubuntu, or WSL):

```bash
sudo apt update
sudo apt install build-essential cmake git libcurl4-openssl-dev
```

-----

## Build Instructions

1.  **Clone the repository** (if you haven't already):

    ```bash
    git clone <your-repo-url>
    cd http_client
    ```

2.  **Configure the project with CMake**. This will also download the required dependencies.

    ```bash
    cmake -B build
    ```

3.  **Compile the source code**:

    ```bash
    cmake --build build
    ```

The final executable will be located at `build/http_client`.

-----

## Usage

The client can be run from the root directory of the project.

### GET Request

To perform a `GET` request, provide the URL as an argument.

```bash
./build/http_client https://api.ipify.org?format=json
```

### POST Request

To perform a `POST` request, specify the method, URL, and the data payload in quotes.

```bash
./build/http_client POST https://jsonplaceholder.typicode.com/posts "Hello, World!"
```

-----

## Dependencies

This project uses modern C++ and leverages the following excellent libraries, which are fetched automatically by CMake:

  * [**cpr (C++ Requests)**](https://github.com/libcpr/cpr): For handling HTTP requests.
  * [**nlohmann/json**](https://github.com/nlohmann/json): For parsing and formatting JSON.
