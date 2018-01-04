<?php 
use Swoole\Table;
class Mem_swoole
{
    private $user;
    private $index;
    private $count;

    public $table;

    public function __construct($conf = []) {
        $table = new Table(1024);
        $user = [];
        $user[] = ['key' => 'ip', 'type' => Table::TYPE_STRING, 'len' => 35];
        $user[] = ['key' => 'port', 'type' => Table::TYPE_STRING, 'len' => 4];
    
        foreach ($user as $key => $value)
            $table->column($value['key'], $value['type'], $value['len']);
        
        $table->create();
    }

    public function add($key1, $ip1, $port1) {
        $table->set($key1, array('ip'=>$ip1, 'port'=>$port1));
    }

    public function query($key) {
        return $table->get($key);
    }
}

$mem = new Mem_swoole();
$mem->add(12, '127.0.0.1', '14');
// var_dump($mem->get(12));