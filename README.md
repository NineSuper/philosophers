<h1>📚 Philosophes 🍽️</h1>

<h2>Description</h2>

<p>Ce projet vise à résoudre le problème des philosophes dîneurs en utilisant des threads et des primitives de synchronisation en langage C.</p>

<p>Le problème des philosophes dîneurs est un problème classique de synchronisation qui implique un certain nombre de philosophes assis à une table et un nombre limité de baguettes (ou fourchettes) entre eux. Chaque philosophe doit tour à tour penser et manger. Cependant, un philosophe ne peut manger que s'il a à sa disposition les baguettes à sa gauche et à sa droite.</p>

<h2>Fonctionnalités</h2>

<ul>
  <li>Implémentation du problème des philosophes dîneurs.</li>
  <li>Solution utilisant des threads et des primitives de synchronisation telles que les verrous mutex et les sémaphores.</li>
  <li>Options pour ajuster les paramètres tels que le nombre de philosophes, le temps de simulation, et les temps de manger/penser.</li>
</ul>

<h2>Utilisation</h2>

<ol>
  <li>Cloner le dépôt :</li>
  <pre><code>git clone https://github.com/votreutilisateur/philosophes.git</code></pre>
  <li>Naviguer jusqu'au répertoire du projet :</li>
  <pre><code>cd philosophes</code></pre>
  <li>Compiler le programme :</li>
  <pre><code>make</code></pre>
  <li>Exécuter le programme avec les options souhaitées :</li>
  <pre><code>./philo [nombre_de_philosophes] [temps_pour_mourir] [temps_pour_manger] [temps_pour_dormir] [optionnel: nombre_de_fois_ou_chaque_philosophe_doit_manger]</code></pre>
  <p>Exemple :</p>
  <pre><code>./philo 5 800 200 200</code></pre>
  <li>Pour nettoyer les fichiers objets et l'exécutable :</li>
  <pre><code>make clean</code></pre>
</ol>

📝 Auteur

- 🎫 [@NineSuper](https://www.github.com/NineSuper)
