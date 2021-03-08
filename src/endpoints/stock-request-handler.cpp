#include "endpoints/stock-request-handler.h"

using namespace dbuddy;

bool StockRequestHandler::canHandle(HTTPMethod method, String uri) {
    return method == HTTP_GET && AbstractRequestHandler::canHandle(method, uri);
}

bool StockRequestHandler::setup(WebServer &server, HTTPMethod requestMethod, String requestUri) {
    if (requestUri.equals("/stock.html")) {
        config->streamFile("/stock.html", mimeHTML);
    } else if (requestUri.equals("/css/stock.css")) {
        config->streamFile("/css/stock.css", mimeCSS);
    } else if (requestUri.equals("/scripts/stock.js")) {
        config->streamFile("/scripts/stock.js", mimeJS);
    } else {
        return false;
    }

    return true;
}
