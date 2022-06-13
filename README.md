<h1 align="center">42 libft</h1>  

> My Second project at [42 São Paulo](https://www.42sp.org.br/), where i need to write a bufferd file reader. the problem is to read a line of size N 
> into a buffer of size M without memory leak and data loss.

> This project was made according to [Norm](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf)

> In the bonus part we need to work with multiple file descriptors at the same time without losing each other's thread.

<h3 align="center">125/100 &nbsp;&nbsp;:heavy_check_mark:</h3>
<p align="center"> 
  <img align="center" src="https://game.42sp.org.br/static/assets/achievements/get_next_linem.png" />
</p>

## Thoughts
   - this project teach you the importance of map all allocated memory and ensure it will be freed when possible.
   - this project teaches the importance of being a friend of gdb
   - This project in general was easy, but the major struggling here was avoid memory leaks (all funcions are tested with [Valgrind](https://valgrind.org/))  
