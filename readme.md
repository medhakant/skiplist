## SKIPLIST
The `source` files and the  `makefile` are in the src directory. The `include` directory contains header files. Compiled `object` files are stored in `.\src\obj\`. Compile the program by running 
```bash
make
```
and then run the program by typing 
```bash
.\skiplist
```
Note: When you try to insert a key already present in the skiplist, it is ignored.

Sample output of the code -
```bash
*****PRINTING SKIP LIST*****
-inf----------------------------------inf
-inf--------------21------------------inf
-inf--------------21------------------inf
-inf--------------21------------------inf
-inf--------------21--45--------------inf
-inf--------------21--45--------------inf
-inf--07--11--14--21--45--53--67--99--inf

*****PRINTING SKIP LIST*****
-inf------------------------------inf
-inf--------------45--------------inf
-inf--------------45--------------inf
-inf--07--11--14--45--53--67--99--inf

Search result: (45, ghi)
Entry not saved.
Greater entry: (45, ghi)
Lesser entry: (14, def)
*****PRINTING SKIP LIST*****
-inf------------------------------------------------------------------------------------------------------------------------------------------------------------------inf
-inf------------------------------------------------------------------------------------------------------------------------------78----------------------------------inf
-inf----------------------------------------------23------------------------------------------------------------------------------78----------------------------------inf
-inf----------------------------------------------23------------------------------------------------------------------------------78--------------------------93------inf
-inf----------------------------------------------23------------------------------------------------------------------------------78--------------89----------93------inf
-inf----------------------09----------------------23------------------------------------------------------------------------------78--------------89----------93------inf
-inf----------------------09----------15----------23------------------34----------------------52----------------------------------78--------------89----------93------inf
-inf----------------------09----------15----------23------------------34------------------48--52------------------------------77--78------86------89----------93------inf
-inf--00------04----------09----------15--16--21--23--------------33--34--35--36----------48--52----------58------------------77--78------86------89--90--91--93------inf
-inf--00--02--04--07--08--09--12--14--15--16--21--23--24--28--29--33--34--35--36--37--38--48--52--55--57--58--61--67--68--73--77--78--85--86--87--89--90--91--93--98--inf
```