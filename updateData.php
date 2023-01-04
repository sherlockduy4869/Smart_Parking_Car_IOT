<?php
$servername = "fdb30.awardspace.net";
$username = "4207329_iotproject";
$password = "7,zOnqB52P!!vJPS";
$dbname = "4207329_iotproject";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

if(!empty($_POST['slot_1'])){
  $status_1 = $_POST['slot_1'];
  $sql_1 = "UPDATE tbl_parking_status SET status = '$status_1' WHERE id = 1";
  $conn->query($sql_1);
}

if(!empty($_POST['slot_2'])){
  $status_2 = $_POST['slot_2'];
  $sql_2 = "UPDATE tbl_parking_status SET status = '$status_2' WHERE id = 2";
  $conn->query($sql_2);
}

if(!empty($_POST['slot_3'])){
  $status_3 = $_POST['slot_3'];
  $sql_3 = "UPDATE tbl_parking_status SET status = '$status_3' WHERE id = 3";
  $conn->query($sql_3);
}

if(!empty($_POST['slot_4'])){
  $status_4 = $_POST['slot_4'];
  $sql_4 = "UPDATE tbl_parking_status SET status = '$status_4' WHERE id = 4";
  $conn->query($sql_4);
}


$conn->close();
?>