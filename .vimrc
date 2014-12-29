set nu
syntax on
set cindent
set shiftwidth=2
set expandtab
set mouse=a
set cursorline
set ruler
set background=dark


func Run()
  exec "w"
  exec "!g++ % -o %<.exe && ./%<.exe < in.txt"
endfunc

map <C-K> :call Run()<CR>
