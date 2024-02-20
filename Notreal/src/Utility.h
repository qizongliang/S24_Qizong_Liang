#pragma once

#define START_GAME(classname) \
int main() \
{\
	classname _game;\
	_game.Run();\
	return 0;\
}
#ifdef NOTREAL_MS_COMPILER
	#ifdef NOTREAL_LIB
		#define NOTREAL_API __declspec(dllexport)
	#else
		#define NOTREAL_API __declspec(dllimport)
	#endif
#else
	#define NOTREAL_API
#endif


#if NOTREAL_DEBUG==2
	#define NOTREAL_ERROR(x) std::cout<<x<<std::endl;
	#define NOTREAL_LOG(x) std::cout<<x<<std::endl;
#elif NOTREAL_DEBUG==1
	#define NOTREAL_ERROR(x) std::cout<<x<<std::endl;
	#define NOTREAL_LOG(x)
#else
	#define NOTREAL_ERROR(x)
	#define NOTREAL_LOG(x)
#endif