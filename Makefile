dependency:
	DOT_PATH=/usr/bin/sh
	cd build && cmake .. --graphviz=graph.dot && dot -Tpng graph.dot -o graphImage.png

prepare:
	rm -rf build
	mkdir build



	