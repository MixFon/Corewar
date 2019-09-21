.name "dsfsdfsdfsdfaf" #asdfasdf
.comment "ta mere ellefait durodeosur les kfar"

buff2:
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
