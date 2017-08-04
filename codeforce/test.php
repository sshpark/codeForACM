<?php
	fscanf(STDIN, "%s", $goodStr);
	fscanf(STDIN, "%s", $pan);	
	$insert = "[^$goodStr]*";
	$insert1 = "[$goodStr]";
	$pan = preg_replace('/\*/', $insert, $pan);
	$pan = preg_replace('/\?/', $insert1, $pan);
	$pan = "/^" . $pan . "$/";
	fscanf(STDIN, "%d", $n);
	for ($i = 0; $i < $n; $i++)
	{
		fscanf(STDIN, "%s", $str);
		if (preg_match($pan, $str) == true)
			print "YES\n";
		else
			print "NO\n";
	}