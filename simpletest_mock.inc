<?php

class DrupalUnitTestCaseWithMock extends DrupalUnitTestCase {
	
	protected function getMock( $className ) {
		
		$tag = substr( md5( rand() ), 0, 6 );
		
		ob_start();
		include dirname(__FILE__).'/template/mockObject.php';
		$evalCode = ob_get_clean();
		
		include dirname(__FILE__).'/template/eval.php';
		
		$classNameForInstance = 'MockObject_'.$tag;
		
		return new $classNameForInstance;
		
	}
	
}