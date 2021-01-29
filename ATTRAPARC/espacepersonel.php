<html lang="Fr">
<?php $page="Espace Personel"; include "head.php"; ?>
<body id="body" class="up-scro<html lang="Fr">
<?php $page="Espace Personel"; include "head.php"; ?>
<body id="body" class="up-scroll">
<?php include "menu.php"; 
    
		  
		 if( isset($_GET["er"]) )    {  $error_msg_mdp=$_GET["er"]; }
		 if( isset($_GET["msg"]) )    {  $msg_mdp=$_GET["msg"]; }
		 if( isset($_GET["msg_"]) )    {  $msg_=$_GET["msg_"]; }
		 if( isset($_GET['err']) )    {  $err=$_GET["err"]; }
   
global $Connect;
		$sql = "select *
				  from personne , client
				  where  id_cl=num_ident and
				  num_ident = '".$_SESSION['id']."'" ;
				  
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
			 
			$tel_pers  = $row["tel_pers"]; 
			$adresse_pers = $row["adresse_pers"];
			$age_pers = $row["age_pers"];
			$adrs_mail_cl = $row["adrs_mail_cl"];  
        }
		?>

<div class="main-wrapper product-checkout-step-1">


  <!-- ====================================
  ———	BREADCRUMB
  ===================================== -->
  <section class="breadcrumb-bg" style="background-image: url(assets/img/background/page-title-bg-img.jpg); ">
    <div class="container">
      <div class="breadcrumb-holder">
        <div>
          <h1 class="breadcrumb-title">Checkout Step 1</h1>
          <ul class="breadcrumb breadcrumb-transparent">
            <li class="breadcrumb-item">
              <a class="text-white" href="index-2.html">Home</a>
            </li>
            <li class="breadcrumb-item text-white active" aria-current="page">
              Checkout Step 1
            </li>
          </ul>
        </div>
      </div>
    </div>
  </section>

<!-- ====================================
———	CHECK-OUT SECTION
===================================== -->
<section class="py-7 py-md-10">
  <div class="container">
		 
		<div class="row">
			<div class="col-md-7 col-lg-8 order-1 order-md-0">
        <form class="" action="modifier_info_personnelle.php" method="post">
          <div class="card bg-transparent shadow-none">
						<div class="card-header card-header-lg bg-danger text-white p-6 rounded-top">
              <h4 class="font-weight-bold mb-0">Informations personnelles</h4>
          	</div>

            <div class="card-body border border-top-0 rounded-bottom-sm p-7">
			
 <?php if(isset($err)   )    { ?>
<div class="alert alert-primary alert-dismissible fade show" role="alert">
  <strong>ERREUR!</strong> <?php echo $err; ?> 
  <button type="button" class="close" data-dismiss="alert" aria-label="Close">
    <span aria-hidden="true">&times;</span>
  </button>
</div> 
  <?php 
 }
  if(isset($msg_)   )    { ?>
 <div class="alert alert-success alert-dismissible fade show" role="alert">
  <strong>Changement effectué avec succés!</strong> 
  <button type="button" class="close" data-dismiss="alert" aria-label="Close">
    <span aria-hidden="true">&times;</span>
  </button>
</div> 
  <?php 
 }
?>
           <div class="row">
                 <div class="form-group form-group-icon col-lg-6">
                  <label for="country">Email</label>
                  <input type="email" class="form-control border-purple rounded-sm" name="adrs_mail_cl" value="<?php echo $adrs_mail_cl; ?>" required="">
                </div>
				
				<div class="form-group form-group-icon col-lg-6">
                  <label for="last-name">tel</label>
                  <input type="text" class="form-control border-success rounded-sm" name="tel_pers" value="<?php echo $tel_pers; ?>" required="" >
                </div>
           </div>
			  
            <div class="row">
			    <div class="form-group form-group-icon col-lg-4">
                  <label for="address-2">Age</label>
                  <input type="text" class="form-control border-info rounded-sm" name="age_pers" value="<?php echo $age_pers; ?>" required="">
                </div>
				
				
                <div class="form-group form-group-icon col-lg-8">
                  <label for="address-1">Adresse</label>
                  <input type="text" class="form-control border-danger rounded-sm" name="adresse_pers" value="<?php echo $adresse_pers; ?>" required="">
                </div>

                
              </div> 
			  
               <div class="pull-right mt-4">
            <button type="submit"   class="btn btn-danger text-white text-uppercase" name="btn">Modifier</button>
          </div>
            </div>
          </div>

			
        </form>
			
			<div class="accordion mb-8" id="accordionExample">
                <div class="card bg-transparent shadow-none"> <a   data-toggle="collapse" data-target="#collapseOne" aria-expanded="true"
                        aria-controls="collapseOne">
                  <div class="card-header card-header-lg bg-danger text-white p-6 rounded-top " id="headingOne">
                    <h4 class="font-weight-bold mb-0">
                     
                        modifier mdp
                     
                    </h4>
                  </div>
				   </a>
              <?php   
					  if(isset($error_msg_mdp) )    { ?>
<div class="alert alert-primary alert-dismissible fade show" role="alert">
  <strong>ERREUR!</strong> <?php echo $error_msg_mdp; ?> 
  <button type="button" class="close" data-dismiss="alert" aria-label="Close">
    <span aria-hidden="true">&times;</span>
  </button>
</div> 
  <?php 
 }
   if(isset($msg_mdp) )    {
?> 

 <div class="alert alert-success alert-dismissible fade show" role="alert">
                <strong>Success!</strong> <?php echo $msg_mdp; ?> 
                <button type="button" class="close" data-dismiss="alert" aria-label="Close">
                  <span aria-hidden="true">&times;</span>
                </button>
              </div>
 <?php 
 }
  
