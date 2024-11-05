#include "long_arithmetics.h"


std::deque<uint8_t> operator+(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2){
	std::deque<uint8_t> result;
	std::deque num_1=num1, num_2=num2;
	int size1=num1.size(), size2=num2.size();
	if(size1>=size2){
		for(int i=0; i!=size1-size2; i++)
			num_2.push_front(0);
	}else{
		for(int i=0; i!=size2-size1; i++)
			num_1.push_front(0);
	}
	int ost=0, size=num_1.size();
	for(int i=0; i!=size; i++){
		int x=num_1[size-i-1]+num_2[size-i-1]+ost;
		int elem=x%10;
		ost=x/10;
		result.push_front(elem);
		
	}
	if(ost!=0)
		result.push_front(ost);
	return result;
}


std::deque<uint8_t> operator-(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2) {
    std::deque<uint8_t> num_1=num1, num_2=num2;

    while (num_2.size()<num_1.size()) {
        num_2.push_front(0);
    }
    int borrow = 0;
    for(int i=num_1.size()-1; i>=0; --i){
        int difference=num_1[i]-num_2[i]-borrow;
        if (difference<0){
            difference+=10;
            borrow=1;
        }else
            borrow = 0;
        num_1[i] = difference;
    }
    while(num_1.size()> 1&& num_1.front()==0){
        num_1.pop_front();
    }

    return num_1;
}


bool operator>(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2){
	int size1=num1.size(), size2=num2.size();
	if(size1>size2)
		return true;
	else if(size2>size1)
		return false;
	else{
		for(int i=0; i!=size1; i++){
			if(num1[i]>num2[i])
				return true;
			else if(num1[i]<num2[i]) 
				return false;
		}
	}
	return false;
}


bool operator<(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2){
	if(num1==num2)
		return false;
	else
		return !(num1>num2);
}


bool operator==(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2){
    if(num1.size()!=num2.size()){
        return false;
    }
    for(int i = 0;i<num1.size();++i){
        if(num1[i]!=num2[i]){
        	return false;
        }
    }
    return true;
}


bool operator!=(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2){
	return !(num1==num2);
}


std::ostream& operator<<(std::ostream& out, const std::deque<uint8_t>& num){
	for(const int n:num)
		out<<n;
	return out;
}


std::istream& operator>>(std::istream& in, std::deque<uint8_t>& num){
	char n;
	while(in>>n)
		num.push_back(n-'0');
	return in;
}


std::deque<uint8_t> operator*(const std::deque<uint8_t>& num, int a) {
    std::deque<uint8_t> result(num.size(), 0);
	int ost=0;
    for(int i=num.size()-1;i>=0;--i){
        int n=num[i];
        int b=n*a+ost;
        result[i]=b%10;
        ost=b/10;      
    }

    while(ost>0){
        result.push_front(ost%10);
        ost/=10;
    }

    return result;
}


std::deque<uint8_t> operator*(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2){
	std::deque<uint8_t> result;
	for(int i=0; i!=num2.size(); i++){
		std::deque<uint8_t> x=num1*num2[i];
		for(int j=0; j!=num2.size()-1-i; j++)
			x.push_back(0);
		result=result+x;
	}
	return result;
}


std::deque<uint8_t> part(const std::deque<uint8_t>& num, int begin, int end){
	std::deque<uint8_t> result;
	for(int i=begin; i<=end; i++)
		result.push_back(num[i]);
	return result;
}


std::deque<uint8_t> str_to_deq(const std::string& str){
	std::deque<uint8_t> result;
	for(int i=0; i!=str.size(); i++)
		result.push_back(str[i]-'0');
	return result;
}

std::deque<uint8_t> operator%(const std::deque<uint8_t>& num1, const std::deque<uint8_t>& num2){
	std::deque<uint8_t> num_1=num1, a, b;	
	if(num1<num2){
		return num1;
	}

	while(num_1>num2 || num_1==num2){
	if(num_1==num2){
		return {0};
	}
	uint8_t flaq=0;

	a=part(num_1, 0, num2.size()-1);
	if(a<num2){ 
		a=part(num_1, 0, num2.size());
		flaq=1;
	}

		for(int i=1; i!=10; i++){
			if( (num2*i<a || num2*i==a) && num2*(i+1)>a ){
				b=num2*i;
				for(int i=0; i!=num_1.size()-a.size(); i++)
					b.push_back(0);
				num_1=num_1-b;
			}	
		}
	}
	return num_1;
}


