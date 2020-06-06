    """ Return the largest prime factor of a given n

    :param n: integer (0 < n < 1e+12)
    :return: largest prime factor of n
    Example:
    124=31*2^2, return: 31
    """




def largest_prime_factor(n: int) -> int:
    if n==1:
        return 1

    i=2
    while n**0.5>=i:
        while n%i==0:
            if n==i:
                break
            n=n/i

        if i!=2:    
            i=i+2    
        else: i=i+1
        
    return int(n) 
    
    
 if __name__ == "__main__":
    print(largest_prime_factor(1))  # correct answer is 1
    print(largest_prime_factor(124))  # correct answer is 31
