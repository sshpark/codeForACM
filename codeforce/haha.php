<?php
	function str_insert($str,$i,$substr)
	{
	  $start=substr($str,0,$i);
	  $end=substr($str,$i);
	  $str = ($start . $substr . $end);
	  return $str;
	}

	while (fscanf(STDIN, "%s", $goodStr) == 1) 
	{
		$loc = 0;
		fscanf(STDIN, "%s", $pan);
		fscanf(STDIN, "%d", $n);
		$lowstr = "/abcdefghijklmnopqrstuvwxyz";
		$endChar = $goodStr[strlen($goodStr)-1];
		if (strlen($goodStr) == 1)
		{
			$next = $lowstr[strpos($lowstr, $goodStr)+1];
			$insert = "[a-$endChar|$next-z]";
			$insert1 = "[$goodStr]";
		}
		else
		{
			$insert = "[$endChar-z]";
			$insert1 = "[a-$goodStr]";
		}

		$add = 0;
		for ($i = 0; $i < strlen($pan); $i++)
		{
			if ($pan[$i] == '*')
			{
				$pan = str_insert($pan, $value+$add, $insert);
				$add = $add + strlen($insert);
			}
			else if ($pan[$i] == '?')
			{
				$pan = str_insert($pan, $value+$add, $insert1);			}
				$add = $add + strlen($insert1);
			}
		}
		$pan = '/' . $pan . '/';
		print $pan . "\n";
		for ($i = 0; $i < $n; $i++)
		{
			fscanf(STDIN, "%s", $str);
			if (preg_match($pan, $str) == true)
				print "YES\n";
			else
				print "NO\n";
		}
	}