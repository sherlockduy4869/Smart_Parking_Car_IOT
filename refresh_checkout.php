<?php
$servername = "fdb30.awardspace.net";
$username = "4207329_iotproject";
$password = "7,zOnqB52P!!vJPS";
$dbname = "4207329_iotproject";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

if (!empty($_POST['payment'])) {
  $payment = $_POST['payment'];
  $sql = "UPDATE tbl_status_checkout SET payment = '$payment' WHERE id = 1";
  $conn->query($sql);
}


$conn->close();

