Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Escriba un programa que se llame union, que reciba como parámetro dos cadenas de
de caracteres y muestre, sin duplicados, los caracteres que aparecen en
la una o en la otra.

Se mostrarán en el orden de aparición dentro de la línea de comandos.

La visualización irá seguida de un salto de línea.

Si el número de parámetros transmitidos es distinto de 2, el programa mostrará
\n.

Ejemplo:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>

