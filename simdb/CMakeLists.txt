configure_file(simdb.h.in simdb.h)
configure_file(simdb.pc.in simdb.pc @ONLY)
add_library(simdb simdb.c)
install(TARGETS simdb DESTINATION lib)
install(FILES "${PROJECT_BINARY_DIR}/simdb/simdb.h" DESTINATION include)
install(FILES "${PROJECT_BINARY_DIR}/simdb/simdb.pc" DESTINATION share)
include_directories(
	"${PROJECT_BINARY_DIR}/simdb"
)
