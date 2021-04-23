<?php

		$host="localhost";
		$user="root";
		$password="";
		$db="students";

		$con=mysqli_connect($host,$user,$password,$db);

		if($con)
		{

		?>
			<script>
				alert(('Connection Successful'))
			</script>	
		
		<?php
		}
		else
		{
		die("no connection".mysqli_connect_error());
		}

	?>