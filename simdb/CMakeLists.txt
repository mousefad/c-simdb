add_library(simdb simdb.c)
install(TARGETS simdb DESTINATION lib)
install(FILES simdb.h DESTINATION include)
