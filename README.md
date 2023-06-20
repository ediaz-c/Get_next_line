<h1>Get_next_line</h1>
<p>El proyecto <strong>get_next_line</strong> es una función diseñada para leer de manera eficiente el contenido de un archivo o la entrada estandar (stdin) línea por línea.
Llamar repetidamente a esta función, leeria todo el contenido de un archivo referenciado por el descriptor</p>
<br>
<h2>Prototipo</h2>
<pre><code>char  *get_next_line(int fd)</code></pre>
<br>
<h2>Funcionalidad</h2>
<ul>La función <strong>get_next_line</strong> debe devolver la línea recién leída</ul>
<ul>Si no hay más contenido que leer o si ocurre algún error, la función debe devolver NULL</ul>
<ul>La función debe funcionar leyendo de un archivo o del stdin</ul>
<ul>El <strong>mandatory</strong> debe de leer de un solo archivo</ul>
<ul>El <strong>bonus</strong> debe gestionar varios descriptores de archivos a la vez</ul>

