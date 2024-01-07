all: mysearch mytail myls mystat	

mysearch: mysearch-kamryn.c
	gcc	-o	mysearch	mysearch-kamryn.c
mytail:	mytail-kamryn.c
	gcc	-o	mytail	mytail-kamryn.c
myls:	myls-kamryn.c
	gcc	-o	myls	myls-kamryn.c
mystat:	mystat-kamryn.c
	gcc	-o	mystat	mystat-kamryn.c