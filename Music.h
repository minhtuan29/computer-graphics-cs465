#ifndef MUSIC_H
#define MUSIC_H

class Music{
public:
	
	static void play(const char* src)
	{
		PlaySound(TEXT(src), NULL, SND_ASYNC);
	}
	
	static void stop_play()
	{
		PlaySound(NULL, 0, 0);
	}
};

#endif
