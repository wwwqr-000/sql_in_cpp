#include <iostream>
#include <fstream>
#include <regex> //voor replace command.

std::string sql(std::string query, std::string sqlreturn = "leeg") {//SQL Functie.
    //Config
    std::string url = "localhost";
    std::string db = "db_test";
    std::string username = "root";
    std::string password = "";
    std::string conn_file_url = "";
    //
    query = std::regex_replace(query, std::regex("\\ "), "%20");
    query = std::regex_replace(query, std::regex("\\^"), "%5E");
    query = std::regex_replace(query, std::regex("\\'"), "\'");
    password = std::regex_replace(password, std::regex("\\ "), "%20");
    password = std::regex_replace(password, std::regex("\\^"), "%5E");
    system(("curl -s \""+conn_file_url+"/?url="+url+"&db="+db+"&query="+query+"&username="+username+"&password="+password+"&return="+sqlreturn+"\" >> data.url").c_str());
    std::string outvar = "";
    int sqlCounter = 0;
    std::ifstream bestand("data.url");
    while (getline(bestand, outvar)) {
        ++sqlCounter;
        std::cout << sqlCounter << "data: " << outvar << "\n";
    }
    bestand.close();
    //system("del data.url");
    return "";
}

int main() {
    std::cout << sql("SELECT * FROM test", "innertest");
    system("set /p end=");
    return 0;
}
