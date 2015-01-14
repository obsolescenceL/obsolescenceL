set nu
syn on
filetype on
set cin
set shiftwidth=2
set expandtab
set mouse=a
set cursorline
set ruler
set showcmd
set background=dark
set lbr "不在单词中间断行
"禁止生成临时文件
set nobackup
set noswapfile
autocmd BufNewFile *.cpp exec ":call SetTitle()"
func SetTitle()
  if &filetype == 'cpp'
    call setline(1, "/*************************************************************************")   
    call append(line("."), "    > File Name: ".expand("%"))   
    call append(line(".")+1, "    > Author: obsolescence")   
    call append(line(".")+2, "    > Mail: 384099319@qq.com ")   
    call append(line(".")+3, "    > Created Time: ".strftime("%c"))   
    call append(line(".")+4, " ************************************************************************/")   
    call append(line(".")+5, "#include<cstdio>")  
    call append(line(".")+6, "#include<iostream>")  
    call append(line(".")+7, "#include<cstring>")  
    call append(line(".")+8, "#include<queue>")  
    call append(line(".")+9, "#include<string>")  
    call append(line(".")+10, "#include<cmath>")  
    call append(line(".")+11, "#include<map>")  
    call append(line(".")+12, "#define FORIN(a,b) for(int i=a;i<b;i++)")  
    call append(line(".")+13, "#define FORDE(a,b) for(int i=a;i>b;i--)")  
    call append(line(".")+14, "using namespace std;")  
    call append(line(".")+15, "const int MAXN=1010;")  
    call append(line(".")+16, "typedef int array[MAXN];")  
    call append(line(".")+17, "")  
  endif
endfunc


func Run()
  exec "w"
  exec "!g++ % -o a.exe && ./a.exe < in.txt"
endfunc

map <C-K> :call Run()<CR>
