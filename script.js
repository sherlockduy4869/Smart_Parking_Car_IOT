$(document).ready(function(){

    setInterval(function(){
        fetch_data();
    },5000);

    function fetch_data(){
        $.ajax({
            url: "ajax_action.php",
            method: "POST",
            success:function(data){
                const myArray = data.split("|");
                $('#slot_1').html(myArray[0]);
                $('#slot_2').html(myArray[1]);
                $('#slot_3').html(myArray[2]);
                $('#slot_4').html(myArray[3]);
                //fetch_data();
            }
        });
    }

    //fetch_data();
    
})