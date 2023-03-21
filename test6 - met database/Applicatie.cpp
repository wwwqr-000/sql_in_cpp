#include <iostream>
#include <fstream>
#include <regex> //voor replace command.

std::string sql(std::string query, std::string sqlreturn = "leeg") {//SQL Functie.
    //Config
    std::string url = "localhost";
    std::string db = "fp245787";
    std::string username = "fp245787";
    std::string password = "html^sql_gggBroak oAk_cpp_jnEFIUB4uirg74jnENJefbjEB";
    std::string conn_file_url = "http://mbo-portal.nl/~fp245787/sql_cpp_to_php.php";
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
    }
    std::string outvarArr[sqlCounter];
    sqlCounter = 0;
    while (getline(bestand, outvar)) {
        ++sqlCounter;
        outvarArr[sqlCounter] = outvar;
    }
    bestand.close();
    //system("del data.url");
    return outvarArr[0];
}

int main() {
    std::cout << sql("SELECT * FROM test", "innertest");
    system("set /p end=");
    return 0;
}
