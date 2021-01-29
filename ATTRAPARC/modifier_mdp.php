
 <?php
	 
	
  session_start();
   include "config.php"; 
		  if( 
			isset($_POST['password_anc']) && $_POST['password_anc']!="" && 
			isset($_POST['password_cl']) && $_POST['password_cl']!=""  &&       
			isset($_POST['password_nv2']) && $_POST['password_nv2']!=""         
			 )
		 {
			  
			 global $Connect;
			 if (strcmp($_POST['password_cl'], $_POST['password_nv2']) == 0) //Mot de passe = Mot de passe répété 
			{
				$mdp=1;
			}else{
				$mdp=0;
			}
				 $ancien_password =  pg_escape_string( $_POST['password_anc'])  ;
				 $password_utilisateurs =  pg_escape_string($_POST['password_cl'])  ;
				 $password_confirm =  pg_escape_string($_POST['password_nv2'])  ;
				 
                    $existe=0;
				 $req_total = "  SELECT *	
						         FROM   client
						         WHERE id_cl = '".$_SESSION["id"]."' and
						               password_cl='".$ancien_password."'";
				 $result = pg_query($Connect, $req_total);
			     
				
			       $row = pg_fetch_row($result);
			       if( $row>0 && $mdp==1) 
			       {  
			   
						 $existe=1; 
						 $sql = "UPDATE  client  SET 
								password_cl='".$password_utilisateurs."' 			
								WHERE id_cl='".$_SESSION["id"]."'";
								
						 $result_ =pg_query($Connect, $sql);
						 
				
			 
 <?php
	 
	
  session_start();
   include "config.php"; 
		  if( 
			isset($_POST['password_anc']) && $_POST['password_anc']!="" && 
			isset($_POST['password_cl']) && $_POST['password_cl']!=""  &&       
			isset($_POST['password_nv2']) && $_POST['password_nv2']!=""         
			 )
		 {
			  
			 global $Connect;
			 if (strcmp($_POST['password_cl'], $_POST['password_nv2']) == 0) //Mot de passe = Mot de passe répété 
			{
				$mdp=1;
			}else{
				$mdp=0;
			}
				 $ancien_password =  pg_escape_string( $_POST['password_anc'])  ;
				 $password_utilisateurs =  pg_escape_string($_POST['password_cl'])  ;
				 $password_confirm =  pg_escape_string($_POST['password_nv2'])  ;
				 
                    $existe=0;
				 $req_total = "  SELECT *	
						         FROM   client
						         WHERE id_cl = '".$_SESSION["id"]."' and
						               password_cl='".$ancien_password."'";
				 $result = pg_query($Connect, $req_total);
			     
				
			       $row = pg_fetch_row($result);
			       if( $row>0 && $mdp==1) 
			       {  
			   
						 $existe=1; 
						 $sql = "UPDATE  client  SET 
								password_cl='".$password_utilisateurs."' 			
								WHERE id_cl='".$_SESSION["id"]."'";
								
						 $result_ =pg_query($Connect, $sql);
						 
				
			        $msg_mdp='Votre mot de passe a bien été changé ';
						 
						 header('Location:  espacepersonel.php?msg='.$msg_mdp) ;
				   }else  {
							$error_msg_mdp="ancien mot de passe incorrecte  ";
							 header('Location:  espacepersonel.php?er='.$error_msg_mdp) ;
						}
					
						 
				}
		        else{					
					$error_msg_mdp="Vérifier Votre formulaire"; header('Location:  espacepersonel.php?er='.$error_msg_mdp) ;
				}
								?>	