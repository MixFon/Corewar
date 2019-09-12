#deassembler par msa 1.8, made by joe
.name"Tchingtching(Intercepteur),Bouh!Bouh!(bruits d'anti-jeu)"
.comment"ta mere ellefait durodeosur les kfar"

loop:
        sti r1, %:live, %1
live:
        live %0
        ld %0, r2
        zjmp %:loop
