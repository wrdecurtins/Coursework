H = int(input("How high "))

# for ( k = 1; k <= H; k++ )

sum = 0

for k in range( 1, H + 1, 3 ):
	print(k, end=" ")
	sum = sum + k

print()
print("This is the total" , sum)
