.name "dsfsdfsdfsdfaf" #asdfasdf
.comment "ta mere ellefait durodeosur les kfar"

buff2:
	lld :buff,r5
	lld %:buff,r5
	lld %45,r5
	lld 45,r5
	ldi %5, %:buff, r3
	ldi r1, r2, r3 
	ldi %:buff, %5, r3
	ldi :buff, %5, r3
	xor r4, r5, r6
	xor %4, %5, r6
	xor :buff2, :buff2, r7
	and r4, r5, r6
	and %4, %5, r6
	and :buff2, :buff2, r7
	sub r4, r5, r6
	add r1, r2, r3
	aff r3
	lfork %58
	lfork %:buff2
	live %48
	live %:buff2
	zjmp %28
	zjmp %:buff2
	fork %45
	fork %:buff
	lldi %5, %:buff, r3
	lldi r1, r2, r3 
	lldi %:buff, %5, r3
	lldi :buff, %5, r3
	or 3, :buff, r4
	or %:buff, :buff2, r5
	or :buff, 4, r5
	or :buff, 4, r5
	or :buff2, :buff2, r5
buff:
	ld %:buff,r5
#buff:
