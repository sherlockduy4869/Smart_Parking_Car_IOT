<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Payment Status</title>
    <link rel="stylesheet" href="./Resource/css/styleResult.css?v=<?php echo time(); ?>">
</head>
<body>
    <section>
        <?php
            if(isset($_GET['vnp_Amount'])){
                echo '<h1>PAYMEN SUCCESSFUL</h1>';

                $data = ["payment" => "yes"];
                echo json_encode($data);
            }
        ?>
    </section>
</body>
</html>