set nu" 显示行号
syn on" 自动语法高亮
filetype on
set cin
set shiftwidth=2" 设定 << 和 >> 命令移动时的宽度为 2
set expandtab" 不要tab
"set mouse=a
set cursorline
set ruler" 打开状态栏标尺
set hlsearch " 搜索时高亮显示被找到的文本
set showcmd
set background=dark
"colorscheme solarized
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
  if &filetype == 'cpp'
    exec "!g++ -std=c++11 % -o a.exe && ./a.exe < in.txt"
  elseif &filetype == 'python'
    exec "!python %"
  elseif &filetype == 'haskell'
    "exec "!ghc --make % -o hs.exe && ./hs.exe < in.txt"
    exec "!runhaskell % < in.txt"
  endif
endfunc


map <C-K> :call Run()<CR>
