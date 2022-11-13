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

if(!empty($_POST['slot_4'])){
  $status_4 = $_POST['slot_4'];
  $sql = "UPDATE tbl_parking_status SET status = '$status_4' WHERE id = 4";

  if ($conn->query($sql) === TRUE) {
    echo "New record updated successfully";
  } else {
    echo "Error: " . $sql . "<br>" . $conn->error;
  }
}

$conn->close();
?>