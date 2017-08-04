<?php
	while (fscanf(STDIN, "%d", $n) == 1)
	{
		$area = 0;
		for ($i = $n; $i < 600; $i += $n)
			$area += $i*$i*$n;
		print $area . "\n";
	}