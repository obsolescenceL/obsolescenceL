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
colorscheme solarized
set lbr "不在单词中间断行
"禁止生成临时文件
set nobackup
set noswapfile
autocmd BufNewFile *.cpp exec ":call SetTitle()"
func SetTitle()
  if &filetype == 'cpp'
    call setline(1, "/*************************************************************************")   
    call append(line("."), "     File Name: ".expand("%"))   
    call append(line(".")+1, "     ID: obsoles1")   
    call append(line(".")+2, "     PROG: ")   
    call append(line(".")+3, "     LANG: C++ ")   
    call append(line(".")+4, "     Mail: 384099319@qq.com ")   
    call append(line(".")+5, "     Created Time: ".strftime("%c"))   
    call append(line(".")+6, " ************************************************************************/")   
    call append(line(".")+7, "")  
  endif
endfunc


func Run()
  exec "w"
  exec "!g++ -std=c++11 % -o a.exe && ./a.exe < in.txt"
endfunc

map <C-K> :call Run()<CR>
