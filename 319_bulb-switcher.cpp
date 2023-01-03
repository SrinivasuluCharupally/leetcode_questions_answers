// it's simple
//


void recursion(bool &inputBulbs, int round) {
	if(round >= inputBulbs.size()) return;

	int off = round;

	while(off < inputBulbs.size()) {
		if(inputBulbs[off] ) inputBulbs[off] = false;
		else inputBulbs[off]  = true;
		off += round; // nothing but multiple of that round;;;
	}

	recursion(inputBulbs, round++);
}


int main() {
	bool inputBulbs[5] = {true}; // this means first round is completed

	recursion(inputBulbs, 2);
}
