.name "Tching tching(Intercepteur), Bouh!Bouh!(bruits d'anti-jeu)"
.comment ""

one:
	st r10, 11
	st r10, 200
	st r10, 450
	ld %6, r10
	live %0
	live %0
	ld %507, r3
	fork %1000
two:
	live %666
	live %1
	live %3     
	zjmp %:start

start:
	fork  %:two
	ldi r1, %777, r7 	
	ldi r1, %777, r6 
	sti   r1,r2,r10
	sti   r1,r2,r10
	zjmp %:one
