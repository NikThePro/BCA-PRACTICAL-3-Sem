<?php

    //Assuming all relations exist in the database
    include 'connection.php';
    
    if(!$con)
    {
        die("An error occured...");
    }
    else
    {

        echo "Successfully connected to the database <br><br>";

        $ch=$_POST['rad'];
        switch($ch)
        {
            case '1':   $actor_name=$_POST['aname'];
                        
                        $selectquery ="select m.movie_name from movie m,actor a,movie_actor mc where a.actor_name='$actor_name' and m.movie_no=mc.movie_no and a.actor_no=mc.actor_no;";

                        $query=mysqli_query($con,$selectquery);



                        while($row=mysqli_fetch_assoc($query))
                        {
                                    echo"Movie name :  ".$row['movie_name']."<br>";
                        }



                        break;
            
            case '2':   
                        $movie_no=$_POST['mno'];
                        $movie_name=$_POST['mname'];
                        $release_year=$_POST['ryear'];
            $insertquery= "insert into movie(movie_no,movie_name,release_year)values($movie_no,'$movie_name','$release_year')";  

            $result= mysqli_query($con,$insertquery);

            if($result)
            {
                ?>
                    <script>
                        alert("data Inserted properly");
                    </script>
                <?php
            }
            else
            {
                ?>
                <script>
                        alert("data Not Inserted ");
                    </script>
                <?php


            } 
                        
                        
            break;

            case '3':   $movie_name=$_POST['mname'];
                        $release_year=$_POST['ryear'];

                        $updatequery="update movie set release_year='$release_year' where movie_name='$movie_name'" ;
                       
                        $result= mysqli_query($con,$updatequery);

            if($result)
            {
                ?>
                    <script>
                        alert("data Updated properly");
                    </script>
                <?php
            }
            else
            {
                ?>
                <script>
                        alert("data Not Updated Inserted ");
                    </script>
                <?php


            } 

                break;
        }


    


    }
?>