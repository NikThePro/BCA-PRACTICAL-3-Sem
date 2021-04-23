<?php

include 'connection.php';

if(isset($_POST['submit']))
{
		$cname=$_POST['cname'];


$selectquery = "select s.stud_id,s.name,s.class from student s,competiton c,stud_comp sc where c.cname='$cname' and sc.rank=1 and sc.stud_id=s.stud_id and c.c_no=sc.c_no";

$query=mysqli_query($con,$selectquery);



  while($row=mysqli_fetch_assoc($query))
                        {
                                    echo"Stud No : ".$row['stud_id']."<br>"."  Name  : ".$row['name']."<br>";
                                    echo"Class :  ".$row['class']."<br>";
                                    echo"--------------------------"."<br>";
                        }


	
}
?>