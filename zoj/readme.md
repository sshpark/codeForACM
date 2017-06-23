# c++ sublime build for windows

```
{	
  "encoding": "utf-8",	
  "working_dir": "$file_path",	
  "shell_cmd": "g++ -Wall \"$file_name\" -o \"$file_base_name\"",	
  "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",	         
  "selector": "source.c++", 	
  "variants": 	
  [		
    {			
      "name": "Run",        	
      "shell_cmd": "g++ -Wall  \"$file\" -o \"$file_base_name\" && start cmd /c \"\"${file_path}/${file_base_name}\" & pause\""		
    }	
  ]
}
```