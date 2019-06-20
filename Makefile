include config.mk

all: quick_build

quick_build:
	$(MAKE) -j39 build

install:
	install $(BIN) $(INSTALL)$(PROJECT)

bin:
	@[ -d bin ] || mkdir bin

obj:
	@[ -d obj ] || mkdir obj

build: bin obj ${OBJ_FILES} tags deps
	${CC} ${CXXFLAGS} ${OBJ_FILES} ${LDFLAGS} -o ${TARGET}

-include $(DEPS)

obj/%.o: obj
obj/%.o: src/%.cc
	${CC} ${CXXFLAGS} -MMD -MP -c $< -o $@

obj/%.o: src/browser/%.cc
	${CC} ${CXXFLAGS} -MMD -MP -c $< -o $@

obj/%.o: src/browser/statusbar/%.cc
	${CC} ${CXXFLAGS} -MMD -MP -c $< -o $@

obj/%.o: src/browser/tabbar/%.cc
	${CC} ${CXXFLAGS} -MMD -MP -c $< -o $@

%.moc.cc: %.hh
	moc $< -o $@

run:
	@echo -n running
	@./${BIN}

.PHONY: tags
tags:
	@ctags -R --exclude=.git --c++-kinds=+p --fields=+iaS --extras=+q .

.PHONY: deps
deps:
	@echo ${CXXFLAGS} | tr " " "\n" >| .ccls

.PHONY: clean
clean:
	@echo cleaning
	@rm -rf ./bin ./release ./obj ./src/browser{,/statusbar,/tabbar}/*.moc.cc
