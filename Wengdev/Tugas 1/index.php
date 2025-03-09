<?php
    $name = "BILLY_RAMADHANI";
    $about = "Hi there! I am an ambitious and dedicated second-year computer science undergraduate student at UPN Veteran Jawa Timur. My drive to expand my knowledge and skills is unwavering, fueled by a strong passion for growth and learning. I have developed intermediate expertise in Network Engineering and Cloud Computing, as reflected in my experiences. I am eager to leverage these skills to contribute effectively in a professional setting and continue my journey of professional development";
    $experiences = array("Top 10 Finalist, LKS Cloud Computing Jatim", "IT Support Intern, Universitas Sunan Bonang", "Mentor LKS CySec Jatim 2025, SMKN 1 Tuban");
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://fonts.googleapis.com/css2?family=Lexend+Mega:wght@100..900&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="style.css">
    <title>Hello!</title>
</head>
<body>
    <nav>
        <ul>
            <li><a href="#">Home</a></li>
            <li><a href="#first">About</a></li>
            <li><a href="#second">Experiences</a></li>
            <li><a href="#third">Contact</a></li>
        </ul>
    </nav>

<div class="home">
    <h1><?php echo $name ?></h1>
    <img src="img/profil.jpeg" alt="">
    <p>CS Student | CySec Enthusiast | CC Enthusiast</p>
</div>

<hr>

<section id="first">
    <h2 class="h2first">About Me.</h2>
    <div class="container" id="about">
        <div class="column">
            <p><?php echo $about ?></p>
        </div>
    </div>
</section>

<hr>

<section id="second">
    <h2 class="h2second" id="experience">Experiences.\</h2>
    <div class="container">
        <div class="column">
            <b><?php echo $experiences[0] ?></b><br>
            <a href=""><img src="img/mentoring.jpg" alt="Gambar 1"></a>
        </div>
        <div class="column">
            <b><?php echo $experiences[1] ?></b>
            <a href=""><img src="img/mentoring.jpg" alt="Gambar 2"></a>
        </div>
        <div class="column">
            <b><?php echo $experiences[2] ?></b>
            <a href=""><img src="img/mentoring.jpg" alt="Gambar 2"></a>
        </div>
    </div>
</section>

<hr>
<section id="third">
    <h2 class="h2third" id="contact">./Contacts</h2>
    <div class="container" id="contact">
        <div class="column">
            <a target="_blank" href="https://github.com/brobilly"><img src="img/github.png" alt=""></a>
        </div>
        <div class="column">
            <a target="_blank" href=""><img src="img/linkedin.png" alt=""></a>
        </div>
    </div>
    <div class="container" id="contact">
        <div class="column">
        </div>
        <div class="column">
            <a target="_blank" href="https://discord.com/users/298808961136721930"><img src="img/discord.png" alt=""></a>
        </div>
        <div class="column">
        </div>
        <div class="column">
            <a target="_blank" href="https://instagram.com/bllyr_/"><img src="img/instagram.png" alt=""></a>
        </div>
    </div>
</section>

<footer>
    <p>&copy; 2025 Billy Ramadhani. All rights reserved.</p>
</footer>

</body>
</html>