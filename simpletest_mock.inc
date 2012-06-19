<?php

class DrupalUnitTestCaseWithMock extends DrupalUnitTestCase {
	
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
		
		return new $classNameForInstance;
		
	}
	
}

interface MockMethod {
	
	function invoke();
	
}