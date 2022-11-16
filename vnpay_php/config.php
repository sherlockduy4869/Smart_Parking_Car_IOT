<?php
date_default_timezone_set('Asia/Ho_Chi_Minh');
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
  
$vnp_TmnCode = "SG6Z7UTP"; //Website ID in VNPAY System
$vnp_HashSecret = "AVTOZLPTDXRXTSZRIVEVPQGBYTNTLHTC"; //Secret key
$vnp_Url = "https://sandbox.vnpayment.vn/paymentv2/vpcpay.html";
//$vnp_Returnurl = "http://localhost/vnpay_php/vnpay_return.php";
$vnp_Returnurl = "http://iotprojectvnuk.atwebpages.com/resultPayment.php";
$vnp_apiUrl = "http://sandbox.vnpayment.vn/merchant_webapi/merchant.html";
//Config input format
//Expire
$startTime = date("YmdHis");
$expire = date('YmdHis',strtotime('+15 minutes',strtotime($startTime)));

// http://iotprojectvnuk.atwebpages.com/?vnp_Amount=1000000&vnp_BankCode=NCB&vnp_BankTranNo=VNP13879379&vnp_CardType=ATM&vnp_OrderInfo=Noi+dung+thanh+toan&vnp_PayDate=20221116131637&vnp_ResponseCode=00&vnp_TmnCode=SG6Z7UTP&vnp_TransactionNo=13879379&vnp_TransactionStatus=00&vnp_TxnRef=20221116131550&vnp_SecureHash=06b539ef531b2129c4b0b81e0b3b4b7f8731f3ec71ee30714d32b651763ce7d536b4cea31a2b87dbec31c92c812ce31353d1da8da57821ec5a251ab3e9e99c49
