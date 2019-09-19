.name "Jumper !"
.comment "en fait C forker !"

	ld -65535,r1
	ld %7,r2
	ld :buff,r4	
	ld %:buff,r4	
buff:
	st r1,r1	
