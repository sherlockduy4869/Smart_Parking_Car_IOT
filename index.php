<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PARKING</title>

    <!--Boostrap-->

    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.1.3/dist/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
    <link rel="stylesheet" href="./Resource/css/style.css?v=<?php echo time(); ?>">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.min.js" integrity="sha384-cVKIPhGWiC2Al4u+LWgxfKTRIcfu0JTxR+EQDz/bgldoEyl4H0zUF0QKbrJ0EcQF" crossorigin="anonymous"></script>

    <!-- JS file -->
    <script src="https://code.jquery.com/jquery-3.6.0.min.js" integrity="sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4=" crossorigin="anonymous"></script>
    <script src="script.js?v=<?php echo time(); ?>"></script>

    <!--DataTables With Print Function-->
    <link rel="stylesheet" href="https://cdn.datatables.net/1.12.1/css/jquery.dataTables.min.css">
    <link rel="stylesheet" href="//cdn.datatables.net/1.12.1/css/jquery.dataTables.min.css">
    <link rel="stylesheet" href="//cdn.datatables.net/buttons/2.2.3/css/buttons.dataTables.min.css">

    <script src="//cdn.datatables.net/1.12.1/js/jquery.dataTables.min.js"></script>

    <script src="//cdn.datatables.net/buttons/2.2.3/js/dataTables.buttons.min.js"></script>
    <script src="//cdnjs.cloudflare.com/ajax/libs/jszip/3.1.3/jszip.min.js"></script>
    <script src="//cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.53/pdfmake.min.js"></script>
    <script src="//cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.53/vfs_fonts.js"></script>
    <script src="//cdn.datatables.net/buttons/2.2.3/js/buttons.html5.min.js"></script>
    <script src="//cdn.datatables.net/buttons/2.2.3/js/buttons.print.min.js"></script>

</head>

<body>
    <div class="heading">
        <h2 class="text-center title">WELCOME TO SMART PARKING CAR</h2>
        <a href="./vnpay_php/index.php" class="btn btn-primary">CHECKOUT</a>
    </div>

    <div class="parking_top">
        <div class="parking_top_item">

        </div>
        <div id="slot_1" class="parking_top_item slot_1">
            <h1>1</h1>
        </div>
        <div id="slot_2" class="parking_top_item slot_2">
            <h1>2</h1>
        </div>
        <div id="slot_3" class="parking_top_item slot_3">
            <h1>3</h1>
        </div>
        <div class="parking_top_item">

        </div>
    </div>

    <div class="parking_middle">
        <div class="parking_middle_item">
            <h1>ENTRY</h1>
        </div>
        <div class="parking_middle_item">
            <div class="square"></div>
            <div class="arrow-right"></div>
        </div>
        <div class="parking_middle_item">
        </div>
        <div class="parking_middle_item">
            <div class="square"></div>
            <div class="arrow-right"></div>
        </div>
        <div class="parking_middle_item">
            <h1>EXIT</h1>
        </div>
    </div>

    <div class="parking_bottom">
        <div class="parking_bottom_item">

        </div>
        <div class="parking_bottom_item">
            <img src="./Resource/img/blacking_car.png" alt="">
        </div>
        <div class="parking_bottom_item">
            <img src="./Resource/img/blacking_car.png" alt="">
        </div>
        <div class="parking_bottom_item">
            <img src="./Resource/img/white_car.png" alt="">
        </div>
        <div class="parking_bottom_item">

        </div>
    </div>

    <?php
    $servername = "fdb30.awardspace.net";
    $username = "4207329_iotproject";
    $password = "7,zOnqB52P!!vJPS";
    $dbname = "4207329_iotproject";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if (!empty($_GET["vnp_Amount"])) {
        $payment = "yes";
        $sql = "UPDATE tbl_status_checkout SET payment = '$payment' WHERE id = 1";
        $conn->query($sql);

        echo '<script> alert("Payment successfully !");</script>';
    }
    ?>

    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.9.2/dist/umd/popper.min.js" integrity="sha384-IQsoLXl5PILFhosVNubq5LC7Qb9DXgDA9i+tQ8Zj3iwWAwPtgFTxbJ8NT4GN1R8p" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.min.js" integrity="sha384-cVKIPhGWiC2Al4u+LWgxfKTRIcfu0JTxR+EQDz/bgldoEyl4H0zUF0QKbrJ0EcQF" crossorigin="anonymous"></script>
    <script src="./Vendors/js/jquery.waypoints.min.js"></script>

</body>

</html>