#include <iostream>
#include <fstream>
#include <regex> //voor replace command. (Erg langzaam met bouwen)

std::string sql(std::string query, std::string sqlreturn = "leeg__", int x = 0) {//SQL Functie.
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
    if (sqlreturn != "leeg__") {
        std::string outvar = "";
        int sqlCounter = 0;
        std::ifstream bestand("data.url");
        while (getline(bestand, outvar)) {
        ++sqlCounter;
        }
        bestand.close();
        outvar = "";
        std::string sqlReturnArr[sqlCounter];
        sqlReturnArr[0] = sqlCounter;
        sqlCounter = 0;
        std::ifstream bestand2("data.url");
        while (getline(bestand2, outvar)) {
        sqlReturnArr[sqlCounter] = outvar;
        ++sqlCounter;
        }
        bestand2.close();
        std::string* rwebjewbbre = sqlReturnArr;
        rwebjewbbre += x;
        if ((x + 1) > sqlCounter || x < 0) {
            *rwebjewbbre = "error_index_scope";
        }
        system("del data.url");
        return *rwebjewbbre;
    }
    system("del data.url");
    return "";
}

int main() {
    /* Example:
        std::cout << sql("SELECT * FROM test", "innertest", 0);

        Result:
            Test

        Working:

        sql(1, 2 , 3);

        1: Sql query command (string).

        2: if you want an return value. Type your tablename here.

        3: row of table for display.
    */
    std::cout << sql("SELECT * FROM test", "innertest", 0);
    return 0;
}
