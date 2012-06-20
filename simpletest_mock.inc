<?php

class DrupalWebTestCaseWithMock extends DrupalWebTestCase {
	
	protected function getMock( $className ) {
		
		$tag = substr( md5( rand() ), 0, 6 );
		
		$reflection = new ReflectionClass($className);
		$methods = $reflection->getMethods( ReflectionMethod::IS_PUBLIC 
											| ReflectionMethod::IS_PROTECTED 
											| ReflectionMethod::IS_ABSTRACT );
		
		ob_start();
		include dirname(__FILE__).'/template/mockObject.php';
		$evalCode = ob_get_clean();
		
		include dirname(__FILE__).'/template/eval.php';
		
		$classNameForInstance = 'MockObject_'.$tag;
		
		$obj = new $classNameForInstance;
		
		$obj->methods = array();
		
		foreach ( $methods as $m ) {
			$obj->methods[ $m->name ] = new MockMethod( $m );
		}
		
		return $obj;
		
	}
	
}

interface MockObject {
	function method( $methodName );
}

class MockMethod {
	
	private $method;
	private $return;
	private $stub;
	
	private $callCount = 0;
	
	function __construct( $method ) {
		$this->method = $method;
	}
	
	function expects() {}
	function willReturn( $return ) {
		$this->return = $return;
		$this->stub = true;
	}
	function alterBahavior() {}
	
	function invoke() {
		return $this->return[ $this->callCount++ ];
	}
	
	function isStub() { return $this->stub; }
	
}		