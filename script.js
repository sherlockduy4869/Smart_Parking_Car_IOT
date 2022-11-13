$(document).ready(function(){

    setInterval(function(){
        fetch_data();
    },5000);

    function fetch_data(){
        $.ajax({
            url: "ajax_action.php",
            method: "POST",
            success:function(data){
                $('#load_data').html(data);
                //fetch_data();
            }
        });
    }

    //fetch_data();
    
})