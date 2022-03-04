/* I have neither given nor received any unauthorized aid on this assignment. */

.section .data

/* Initialize all of the values that we need */

A: .int	89, -5, 91, 23, -67, 31, 46, -71, -14, -10, 3, 67
Min: .int 100
Index: .int 0
Sum: .int 0
printMin: .asciz "A[%d] = %d\n"
printSum: .asciz "SUM = %d\n"

.section .text

.global main

main:
  /* Initialize values for finding the minimum */

	ldr x9, =A 							      /* Load address of array A into register */
  ldr x10, =Min							    /* Store the address of min in x10 */
	ldr x11, =Index						    /* Store the address of index in x11 */

  /* Find Minimum Positive Value */

	mov x13, #0 								  /* Initialize i to 0 */
minLoop:
  lsl x14, x13, #2              /* Shift i twice to the left aka mult by 4 */
  
	cmp x13, #12 							    /* store i - 12 in x10 with flags */
	b.ge afterMin 							  /* if i < 12, keep looping */
  add x13, x13, #1 						  /* increment i by 1 */
  
  ldrsh x15, [x9, x14] 			    /* get the i-th element of A (using signed halfword because ldr is getting 8 bytes) */

  cmp x15, #0                   /* Compare the current value with 0 */
  b.le minLoop                  /* If the current value is less than or equal to 0, loop again */
  ldrsh x16, [x10]						  /* get the value of the current Min */   
  cmp x15, x16                  /* Compare the current value with the current minimum */
  b.ge minLoop                  /* If the current value is greater than or equal to the current minimum, loop again */
  
  /* We now know that the current value is greater than 0 and less than the minimum */

  str x15, [x10]                /* Store the current value in Min */
  sub x13, x13, #1              /* Need to back the index up by 1 before storing */
  str x13, [x11]                /* Store the current index in Index */
  add x13, x13, #1 						  /* increment i by 1, back to proper value */
  b minLoop

afterMin:
  /* Print Minimum */

	ldr x0, =printMin             /* Load min print from heap */
  ldr x1, =Index                /* Load Index address as first argument */
  ldr x2, =Min                  /* Load Min address as second argument */
  ldr x1, [x1]                  /* Dereference Index address to get Index */
  ldr x2, [x2]                  /* Dereference Min address to get Min */
	bl printf

  /* Initialize values for finding the sum */

	ldr x9, =A 							      /* Load array A into register */
  ldr x10, =Min							    /* Store the address of min in x10 */
  ldr x11, [x10]                /* Get the value of Minimum for comparisons */
  and x11, x11, 0xffffffff	    /* only take the first 4 bytes of the sum value */
	ldr x12, =Sum                 /* Store the address of Sum in x12 */

  /* Find Sum of Positive values that aren't the Minimum value */

  mov x13, #0 								  /* Initialize i to 0 */
sumLoop:
  lsl x14, x13, #2              /* Shift i twice to the left aka mult by 4 */

  cmp x13, #12 							    /* store i - 12 in x10 with flags */
	b.ge afterSum 							  /* if i < 12, keep looping */
  add x13, x13, #1 						  /* increment i by 1 */

  ldrsh x15, [x9, x14] 			    /* get the i-th element of A (using signed halfword because ldr is getting 8 bytes) */
  ldr x16, [x12]						    /* get the current sum value */
  and x16, x16, 0xffffffff	    /* only take the first 4 bytes of the sum value */

  cmp x15, #0                   /* Compare the current value with 0 */
  b.le sumLoop                  /* If the current value is less than or equal to 0, loop again */
  cmp x15, x11                  /* Compare the current value with the minimum value */
  b.eq sumLoop                   /* If the current value is equal to the minimum, loop again */

  /* We now know that the value is positive and not the minimum */

	add x16, x16, x15 				    /* add the current element to the sum */
	str x16, [x12] 						    /* store the new sum in Sum */

  b sumLoop

afterSum:
  /* Print Sum */

  ldr x0, =printSum             /* Load sum print from heap */
  ldr x1, =Sum                  /* Load Sum address as argument */
  ldr x1, [x1]                  /* Dereference Sum address to get Sum */
  bl printf

	b exit

exit:
	mov x0, 0
	mov x8, 93
	svc 0
	ret
