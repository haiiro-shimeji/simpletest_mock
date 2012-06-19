class MockObject_<?php echo $tag ?> extends <?php echo $className ?> {

<?php
	foreach ( $methods as $method ) {
		
		$accessor = ( $method->isProtected() ? 'protected' : 'public' );
		
		echo ( $method->isProtected() ? 'protected' : 'public' )
			.' function '.$method->name.'() { return call_user_func_array(array($this, "parent::'.$method->name.'"), func_get_args()); }'."\n";
		
	}
?>

}