empty:
	@echo "----No Target!!!!"
	
clean:
	#rm -f tmp;
	
.PHONY: so serversvn 


server:
	rm -f main
	gcc -lstdc++  -rdynamic -L./ Entity.cpp EntityManager.cpp main.cpp Monster.cpp Player.cpp -ldl -o main  
do:
	rm -f libMgrDo.so
	gcc -lstdc++  -L./  -fpic -shared -D BUILD_SO -o libMgrDo.so MonsterEx.cpp 