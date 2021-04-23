<?php

include 'connection.php';

if(isset($_POST['submit']))
{
		$hname=$_POST['cname'];



$selectquery = "select dh.dno,d.dname,d.address,dh.hosp_no,h.hos_name from doctor d,hospital h,doc_hos dh where h.hos_name='$hname' and d.dno=dh.dno and dh.hosp_no=h.hosp_no;";
$query=mysqli_query($con,$selectquery);



  while($row=mysqli_fetch_assoc($query))
                        {
                                   

                                  echo"Doctor No : ".$row['dno']."<br>"." Doctor Name  : ".$row['dname']."<br>";
                                    echo"Doctor address :  ".$row['address']."<br>";
                                    echo"Hospital NO :  ".$row['hosp_no']."<br>";
                                    echo"Hospital Name:  ".$row['hos_name']."<br>";
                                    echo"--------------------------"."<br>";
                        }


	
}
?>