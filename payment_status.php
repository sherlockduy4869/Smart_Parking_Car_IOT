<?php
    include_once("db.php");
    $sql_select_1 =  mysqli_query($con,'SELECT * FROM tbl_status_checkout WHERE id = 1');


    while($rows = mysqli_fetch_array($sql_select_1)){
            
        $data = ["payment" => $rows["payment"]];
        echo json_encode($data);
    }
?>