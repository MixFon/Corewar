#
# Warrior qui a gagne
# l'annee derniere
#     VOALA
#
.name		"Celebration Funebre v0.99pl42"
.comment	"Jour J"

buff:
	sti	  r3, 3, %3
	or	  r2, %23, r3
	or	  r2, r2, r3
	or	  %24, %32, r5
	or	  %:buff, %:buff, r5
	or	  11, 22, r5
	or	  :buff, :buff, r5

	st r2, r4
	st r2, 45
	xor	  r2, %-23, r3
	xor	  r2, r2, r3
	xor	  %24, %32, r5
	xor	  %:buff, %:buff, r5
	xor	  11, 22, r5
	xor	  :buff, :buff, r5

	and	  r2, %-23, r3
	and	  r2, r2, r3
	and	  %24, %32, r5
	and	  %:buff, %:buff, r5
	and	  11, 22, r5
	and	  :buff, :buff, r5

buf2:
	lld	%21, r3
	lld	21, r4
	lld	:buff, r4
	lld	%:buff, r4

	ld	%21, r3
	ld	21, r4
	ld	:buff, r4
	ld	%:buff, r4
	ld   %2,r3

	ldi r1, r3, r4
	ldi %23, %43, r5
	ldi %:buf2, %:buf2, r5
	ldi :buf2, %:buf2, r5
	ldi 23, %53, r5

	lldi r1, r3, r4
	lldi %23, %43, r5
	lldi %:buf2, %:buf2, r5
	lldi :buf2, %:buf2, r5
	lldi 23, %53, r5

	add r1, r3, r4
	sub r1, r3, r4

	aff r4
	lfork %43
	fork %43
	zjmp %43
	live %43



