<?
 
  $mySQLUserID = "root";
   $mySQLDB = "mony";
   $mySQLUserPassword = "";
  // $appURL = "index.php";
   $mySQL_Link = 0;
		
   function SQLConnect()
   {
      global $mySQLServerIP, $mySQLUserID, $mySQLUserPassword, $mySQLDB;
      $mySQL_Link = mysql_connect($mySQLServerIP, $mySQLUserID, $mySQLUserPassword);
      if ($mySQL_Link){
         mysql_select_db($mySQLDB);
         $sqlString = "SET character_set_results='utf8'";
         mysql_query($sqlString);
         $sqlString = "SET character_set_client='utf8'";
         mysql_query($sqlString);
         $sqlString = "SET character_set_results='utf8'";
         mysql_query($sqlString);
         $sqlString = "SET character_set_connection='utf8'";
         mysql_query($sqlString);
      }
      return $mySQL_Link;
   }

   function SQLClose()
   {
      if (isset($mySQL_Link)){
         mysql_close($mySQL_Link);
      }
   }

   function getValue($tableName, $fieldName, $fieldValue, $fieldReturn)
   {
      $sqlString = "SELECT " . $fieldReturn . " from " . $tableName . " where " . $fieldName . " = '" . $fieldValue . "';";
      $result = mysql_query($sqlString);
      if ($result)
      {
         $row = mysql_fetch_array($result, MYSQL_BOTH);
         $return = $row[$fieldReturn];
         return $return;
      }
   }

   function check_authentication($userName, $userPassword)
   {
      $sqlString = "SELECT id_user, userName, userPassword from m_user ";
      $sqlString .= "where userName = '" . $userName . "' and userPassword = '" . md5($userPassword) ."' and status=1;"; 
      $result = mysql_query($sqlString);
      if ($result) {
         if ($row = mysql_fetch_array($result, MYSQL_ASSOC)) {
/*            $place_type = $row["place_type"];
            $place_id = $row["place_id"];*/
            $return_value = 1;
         }else{
            $return_value = -1;
         }
         mysql_free_result($result);
      }else{
         $return_value = 0;
      }
      return $return_value;
   }
   
   function addLogLogin($id_user)
   {
      $sqlString = "INSERT into log_login (id_user,login_datetime) values (" . $id_user . ", now());";
      $result = mysql_query($sqlString);
   }
   
	// ททดสอบ github เพิ่มโค้ทโปรแก
	อบ github
	อบ github
	อบ githubรม
	อบ github



   ?>