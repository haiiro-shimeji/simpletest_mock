class MockObject_<?php echo $tag ?> extends <?php echo $className ?> implements MockObject {

	var $methods;
	
	protected function invokeMethod( $methodName, $args ) {
	
		$method = $this->methods[ $methodName ];
		
		if ( $method->isStub() ) {
			return $method->invoke( $args );
		} else {
			return call_user_func_array(array($this, "parent::".$methodName), $args);
		}
	
	}

	function method( $methodName ) {
		return $this->methods[ $methodName ];
	}

<?php
	foreach ( $methods as $method ) {
		
		$accessor = ( $method->isProtected() ? 'protected' : 'public' );
		
		echo ( $method->isProtected() ? 'protected' : 'public' )
			.' function '.$method->name.'() { return $this->invokeMethod( "'.$method->name.'", func_get_args() ); }'."\n";
		
	}
?>

}