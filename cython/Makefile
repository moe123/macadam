# BOF

all: clean
	@python setup.py build_ext --inplace 1>&2 &> /dev/null

run: all
	@python mcmath_run.py

clean:
	@rm -rf build mcmath.c *.so

# EOF