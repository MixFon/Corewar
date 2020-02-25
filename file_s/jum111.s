#debut du mega truc qu'il est trop dur a faire

.name "Jumper !"
.comment "en fait C forker !"

gobepc:	st r1,:buff
	st r6,-4
	ld :buff,r1
debut:	ld %0,r7
	zjmp %:suite

goboucle0:	live %66
		ldi %-5,r3,r1
		sti r1,%-173,r3
		add r3,r4,r3
		xor r5,r3,r6
		zjmp %:finboucle0
		ld %0,r7
		zjmp %:goboucle0
finboucle0:	xor r3,r3,r3
		zjmp %-207

buff:	st r1,r1	
suite:	sti r1,%:buff,%1
