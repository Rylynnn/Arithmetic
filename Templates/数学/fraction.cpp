struct Fraction
{
	LL num,den;
	Fraction(LL num=0,LL den=1)
	{
		if (den<0)
		{
			num=-num;
			den=-den;
		}
		LL g=gcd(abs(num),den);
		this->num=num/g;
		this->den=den/g;
	}
	Fraction operator +(const Fraction &o) const
	{
		return Fraction(num*o.den+den*o.num,den*o.den);
	}
	Fraction operator -(const Fraction &o) const
	{
		return Fraction(num*o.den-den*o.num,den*o.den);
    }
    Fraction operator *(const Fraction &o) const
    {
		return Fraction(num*o.num,den*o.den);
	}
	Fraction operator /(const Fraction &o) const
	{
		return Fraction(num*o.den,den*o.num);
	}
	bool operator <(const Fraction &o) const
	{
		return num*o.den<den*o.num;
	} 
	bool operator >(const Fraction &o) const
	{
		return num*o.den>den*o.num;
	} 
	bool operator ==(const Fraction &o) const
	{
		return num*o.den==den*o.num;
	}
};
