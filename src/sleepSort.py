####################################
#Author: u6th9d
#E-mail: u6th9d@outlook.com
#Copyright (c) 2015-07-26
#All rights reserved
####################################

#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from multiprocessing import Pool
import time, sys

def sleep_task(item):
	time.sleep(item)
	print(item)
	
if __name__ == "__main__":
	item_list = sys.argv[1:]
	pool = Pool(len(item_list))
	for item in item_list:
		pool.apply_async(sleep_task, (int(item),))
	pool.close()
	pool.join()
	print("Done...")
