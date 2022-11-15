<?php
    include_once("db.php");


    //Get data
    $outPut = '';


    $sql_select_1 =  mysqli_query($con,'SELECT * FROM tbl_parking_status WHERE id = 1');
    $sql_select_2 =  mysqli_query($con,'SELECT * FROM tbl_parking_status WHERE id = 2');
    $sql_select_3 =  mysqli_query($con,'SELECT * FROM tbl_parking_status WHERE id = 3');
    $sql_select_4 =  mysqli_query($con,'SELECT * FROM tbl_parking_status WHERE id = 4');

    if(mysqli_num_rows($sql_select_1)>0){

        while($rows = mysqli_fetch_array($sql_select_1)){
            
            if($rows['status']== "not"){
                $outPut .= '<img src="./Resource/img/black_car.png">';
                $outPut .= "|";
            }
            else{
                $outPut .= '<h2 class = "available">1</h2>';
                $outPut .= "|";
            }
        }
    }

    if(mysqli_num_rows($sql_select_2)>0){

        while($rows = mysqli_fetch_array($sql_select_2)){
            
            if($rows['status']== "not"){
                $outPut .= '<img src="./Resource/img/white_car.jpeg">';
                $outPut .= "|";
            }
            else{
                $outPut .= '<h2 class = "available">2</h2>';
                $outPut .= "|";
            }
        }
    }

    if(mysqli_num_rows($sql_select_3)>0){

        while($rows = mysqli_fetch_array($sql_select_3)){
            
            if($rows['status']== "not"){
                $outPut .= '<img src="./Resource/img/blue_car.jpeg">';
                $outPut .= "|";
            }
            else{
                $outPut .= '<h2 class = "available">3</h2>';
                $outPut .= "|";
            }
        }
    }

    if(mysqli_num_rows($sql_select_4)>0){

        while($rows = mysqli_fetch_array($sql_select_4)){
            
            if($rows['status']== "not"){
                $outPut .= '<img src="./Resource/img/blue_car.jpeg">';
            }
            else{
                $outPut .= '<h2 class = "available">4</h2>';
            }
        }
    }

    echo $outPut;

    
?>