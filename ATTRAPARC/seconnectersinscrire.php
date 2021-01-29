<html lang="Fr">
<?php 
$page="Se Connecter S'inscrire";                                
include "head.php";                                             
include "connex.php";
include "inscrip.php";
if((isset($success) && $success==1 ) || isset($_SESSION['id']) ){ header('Location:index.php'); }

?>

<body id="body" class="up-scroll">

<?php include "menu.php"; ?>
<div class="main-wrapper sign-up-or-login">


  <!-- ====================================
  ———	BREADCRUMB
  ===================================== -->
  <section class="breadcrumb-bg" style="background-image: url(assets/img/background/page-title-bg-img.jpg); ">
    <div class="container">
      <div class="breadcrumb-holder">
        <div>
          <h1 class="breadcrumb-title">Sign Up Or Log In</h1>
          <ul class="breadcrumb breadcrumb-transparent">
            <li class="breadcrumb-item">
              <a class="text-white" href="index.php">Accueil</a>
            </li>
            <li class="breadcrumb-item text-white active" aria-current="page">
              Sign Up Or Log In
            </li>
          </ul>
        </div>
      </div>
    </div>
  </section>

<!-- ====================================
———	SIGN-UP OR LOG-IN
===================================== -->
<section class="py-8 py-md-10">
  <div class="container">
    <div class="row">
      <div class="col-sm-6 offset-lg-2 col-lg-4">
        <div class="mb-4 mb-sm-0">
          <div class="bg-warning rounded-top p-2">
            <h3 class="text-white font-weight-bold mb-0 ml-2">Create An Account</h3>
          </div>
<?php
if(isset($error_msg_insc))
{
	?>
	
	 <div class="alert alert-primary alert-dismissible fade show" role="alert">
                <str<html lang="Fr">
<?php 
$page="Se Connecter S'inscrire";                                
include "head.php";                                             
include "connex.php";
include "inscrip.php";
if((isset($success) && $success==1 ) || isset($_SESSION['id']) ){ header('Location:index.php'); }

?>

<body id="body" class="up-scroll">

<?php include "menu.php"; ?>
<div class="main-wrapper sign-up-or-login">


  <!-- ====================================
  ———	BREADCRUMB
  ===================================== -->
  <section class="breadcrumb-bg" style="background-image: url(assets/img/background/page-title-bg-img.jpg); ">
    <div class="container">
      <div class="breadcrumb-holder">
        <div>
          <h1 class="breadcrumb-title">Sign Up Or Log In</h1>
          <ul class="breadcrumb breadcrumb-transparent">
            <li class="breadcrumb-item">
              <a class="text-white" href="index.php">Accueil</a>
            </li>
            <li class="breadcrumb-item text-white active" aria-current="page">
              Sign Up Or Log In
            </li>
          </ul>
        </div>
      </div>
    </div>
  </section>

<!-- ====================================
———	SIGN-UP OR LOG-IN
===================================== -->
<section class="py-8 py-md-10">
  <div class="container">
    <div class="row">
      <div class="col-sm-6 offset-lg-2 col-lg-4">
        <div class="mb-4 mb-sm-0">
          <div class="bg-warning rounded-top p-2">
            <h3 class="text-white font-weight-bold mb-0 ml-2">Create An Account</h3>
          </div>
<?php
if(isset($error_msg_insc))
{
	?>
	
	 <div class="alert alert-primary alert-dismissible fade show" role="alert">
                <strong>Erreur!</strong> 
               <?php echo $error_msg_insc;?>
                <button type="button" class="persose" data-dismiss="alert" aria-label="persose">
                  <span aria-hidden="true">&times;</span>
      </div>
		 <?php
}
?>

          <div class="border rounded-bottom-sm border-top-0">
            <div class="p-3">
              <form action="" method="POST" role="form">
			   
			   
                <div class="form-group form-group-icon">
                  <input type="text" class="form-control border" name="num_ident" placeholder="Numéro d'identite national" required="">
                </div> 
				
				<div class="row" >
					 <div class="form-group form-group-icon col-6  ">
					  <input type="text" class="form-control border" name="nom_pers" placeholder="Nom" required="">
					</div>

					<div class="form-group form-group-icon col-6  ">
					  <input type="text" class="form-control border" name="prenom_pers" placeholder="Prenom" required="">
					</div>
                </div>
				
                <div class="form-group form-group-icon">
                  <input type="email" class="form-control border" name="adrs_mail_cl" placeholder="Email" required="">
                </div>

                <div class="form-group form-group-icon">
                  <input type="password" class="form-control border" name="password_cl" placeholder="mot de passe" required="">
                </div>
				
				<div class="form-group form-group-icon ">
                  <input type="password" class="form-control border" name="password" placeholder="Re-mot de passe" required="">
                </div>
				
				
                <div class="row" > 
                 
					<div class="form-group form-group-icon col-4  ">
					  <input type="text" class="form-control border" name="age_pers" placeholder="Age" required="">
					</div>
					
					<div class="form-group form-group-icon   col-8">
					  <input type="text" class="form-control border" name="tel_pers" placeholder="Telephone" required="">
					</div> 
					
                 </div>
				 
				<div class="form-group form-group-icon">
                  <input type="text" class="form-control border" name="adresse_pers" placeholder="Adresse" required="">
                </div>
                
				

                <div class="form-group">
                  <button type="submit" name="sinscrire_btn" class="btn btn-danger text-uppercase w-100">S'inscrire</button>
                </div>

               
              </form>
            </div>
          </div>
        </div>
      </div>

      <div class="col-sm-6 col-lg-4">
        <div class="mb-4 mb-sm-0">
          <div class="bg-warning rounded-top p-2">
            <h3 class="text-white font-weight-bold mb-0 ml-2">Login</h3>
          </div>
		  
  
<?php 
			

if(isset($error_msg))
{
	?>
	
	 <div class="alert alert-primary alert-dismissible fade show" role="alert">
                <strong>Erreur!</strong> 
               <?php echo $error_msg; ?>
                <button type="button" class="persose" data-dismiss="alert" aria-label="persose">
                  <span aria-hidden="true">&times;</span>
      </div>
			  
		
		<?php			
}
	

?>
          
     
  
  <div class="border rounded-bottom-sm border-top-0">
            <div class="p-3">
              <form action="" method="POST" role="form">
                <div class="form-group form-group-icon">
                  <input type="email" class="form-control border" name="adrs_mail_cl" placeholder="Email" required="">
                </div>

                <div class="form-group form-group-icon">
                  <input type="password" class="form-control border" name="password_cl" placeholder="mot de passe" required="">
                </div>

                <div class="form-group">
                  <button type="submit" name="seconnecter_btn" class="btn btn-danger text-uppercase w-100">Log In</button>
                </div>

                <div class="form-group text-center text-secondary mb-0">
                  <a class="text-danger" href="#">Forgot mot_de_passe?</a>
                </div>
              </form>
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
	