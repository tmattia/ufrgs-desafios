test:
	g++ $(p).cpp -o $(p)
	./$(p) < $(p).in
	rm $(p)
