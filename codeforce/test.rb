m = gets.to_i
n = m*2
r = 1
i = n
while i != m
	r = r*i/(i-m)
	i -= 1
end
puts r/(m+1)