#ifndef OX_H
#define OX_H

class OX {
public:
	OX();
	void draw();//getPosition
	void wrong();
	bool setPosition(int position, int& round);
	bool gameover();
	bool whoFirst();
private:
	int rowSize=3, columnSize=3;
	char table[3][3] = {'\0'};

};

#endif

