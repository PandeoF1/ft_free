<h1 align="center">
	42 - ft_free
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' tnard project at 42 lyon</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/PandeoF1/42-ft_free?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/PandeoF1/42-ft_free?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/PandeoF1/42-ft_free?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/PandeoF1/42-ft_free?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/PandeoF1/42-ft_free?color=brightgreen" />
</p>

---
## Descriptions :
This project is made to perform a clean management of all malloc.<br /><br />
Functions :<br />
```c
  t_m_free	*ft_free_init(void);
    Return malloced struct of t_m_free to store all malloced ptr
  void	*ft_free_malloc(t_m_free *m_free, size_t size);
    Malloc a new ptr and store it in m_free struct (ft_free_add not needed, already done)
  int		ft_free_add(t_m_free *m_free, void *ptr);
    Add inside m_free the malloced ptr
  void		ft_free_remove(t_m_free *m_free, void *ptr);
    Remove inside m_free the ptr malloced and free it
  void		ft_free(t_m_free *m_free);
    Free all maloced ptr and free m_free
  int				ft_free_size(t_m_free *m_free);
    Return the number of malloced ptr
```
If you try to add a variable not malloced / not NULLED it will crash the program.<br />
If you want to use it, be sure the variables is malloced or the variable = NULL<br />
If a NULL variables is gived in ft_free_add(), the program will don't ad it<br /><br />
Example of a crash :<br />
```c
int main(void)
{
  t_m_free  *m_free;
  char      *a;
  char      *b;
 
  m_free = ft_free_init();
  
  a = malloc(sizeof(char));
  ft_free_add(m_free, (void *)a);
  ft_free_add(m_free, (void *)b);
  ft_free(m_free);
}
```
To patch it :<br />
```c
  b = NULL; // Before adding it, or don't add it ;).
```
If a variables is manually freed and inside the free list, that gonna cause a "double free error" if you use ft_free() / ft_free_remove(m_free_ptr, ptr)<br />
The struct m_free returned by ft_free_init() is a malloced struct, so if you don't use ft_free(), he don't gonna be free. If you init him and you don't add any ptr, you can use ft_free or free(m_free)<br />

## Example :
```c
int main(void)
{
  t_m_free  *m_free;
  char      *test;
  char      *test2;
 
  m_free = ft_free_init();
  
  // Now you can malloc a variable.
  test = malloc(sizeof(char));
  test2 = ft_free_malloc(m_free, sizeof(char));
  ft_free_add(m_free, (void *)test);
  // If you want to remove it manually you just need to use :
  ft_free_remove(m_free, (void *)test);
  // Else, if you want to remove all malloced variable :
  ft_free(m_free);
}
```

## Tools :
 > - [norminette](https://github.com/42School/norminette) <br />
 > - [Makefile](https://github.com/PandeoF1/makefile) <br />

## (づ｡◕‿‿◕｡)づ :
```
██╗  ██╗██████╗ ██╗  ██╗   ██╗ ██████╗ ███╗   ██╗   ███████╗██████╗ 
██║  ██║╚════██╗██║  ╚██╗ ██╔╝██╔═══██╗████╗  ██║   ██╔════╝██╔══██╗
███████║ █████╔╝██║   ╚████╔╝ ██║   ██║██╔██╗ ██║   █████╗  ██████╔╝
╚════██║██╔═══╝ ██║    ╚██╔╝  ██║   ██║██║╚██╗██║   ██╔══╝  ██╔══██╗
     ██║███████╗███████╗██║   ╚██████╔╝██║ ╚████║██╗██║     ██║  ██║
     ╚═╝╚══════╝╚══════╝╚═╝    ╚═════╝ ╚═╝  ╚═══╝╚═╝╚═╝     ╚═╝  ╚═╝
```