?> 
                  <div id="collapseOne" class="collapse show pb-0" aria-labelledby="headingOne" data-parent="#accordionExample">
                    <div class="card-body border border-top-0 rounded-bottom-sm p-7 pb-9 pt-2 "> 
					<form class="" action="modifier_mdp.php" method="post">
					
        
          
                 <div class="form-group form-group-icon col-lg-12 pt-0">
                  <label for="country">Tapez votre ancien mot de passe </label>
                  <input type="password" class="form-control border-purple rounded-sm" name="password_anc"   required="">
                </div>
				
				<div class="form-group form-group-icon col-lg-12">
                  <label for="last-name">Tapez votre nouveau mot de passe</label>
                  <input type="password" class="form-control border-success rounded-sm" name="password_cl"  required="" >
                </div>
           
			   
			    <div class="form-group form-group-icon col-lg-12">
                  <label for="address-2">Confirmez votre mot de passe</label>
                  <input type="password" class="form-control border-info rounded-sm" name="password_nv2"  required="">
                </div>
				
				 <div class="pull-right mt-3">
                   <button type="submit"   class="btn btn-danger text-white text-uppercase" name="btnmdp">Modifier</button>
                </div>
				 </form>
                    </div>
                  </div>
                </div>
               </div>

			
			</div>

			<div class="col-md-5 col-lg-4">
        <div class="card">
          <div class="card-header card-header-lg bg-danger text-white p-6 rounded-top">
            <h4 class="font-weight-medium font-size-24 mb-0">Billets Réservés</h4>
          </div>

			<div class="col-lg-12 col-md-12">
				<div class="pb-4 mb-2">
					 <?php  
    
		 
   
global $Connect;
		$sql__ = "select parc.id_parc, nom_parc, adress_parc 
                       from public.parc, propose2
                        where parc.id_parc=propose2.id_parc and
                         num_bil IN (select num_bil from billet where id_cl='".$_SESSION['id']."' )
						 GROUP BY parc.id_parc
                          
                ";  
				  
		$result = pg_query($Connect, $sql__);
		
        if (!$result) {
          echo "Une erreur s'est produite.\n";
          exit;
        }
         
        while ($row = pg_fetch_row($result)) {
  
			?>
			
			
		
					<div class="border border-top-0 rounded-bottom">
					 
						<div class="media p-3 border-bottom">
							 
							<div class="media-body">
								 <a  data-toggle="collapse" href="#collapseExample<?php echo $row[0] ; ?>" role="button" aria-expanded="false" aria-controls="collapseExample<?php echo $row[0] ; ?>">
					                  <h5 class="text-uppercase text-success mt-0 font-weight-bold">
									  <?php echo $row[1] ; ?> </h5>
					             </a>
								<time class="text-muted font-weight-bold"><?php echo $row[2] ; ?></time>
							</div>
							 <a  data-toggle="collapse" href="#collapseExample<?php echo $row[0] ; ?>" role="button" aria-expanded="false" aria-controls="collapseExample<?php echo $row[0] ; ?>">
							<button type="button" class="icon-rounded-circle-medium ml-3 bg-secondary" data-toggle="tooltip" data-placement="bottom" title="Nombre de billets réservés">
                  
               
				 
							 <?php  
								$sql  = "select COUNT(propose2.num_bil) as nbr
                                        from  propose2 , billet
                                        where  id_parc= '".$row[0]."' and 
										       propose2.num_bil=billet.num_bil and 
											   id_cl= '".$_SESSION['id']."'
										 ";
	
		                       $result_ = pg_query($Connect, $sql); 
                               $numrows = pg_numrows($result_);
        
                               for($i = 0; $i < $numrows; $i++) 
								{
									$row_ = pg_fetch_array($result_, $i);
									echo $row_['nbr'];
						        } 
							?>
							
							 </button>
							</a>
					    </div>
							 <div class="collapse" id="collapseExample<?php echo $row[0] ; ?>">
                                 <div class="card card-body">
                                        <div class="list-group">
										
					 <?php
							
							$sql_  = "select billet.num_bil , date_achat , prix_bil
                                      from billet , propose2
                                      where billet.num_bil=propose2.num_bil and
                                      propose2.id_parc='".$row[0]."' and 
									  id_cl= '".$_SESSION['id']."' 
						              ORDER BY date_achat DESC 
                                     ";  
				  
		                   $result__ = pg_query($Connect, $sql_);
		 
                           while ($row__ = pg_fetch_row($result__))
						    {
                    ?>
                   
				                  <a href="#" class="list-group-item list-group-item-action list-group-item-success">
									   Billet N° <?php echo $row__[0] ; ?>
									   <br>
									   Acheté le <?php echo $row__[1] ; ?>
								   </a>
				  
		               <?PHP } ?>
                   
                </div>
             
                                 </div>
                             </div>
					  

						 

						 
					</div>
				<?php 
		}
		 
        
		?>
				</div>

				 

			 </div>
		
         </div>
			</div>
		</div>
  </div>
</section>

</div> <!-- element wrapper ends -->



<?php include "footer.php"; ?>

</body>

</html>
	