std::deque<uint8_t> operator/(const std::deque<uint8_t>& lhs, const std::deque<uint8_t>& rhs){

    std::deque<uint8_t> quotient;           //частное
    std::deque<uint8_t> remainder;          //отстаток

    for(int i=0; i<lhs.size(); i++){
        remainder.push_back(lhs[i]);

        while(!remainder.empty() && remainder.front()==0){
            remainder.pop_front();
        }
        if(remainder<rhs){
            quotient.push_back(0);
            continue;
        }
        int low=0, high=9, best_factor=0;
        while((low<high) || (low==high)){
            int mid=(low+high)/2;
            std::deque<uint8_t> mid_product=rhs*mid;
            if((mid_product<remainder) || (mid_product==remainder)){
                best_factor=mid;
                low=mid+1;
            }else
                high=mid-1;
        }
        quotient.push_back(best_factor);
        remainder=remainder-rhs*best_factor;
    }
    while(quotient.size()>1 && quotient.front()==0){
        quotient.pop_front();
    }

    return quotient;
}


std::deque<uint8_t> int_to_deq(const int num){
	std::deque<uint8_t> result;
	int n=num;
	while(n!=0){
		result.push_front(n%10);
		n/=10;
	}
	return result;
}


//(x^y) mod n, a_1=x mod n, a_2=(a_1*a_1) mod n, a_3=(a_2*a_1) mod n, ..., a_y=(a_(y-1)*a_1) mod n
std::deque<uint8_t> pow_mod(const std::deque<uint8_t>& x, 
										const std::deque<uint8_t>& y, const std::deque<uint8_t>& n){
	std::deque<uint8_t> result, deq0={0}, binary_y=binary_deq(y), a, b=x%n;
	std::deque< std::deque<uint8_t> > x_pow_y_mod_n;
	//std::cout<<"binary_y="<<binary_y<<"\n";
	x_pow_y_mod_n.push_back(b);
	//std::cout<<"x_pow_y_mod_n[0]="<<x_pow_y_mod_n[0]<<"\n";
	for(int i=1; i!=binary_y.size(); i++){
		a=((*x_pow_y_mod_n.rbegin())*(*x_pow_y_mod_n.rbegin()))%n;
		x_pow_y_mod_n.push_back(a);
		//std::cout<<"x_pow_y_mod_n["<<i<<"]="<<x_pow_y_mod_n[i]<<"\n";
	}

	/*for(int i=0; i!=binary_y.size(); i++)
		std::cout<<x_pow_y_mod_n[i]<<"  ";
	std::cout<<"\n";*/

	for(int i=binary_y.size()-1; i!=-1; i--){
		if(binary_y[i]==0){
			x_pow_y_mod_n[binary_y.size()-1-i]={1};
		}
	}
	result=x_pow_y_mod_n[0];

	/*for(int i=0; i!=binary_y.size(); i++)
		std::cout<<x_pow_y_mod_n[i]<<"  ";
	std::cout<<"\n";*/

	for(int i=1; i!=binary_y.size(); i++){
		result=(result*x_pow_y_mod_n[i])%n;
	}

	return result;
}


std::deque<uint8_t> binary_deq(const std::deque<uint8_t>& n){
    std::deque<uint8_t> number=n;
    std::deque<uint8_t> result;

    while (!number.empty() && !(number.size()==1 && number[0]==0)){
        uint8_t remainder=0;
        for (size_t i=0; i<number.size(); ++i){
            uint8_t current=remainder*10+number[i];
            number[i]=current/2;
            remainder=current%2;
        }

        result.push_front(remainder);

        while (!number.empty() && number.front() == 0) {
            number.pop_front();
        }
    }

    return result;
}


std::deque<uint8_t> d_finder(const std::deque<uint8_t>& fn, const std::deque<uint8_t>& e){
	std::deque<uint8_t> k={1}, deq1={1}, deq0={0};
	while( (k*fn+deq1)%e!=deq0 ){
		k=k+deq1;
		//std::cout<<k<<"\n";
	}
	return (k*fn+deq1)/e;
}


std::deque<uint8_t> scrumble(const std::deque<uint8_t>& m, 
										const std::deque<uint8_t>& e, const std::deque<uint8_t>& n){
	return pow_mod(m, e, n);
}


std::deque<uint8_t> unscrumble(const std::deque<uint8_t>& c, 
										const std::deque<uint8_t>& d, const std::deque<uint8_t>& n){
	return pow_mod(c, d, n);
}



/*std::deque<std::deque<uint8_t>> scrumble(const std::string message, 
										const std::deque<uint8_t>& e, const std::deque<uint8_t>& n){
	std::deque<std::deque<uint8_t>> result;
	for(int i=0; i!=message.size(); i++){
		result
	}
}


std::string unscrumble(const std::deque<uint8_t>& scrumbled_message, 
										const std::deque<uint8_t>& d, const std::deque<uint8_t>& n){

}*/


int deq_to_int(const std::deque<uint8_t>& num){
	int result=0;
	for(int i=num.size()-1; i!=-1; i--){
		result+=num[i]*pow(10, num.size()-i-1);
	}
	return result;
}

















