#include "stdafx.h"
#include "source.h"

void source::source_p() {
	const char *alphabet = "abcdefghijklmnopqrstuvwxyz\n";

	while (*alphabet) {
		out->write(*alphabet++);
	}
}