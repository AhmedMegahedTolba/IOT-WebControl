<?php

$file="write.txt";
        
if(isset($_GET['status'])) 
{   
     if($_GET['status']=="image")
      {
             
         $handle=fopen($file,'w');
         fwrite($handle,'0');
         fclose($handle);    
             
             
       }
      elseif($_GET['status']=="video")  
       {
             
         $handle=fopen($file,'w');
         fwrite($handle,'1');
         fclose($handle);    
             
             
       }
      elseif($_GET['status']=="audio")  
       {
             
         $handle=fopen($file,'w');
         fwrite($handle,'2');
         fclose($handle);    
             
             
       } 
        
      header("location:index.html");  
        
        
}        