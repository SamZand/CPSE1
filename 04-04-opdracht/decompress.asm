.cpu cortex-m0
.data
buffer_length = 100
uncompressed: .skip buffer_length
.text
.align 2
.global decompress

decompress:
	push 	{r4-r7,lr}
	ldr	r5, =compressed_data
	
loop:
	ldrb 	r4, [r5]			// laad het index karakter in r4

	cmp 	r4, #0
    beq 	done				// EOF

	cmp 	r4, #'@'			// if r0 = @ decoder
	beq		decoder			

	mov 	r0, r4      		//copy R4 content to R0
    bl 		buffer   
    add 	r5, #1				//move the compressed_data pointer to next char
    b 		loop
	
decoder:
	add 	r5, #1				// index++
	ldrb 	r6, [r5]			// laad eerste karakter na de @ in r6
	add 	r5, #1				// index++
	ldrb 	r7, [r5]			// laad tweede karakter na de @ in r7
	sub 	r6, #'0'			// -48, zet offset karakter om naar int
	sub 	r7, #'0'			// -48, zet lengte karakter om naar int
	ldr 	r4, =uncompressed	// laad uncompressed pointer in r4
	
decompressLoop:
	ldrb 	r0, [r4, r6]		// laad buffer en offset in r0
	bl 		buffer				// branch naar buffer subroutine

	sub		r7, #1				// r7 length--
	bne 	decompressLoop
	add 	r5, #1 				// check of r7 == 1 als true is de compresssion gedaan
	b 		loop				// loop
	
buffer:
	ldr 	r1, =uncompressed	// sla uncompressed pointer op in r1
	mov 	r2, #buffer_length	// laad 100 in r2 (max uncompressed size)

bufferLoop:
	sub 	r2, #1 				// index--
	ldrb 	r3, [r1, r2] 		// laad memeory in r3
	add 	r2, #1				// index++
	strb 	r3, [r1, r2]		// sla het karakter op in r3 met een index r1 in r2
	sub 	r2, #1				// index--

	sub 	r2, #0				// vergelijk r1 met 0
	blt 	bufferDone			// branch wanneer gelijk
	b 		bufferLoop			// loop
	
bufferDone:
	strb 	r0, [r1]			// sla r0 op in r1, r1 is de uncompressed pointer
	b 		print_char			// print char
	mov 	pc, lr
	
done:
	pop 	{r4-r7, pc} 		// pop de pc