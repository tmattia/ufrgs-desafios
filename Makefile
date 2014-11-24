test:
	g++ $(p).cpp -o $(p)
	./$(p) < in/$(p).in
	rm $(p)
