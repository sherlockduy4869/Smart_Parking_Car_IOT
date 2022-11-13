<?php
    include_once("db.php");


    //Get data
    $outPut = '';
    $sql_select =  mysqli_query($con,'SELECT * FROM tbl_parking_status WHERE id = 4');

    if(mysqli_num_rows($sql_select)>0){

        while($rows = mysqli_fetch_array($sql_select)){
            
            if($rows['status']== "not"){
                $style = 'red';
                $outPut .= '<div style="color:'.$style.' ;">' .$rows['status']. '</div>';
            }
            else{
                $outPut .= '<div>'.$rows['status'].'</div>';
            }
        }
    }

    echo $outPut;
?>