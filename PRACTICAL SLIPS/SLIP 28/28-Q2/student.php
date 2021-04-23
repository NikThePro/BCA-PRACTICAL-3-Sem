<?php

include 'connection.php';

if(isset($_POST['submit']))
{
		$cname=$_POST['cname'];


$selectquery = "select st.sno,s.sname,st.subject,t.tno,t.tname from student1 s,teacher t,stud_teach st where tname='$cname' and s.sno=st.sno and t.tno=st.tno;";

$query=mysqli_query($con,$selectquery);



  while($row=mysqli_fetch_assoc($query))
                        {
                                    echo"Stud No : ".$row['sno']."<br>"."  Name  : ".$row['sname']."<br>";
                                    echo"Subject :  ".$row['subject']."<br>";
                                    echo"Teacher No :  ".$row['tno']."<br>";
                                    echo"Teacher name :  ".$row['tname']."<br>";
                                    echo"--------------------------"."<br>";
                        }


	
}
?>