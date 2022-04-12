<h1 align="center">
 	ft_free
</h1>

<p align="center">
	<b><i>Development repo for tnard project</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/PandeoF1/42-ft_free?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/PandeoF1/ft_free?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/PandeoF1/ft_free?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/PandeoF1/ft_free?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/PandeoF1/ft_free?color=brightgreen" />
</p>

---
## Descriptions :
This project is made to perform a clean management of all malloc.<br /><br />
Functions :<br />
```c
  t_m_free	*ft_free_init(void);
  	Return malloced struct of t_m_free to store all malloced ptr
  void		*ft_free_malloc(t_m_free *m_free, size_t size);
  	Malloc a new ptr and store it in m_free struct (ft_free_add not needed, already done)
  int		ft_free_add(t_m_free *m_free, void *ptr);
  	Add inside m_free the malloced ptr
  void		ft_free_remove(t_m_free *m_free, void *ptr);
  	Remove inside m_free the ptr malloced and free it
  void		ft_free(t_m_free *m_free);
  	Free all maloced ptr and free m_free
  int		ft_free_size(t_m_free *m_free);
  	Return the number of malloced ptr
```
If you try to add two (or much) time a ptr to ft_free_add(), that gonna do nothing (The program cancel the action if found in the list)<br />
If you try to free a function with ft_free_remove two times (or more) that gonna do nothing. <br />
But if you free it with free() that can crash if after you use ft_free_remove() / ft_free() - To patch that :
- Set the PTR to NULL (Or don't use free()..).

If you try to add a variable not malloced / not NULLED it will crash the program.<br />
If you want to use it, be sure the variables is malloced or the variable = NULL<br />
If a NULL variables is gived in ft_free_add(), the program will don't add it<br /><br />
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
If a variables is manually freed and is inside the free list, that gonna cause a "double free error" if you use ft_free() / ft_free_remove(m_free_ptr, ptr)<br />
The struct m_free returned by ft_free_init() is a malloced struct, so if you don't use ft_free(), he don't gonna be free. If you init him and you don't add any ptr, you can use ft_free or free(m_free)<br />

## Example (Global Usage):
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
  // Else, if you want to remove all malloced variable (also needed to destroy *m_free):
  ft_free(m_free);
}
```
## Example (Performance Test (5000 malloc)):
```c
int	main(void)
{
	t_m_free	*m_free;
	char		*a;
	int			*b;
	char		**c;
	char		*d;
	int			x;

	d = NULL;
	x = 0;
	m_free = ft_free_init();
	while (x < 1000)
	{
		a = malloc(sizeof(char) * 100);
		ft_free_add(m_free, a);
		b = malloc(sizeof(int) * 100);
		ft_free_add(m_free, b);
		c = malloc(sizeof(char *) * 2);
		c[0] = malloc(sizeof(char) * 100);
		c[1] = malloc(sizeof(char) * 100);
		ft_free_add(m_free, d); // Exemple of null pointer
		ft_free_add(m_free, c[1]);
		ft_free_add(m_free, c);
		ft_free_add(m_free, c[0]);
		x++;
	}
	printf("%d\n", ft_free_size(m_free));
	ft_free(m_free);
	return (0);
}
```
## Example (Own malloc function):
```c
int	main(void)
{
	t_m_free	*m_free;
	char		*test;

	m_free = ft_free_init();
	test = ft_free_malloc(m_free, sizeof(char) * 100);
	test[0] = 'a';
	test[1] = 'b';
	test[2] = 'c';
	test[3] = '\0';
	printf("%s\n", test);
	ft_free(m_free);
	return (0);
}
```
## Example (Count malloced ptr):
```c
int	main(void)
{
	t_m_free	*m_free;
	char		*test;

	m_free = ft_free_init();
	printf("%d\n", ft_free_size(m_free));
	test = ft_free_malloc(m_free, sizeof(char));
	printf("%d\n", ft_free_size(m_free));
	ft_free(m_free);
	return (0);
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
