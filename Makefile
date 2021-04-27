all:
	for d in UnitTestHuntTheWumpus; \
	do \
		$(MAKE) -j --directory=$$d all; \
	done

clean:
	$(MAKE) -j -C UnitTestHuntTheWumpus clean
