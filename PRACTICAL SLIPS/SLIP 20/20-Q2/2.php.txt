<?php
echo "style is ".$_GET['s1']."
color is ".$_GET['c']."
Background color is ".$_GET['b']."
size is ".$_GET['s'];
setcookie("set1",$_GET['s1'],time()+3600);
setcookie("set2",$_GET['c'],time()+3600);
setcookie("set3",$_GET['b'],time()+3600);
setcookie("set4",$_GET['s'],time()+3600);
?>
<a href="3.php">Show</a>
