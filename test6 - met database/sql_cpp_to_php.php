<?php
    if (isset($_GET["query"]) && isset($_GET["url"]) && isset($_GET["username"]) && isset($_GET["db"]) && isset($_GET["password"]) && isset($_GET["return"])) {
        $debug = false;
        $query = $_GET["query"];
        $url = $_GET["url"];
        $username = $_GET["username"];
        $password = $_GET["password"];
        $db = $_GET["db"];
        $return = $_GET["return"];
        $conn = new mysqli($url, $username, $password, $db);
        if ($conn->connect_error) {
            die("error_505_cn");
        }
        $outCheck = $conn->query("$query");
        if ($outCheck->num_rows > 0) {
            $counter = 0;
            while ($row = $outCheck->fetch_assoc()) {
                echo $row[$table] . "\n";
            }
        }
        if ($debug == true) {
            echo $query . "<br>";
            echo $url . "<br>";
            echo $username . "<br>";
            echo $password . "<br>";
            echo $db . "<br>";
            print_r($conn);
        }
        $conn->close();
    }
    else {
        if (!isset($_GET["query"])) {
            echo "error_404_query";
        }
        else if (!isset($_GET["url"])) {
            echo "error_404_url";
        }
        else if (!isset($_GET["username"])) {
            echo "error_404_username";
        }
        else if (!isset($_GET["password"])) {
            echo "error_404_password";
        }
        else if (!isset($_GET["db"])) {
            echo "error_404_db";
        }
        else if (!isset($_GET["return"])) {
            echo "error_404_rt";
        }
    }
?>