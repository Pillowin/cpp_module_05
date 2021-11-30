let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Documents/GitHub/cpp_module_05/ex02
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +75 Bureaucrat.cpp
badd +13 Form.cpp
badd +19 RobotomyRequestForm.cpp
badd +1 ShrubberyCreationForm.cpp
badd +63 main.cpp
badd +1 Bureaucrat.hpp
badd +57 Form.hpp
badd +1 ShrubberyCreationForm.hpp
badd +26 AForm.cpp
badd +1 AForm.hpp
badd +1 RobotomyRequestForm.hpp
badd +0 PresidentialPardonForm.hpp
badd +43 PresidentialPardonForm.cpp
argglobal
%argdel
$argadd Bureaucrat.cpp
$argadd Form.cpp
$argadd RobotomyRequestForm.cpp
$argadd ShrubberyCreationForm.cpp
$argadd main.cpp
set stal=2
tabnew
tabnew
tabnew
tabnew
tabnew
tabrewind
edit main.cpp
argglobal
5argu
balt ShrubberyCreationForm.hpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 2 - ((1 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 2
normal! 0
tabnext
edit Bureaucrat.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 90 + 90) / 180)
exe 'vert 2resize ' . ((&columns * 89 + 90) / 180)
argglobal
1argu
if bufexists("Bureaucrat.hpp") | buffer Bureaucrat.hpp | else | edit Bureaucrat.hpp | endif
if &buftype ==# 'terminal'
  silent file Bureaucrat.hpp
endif
balt Bureaucrat.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 30 - ((29 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 30
normal! 019|
wincmd w
argglobal
1argu
balt Bureaucrat.hpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 38 - ((25 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 38
normal! 031|
wincmd w
exe 'vert 1resize ' . ((&columns * 90 + 90) / 180)
exe 'vert 2resize ' . ((&columns * 89 + 90) / 180)
tabnext
edit AForm.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 90 + 90) / 180)
exe 'vert 2resize ' . ((&columns * 89 + 90) / 180)
argglobal
2argu
if bufexists("AForm.hpp") | buffer AForm.hpp | else | edit AForm.hpp | endif
if &buftype ==# 'terminal'
  silent file AForm.hpp
endif
balt Form.hpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 22 - ((21 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 22
normal! 048|
wincmd w
argglobal
2argu
if bufexists("AForm.cpp") | buffer AForm.cpp | else | edit AForm.cpp | endif
if &buftype ==# 'terminal'
  silent file AForm.cpp
endif
balt Form.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 27 - ((26 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 27
normal! 050|
wincmd w
exe 'vert 1resize ' . ((&columns * 90 + 90) / 180)
exe 'vert 2resize ' . ((&columns * 89 + 90) / 180)
tabnext
edit ShrubberyCreationForm.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 87 + 90) / 180)
exe 'vert 2resize ' . ((&columns * 92 + 90) / 180)
argglobal
4argu
if bufexists("ShrubberyCreationForm.hpp") | buffer ShrubberyCreationForm.hpp | else | edit ShrubberyCreationForm.hpp | endif
if &buftype ==# 'terminal'
  silent file ShrubberyCreationForm.hpp
endif
balt ShrubberyCreationForm.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 21 - ((20 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 21
normal! 0
wincmd w
argglobal
4argu
balt ShrubberyCreationForm.hpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 48 - ((34 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 48
normal! 05|
wincmd w
exe 'vert 1resize ' . ((&columns * 87 + 90) / 180)
exe 'vert 2resize ' . ((&columns * 92 + 90) / 180)
tabnext
edit RobotomyRequestForm.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 90 + 90) / 180)
exe 'vert 2resize ' . ((&columns * 89 + 90) / 180)
argglobal
5argu
if bufexists("RobotomyRequestForm.hpp") | buffer RobotomyRequestForm.hpp | else | edit RobotomyRequestForm.hpp | endif
if &buftype ==# 'terminal'
  silent file RobotomyRequestForm.hpp
endif
balt main.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 16 - ((15 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 16
normal! 0
wincmd w
argglobal
5argu
if bufexists("RobotomyRequestForm.cpp") | buffer RobotomyRequestForm.cpp | else | edit RobotomyRequestForm.cpp | endif
if &buftype ==# 'terminal'
  silent file RobotomyRequestForm.cpp
endif
balt ShrubberyCreationForm.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 2 - ((1 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 2
normal! 019|
wincmd w
exe 'vert 1resize ' . ((&columns * 90 + 90) / 180)
exe 'vert 2resize ' . ((&columns * 89 + 90) / 180)
tabnext
edit PresidentialPardonForm.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 89 + 90) / 180)
exe 'vert 2resize ' . ((&columns * 90 + 90) / 180)
argglobal
if bufexists("PresidentialPardonForm.hpp") | buffer PresidentialPardonForm.hpp | else | edit PresidentialPardonForm.hpp | endif
if &buftype ==# 'terminal'
  silent file PresidentialPardonForm.hpp
endif
balt RobotomyRequestForm.hpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 20 - ((16 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 20
normal! 0
wincmd w
argglobal
if bufexists("PresidentialPardonForm.cpp") | buffer PresidentialPardonForm.cpp | else | edit PresidentialPardonForm.cpp | endif
if &buftype ==# 'terminal'
  silent file PresidentialPardonForm.cpp
endif
balt RobotomyRequestForm.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 43 - ((42 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 43
normal! 017|
wincmd w
exe 'vert 1resize ' . ((&columns * 89 + 90) / 180)
exe 'vert 2resize ' . ((&columns * 90 + 90) / 180)
tabnext 1
set stal=1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0&& getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToOF
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
