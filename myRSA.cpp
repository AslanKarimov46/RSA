#include "long_arithmetics.h"


int main(){

	std::deque<uint8_t> 
	p1=str_to_deq("96192759682482136361283586897480020521087875967458251803173219241271230713408783056720392924724665501252020941604287048896677210643120613751471976510767"),
	q1=str_to_deq("14612087592038378751152858509524512533536096028044190178822935218486730194880516808459166772134240378240755073828170296740373082348622309614668344831750401"), 
	p2=str_to_deq("68718952447"),
	q2=str_to_deq("1046527"),
	n=p2*q2, deq1={1}, deq0={0},
	fn=(p2-deq1)*(q2-deq1), e1=str_to_deq("17"), e2=str_to_deq("257"), e3=str_to_deq("65537"), 
	e, d=d_finder(fn, e1), mes, scrumbled_mes, unscrumbled_mes;

	std::string message="hello world, I'm crocodile46";
	for(int i=0; i!=message.size(); i++){
		char j=deq_to_int(unscrumble( scrumble(int_to_deq(message[i]), e1, n), d, n));
		std::cout<<j;
	}


/*	int message=189;
	mes=int_to_deq(message);
	scrumbled_mes=scrumble(mes, e1, n);
	unscrumbled_mes=unscrumble(scrumbled_mes, d, n);

	std::cout<<"p="<<p<<"\nq="<<q<<"\nn="<<n<<"\nfn="<<fn<<"\ne="<<e1<<"\n";
	std::cout<<scrumbled_mes<<"\n";
	//std::cout<<
	std::cout<<unscrumbled_mes<<"\n";*/


return 0;
}



















