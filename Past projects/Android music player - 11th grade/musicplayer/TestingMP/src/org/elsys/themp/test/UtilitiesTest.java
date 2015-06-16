package org.elsys.themp.test;

import junit.framework.TestCase;
import org.elsys.themp.*;

public class UtilitiesTest extends TestCase {
	Utilities util;
	String test;
	int test2;

	@Override
	protected void setUp() throws Exception {
		super.setUp();
		util = new Utilities();
		test = new String();
	}

	public void testMilliSecondsToTimer() {
		test = util.milliSecondsToTimer(1000);
		assertEquals("0:01", test);
	}

	public void testGetPercentage() {

		test2 = util.getProgressPercentage(1000, 2000);
		assertEquals(50, test2);
	}

	public void testProgressToTimer() {

		test2 = util.progressToTimer(100, 5000);
		assertEquals(5000, test2);
	}
}
