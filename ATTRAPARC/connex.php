<?php 
			
if(isset($_POST['seconnecter_btn'])) 
{
	if(isset($_POST['adrs_mail_cl']) && $_POST['adrs_mail_cl']!="" &&
  	   isset($_POST['password_cl']) && $_POST['password_cl']!=""
	  )
	{	
		$adrs_mail_cl=pg_escape_string(htmlspecialchars($_POST['adrs_m<?php 
			
if(isset($_POST['seconnecter_btn'])) 
{
	if(isset($_POST['adrs_mail_cl']) && $_POST['adrs_mail_cl']!="" &&
  	   isset($_POST['password_cl']) && $_POST['password_cl']!=""
	  )
	{	
		$adrs_mail_cl=pg_escape_string(htmlspecialchars($_POST['adrs_mail_cl']));
		$password_cl= htmlspecialchars($_POST['password_cl']) ; 

		global $Connect;
		$sql = "select num_ident, nom_pers, prenom_pers 
				  from personne , client
				  where 
				  adrs_mail_cl = '".$adrs_mail_cl."' and 
				  password_cl='".$password_cl."' and num_ident = id_cl";
				  
		$result = pg_query($Connect, $sql);
		
        if (!$result) {
          echo "Une erreur s'est produite.\n";
          exit;
        }
        $numrows = pg_numrows($result);
        
        for($i = 0; $i < $numrows; $i++) 
		{
			$row = pg_fetch_array($result, $i);
		}
		
        if($numrows>0) 
		{
			$_SESSION['nom'] = $row["nom_pers"];
			$_SESSION['prenom'] = $row["prenom_pers"];
			$_SESSION['id'] = $row["num_ident"];
			
			$success=1;
        }else{
             $error_msg="Identifiant ou mot de passe incorrect.";
	    }
				
	}else{
             $error_msg="Il faut remplir tous les champs.";
	}			 

}
	?>