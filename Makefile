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

notify-build:
	@echo building

notify-link:
	@echo
	@echo linking

build: notify-build bin obj ${OBJ_FILES} notify-link tags deps
	${CC} ${CXXFLAGS} ${OBJ_FILES} ${LDFLAGS} -o ${TARGET}

-include $(DEPS)

obj/%.o: obj
obj/%.o: src/%.cc
	${CC} ${CXXFLAGS} -MMD -c $< -o $@

run:
	@echo -n running
	@./${BIN}

.PHONY: tags
tags:
	@echo generating tags
	@ctags -R --exclude=.git --c++-kinds=+p --fields=+iaS --extras=+q .

.PHONY: deps
deps:
	@echo gathering deps
	@echo ${CXXFLAGS} | tr " " "\n" >| .ccls

.PHONY: clean
clean:
	@echo cleaning
	@rm -rf ./bin ./release ./obj
