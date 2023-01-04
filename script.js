$(document).ready(function(){

    setInterval(function(){
        fetch_data();
        update_checkout();
    },6000);

    function fetch_data(){
        $.ajax({
            url: "ajax_action.php",
            method: "POST",
            success:function(data){
                console.log(data)
                const myArray = data.split("|");
                $('#slot_1').html(myArray[0]);
                $('#slot_2').html(myArray[1]);
                $('#slot_3').html(myArray[2]);
                //fetch_data();
            }
        });
    }

    function update_checkout(){
        $.ajax({
            url: "refresh_checkout.php",
            method: "POST",
            data: {"payment" : "no"},
            success: function(data){
                console.log(data)
            }
        });
        
    }

    //fetch_data();
    
})