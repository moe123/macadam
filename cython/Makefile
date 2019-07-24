# BOF

all: clean pdx pyx build
run: all
	@python mcmath_run.py 1>&2 >> mcmath.log

pdx::
	@sh mcmath_pxd.sh 1>&2 &> mcmath.log

pyx::
	@sh mcmath_pyx.sh 1>&2 &> mcmath.log

build::
	@python setup.py build_ext --inplace 1>&2 >> mcmath.log

clean:
	@rm -rf       \
		build      \
		mcmath.c   \
		mcmath.pxd \
		mcmath.pyx \
		mcmath.log \
		*.so

# EOF