####################################
#Author: u6th9d
#E-mail: u6th9d@outlook.com
#Copyright (c) 2015-07-26
#All rights reserved
####################################

#!/usr/bin/env python
# -*- coding:utf-8 -*-

import time, threading, sys

def sleep_task(item):
	time.sleep(item)
	print(item)
	
if __name__ == "__main__":
	num_list = sys.argv[1:]
	thread_pool = [threading.Thread(target = sleep_task, args = (int(item),)) for item in num_list]
	for item in thread_pool:
		item.start()
	for item in thread_pool:
		item.join()
	print("Done...")