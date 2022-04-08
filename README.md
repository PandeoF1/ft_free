<h1 align="center">
	42 - ft_free
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' tnard project at 42 lyon</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/PandeoF1/42-cub3d?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/PandeoF1/42-cub3d?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/PandeoF1/42-cub3d?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/PandeoF1/42-cub3d?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/PandeoF1/42-cub3d?color=brightgreen" />
</p>

---
## Descriptions :
This project is made to perform a clean management of all malloc.<br /><br />
Functions :<br />
```c
  t_m_free	*ft_free_init(void);
    Return malloced struct of t_m_free to store all malloced ptr
  int		ft_free_add(t_m_free *m_free, void *ptr);
    Add inside m_free the ptr of the malloced ptr
  void		ft_free_remove(t_m_free *m_free, void *ptr);
    Remove inside m_free and free the ptr malloced
  void		ft_free(t_m_free *m_free);
    Free all maloced ptr and free m_free
 ```

## Example :
```c
int main(void)
{
  t_m_free  *m_free;
  char      *test;
 
  m_free = ft_free_init();
  
  // Now you can malloc a variable.
  test = malloc(sizeof(char));
  ft_free_add(m_free, (void *)test);
  // If you want to remove it manually you just need to use :
  // ft_free_remove(m_free, (void *)test);
  // Else, if you want to remove all malloced variable :
  // ft_free(m_free);
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
