#include "process.h"

/*
 * utilities.c
 *
 * Created on: 25 Jun 2015
 * Author: Caspar Friedrich
 */

void sleep(bool wakeupCondition) {
	while (!wakeupCondition)
		;
}
